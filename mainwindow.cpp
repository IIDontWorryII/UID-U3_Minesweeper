#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settingsdialog.h"
#include "statisticsdialog.h"
#include "helpdialog.h"
#include "qminerpushbutton.h"
#include "game.h"
#include <QMenu>
#include <QMessageBox>
#include <QDebug>
#include <QFile>
#include <QTimer>

/**
 * @brief Konstruktor der MainWindow-Klasse.
 * @param parent Zeiger auf das übergeordnete Widget.
 * @param game Zeiger auf das Game-Objekt zur Spiellogikverwaltung.
 */
MainWindow::MainWindow(QWidget *parent, Game *game)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Minesweeper");

    ///< Spielfeld-Einstellungen
    ui->gameGridWidget->setMinimumSize(BUTTONSIZE * 10, BUTTONSIZE * 10);
    ui->gameGrid->setSpacing(0);
    this->game = game;

    ///< LCD-Anzeigen für Minen und Flags initialisieren
    ui->minesLCDNumber->display(game->getMinesNumber());
    ui->flagsLCDNumber->setStyleSheet("QLCDNumber { color: blue; }");

    ///< Timer-Einstellungen
    ui->timeLCDNumber->setDigitCount(8);  ///< Anzeigeformat: hh:mm:ss
    ui->timeLCDNumber->display("00:00:00");
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTime);

    ///< Menü erstellen
    QMenu *menu = new QMenu(this);
    QAction *settingsAction = menu->addAction("Einstellungen");
    QAction *helpAction = menu->addAction("Hilfe");
    QAction *statsAction = menu->addAction("Statistik");

    ///< Menü mit Button verbinden
    ui->menuButton->setMenu(menu);

    ///< Menüaktionen verbinden
    connect(settingsAction, &QAction::triggered, this, &MainWindow::on_settingsAction_clicked);
    connect(helpAction, &QAction::triggered, this, &MainWindow::on_helpAction_clicked);
    connect(statsAction, &QAction::triggered, this, &MainWindow::on_statsAction_clicked);

    ///< Buttons für Spielsteuerung verbinden
    connect(ui->newGameButton, &QPushButton::clicked, this, &MainWindow::on_newGameBtn_clicked);
    connect(ui->pauseGameButton, &QPushButton::clicked, this, &MainWindow::on_pauseGameBtn_clicked);
    connect(ui->endGameButton, &QPushButton::clicked, this, &MainWindow::on_endGameBtn_clicked);

    resizeMainWindow();
}

/**
 * @brief Destruktor der MainWindow-Klasse.
 * Gibt die Benutzeroberfläche frei.
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief Slot: Startet ein neues Spiel.
 * Setzt das Spielfeld zurück und beginnt ein neues Spiel.
 */
void MainWindow::on_newGameBtn_clicked() {
    clear_grid();
    create_grid();
    updateGameGrid();
    restartTime();

    ///< Flags-Zähler zurücksetzen
    game->resetMarkedCells();
    ui->flagsLCDNumber->display(game->getMarkedCells());
    ui->flagsLCDNumber->setStyleSheet("QLCDNumber { color: blue; }");
    resizeMainWindow();
}

/**
 * @brief Slot: Pausiert oder setzt das Spiel fort.
 * Blendet das Spielfeld, neues Spiel, und beenden aus/an und stoppt/fortsetzt den Timer.
 */
void MainWindow::on_pauseGameBtn_clicked() {
    if (isRunning) {
        hideGameGrid();
        ui->newGameButton->setVisible(false);
        ui->endGameButton->setVisible(false);
        timer->stop();
        isRunning = false;
        ui->pauseGameButton->setText("Resume");
    } else {
        showGameGrid();
        ui->newGameButton->setVisible(true);
        ui->endGameButton->setVisible(true);
        timer->start(1000);
        isRunning = true;
        ui->pauseGameButton->setText("Pause");
    }
}

/**
 * @brief Slot: Beendet das Spiel.
 * Setzt das Spielfeld und den Timer zurück.
 */
void MainWindow::on_endGameBtn_clicked() {
    game->gameLost();
    updateGameGrid();
    resetTime();
}

/**
 * @brief Slot: Öffnet das Einstellungsdialogfenster.
 * Passt Spielfeldgröße und Spielparameter basierend auf den Benutzereinstellungen an.
 */
void MainWindow::on_settingsAction_clicked() {
    this->hide();
    if (isRunning)
        timer->stop();

    SettingsDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        game->setWon(false);
        game->gameEnd();
        clear_grid();

        ///< Spielfeld basierend auf Schwierigkeitsgrad erstellen
        if (dialog.get_difficulty().isEmpty()) { ///< wenn nichts gewählt wurde
            game->changeLength(dialog.get_boardLength());
            game->changeWidth(dialog.get_boardWidth());
            game->changeMinesNumber(dialog.get_minesNumber());
        } else if (dialog.get_difficulty().contains("Leicht")) { ///< wenn leichte Schwirigkeit gewählt wurde
            game->changeLength(10);
            game->changeWidth(10);
            game->changeMinesNumber(10);
        } else if (dialog.get_difficulty().contains("Mittel")) { ///< wenn mittlere Schwirigkeit gewählt wurde
            game->changeLength(14);
            game->changeWidth(18);
            game->changeMinesNumber(40);
        } else if (dialog.get_difficulty().contains("Schwer")) { ///< wenn schwere Schwirigkeit gewählt wurde
            game->changeLength(20);
            game->changeWidth(24);
            game->changeMinesNumber(99);
        }
        ///< das Spielfeld mit neuen Parametern starten
        game->resetMarkedCells();
        ui->minesLCDNumber->display(game->getMinesNumber());
        create_grid();
        updateGameGrid();
        resizeMainWindow();
        restartTime();
    } else if (!firstGame && game->is_inGame()) { ///< falls die Einstellungen nicht bestätigt wurden, zurückgehen
        timer->start(1000);
    }
    this->show(); ///< mainwindow wieder anzeigen
}

/**
 * @brief Slot: Öffnet den Statistikdialog.
 */
void MainWindow::on_statsAction_clicked() {
    this->hide();
    timer->stop();
    StatisticsDialog dialog(this);
    dialog.exec();
    if (firstGame && game->is_inGame()) {
        timer->start(1000);
    }
    this->show();
}

/**
 * @brief Slot: Öffnet den Hilfedialog.
 */
void MainWindow::on_helpAction_clicked() {
    this->hide();
    timer->stop();
    HelpDialog dialog(this);
    dialog.exec();
    if (!firstGame && game->is_inGame()) {
        timer->start(1000);
    }
    this->show();
}

/**
 * @brief Linksklick-Signal auf einem Spielfeldbutton.
 * @param row Zeilenindex der Zelle.
 * @param col Spaltenindex der Zelle.
 */
void MainWindow::LMC_on_gameCell(int row, int col) {
    qDebug() << "Linksklick auf Zelle";
    game->open_cell(row, col);
    updateGameGrid();
}

/**
 * @brief Mittelklick-Signal auf einem Spielfeldbutton.
 * Entfernt eine Markierung auf der Zelle.
 * @param row Zeilenindex der Zelle.
 * @param col Spaltenindex der Zelle.
 */
void MainWindow::MMC_on_gameCell(int row, int col) {
    qDebug() << "Mittelklick auf Zelle";
    game->unmark_cell(row, col);
    updateGameGrid();
    ui->flagsLCDNumber->display(game->getMarkedCells());
    if (game->getMarkedCells() <= game->getMinesNumber()) {
        ui->flagsLCDNumber->setStyleSheet("QLCDNumber { color: blue; }");
    }
}

/**
 * @brief Rechtsklick-Signal auf einem Spielfeldbutton.
 * Markiert eine Zelle als potenzielle Mine.
 * @param row Zeilenindex der Zelle.
 * @param col Spaltenindex der Zelle.
 */
void MainWindow::RMC_on_gameCell(int row, int col) {
    qDebug() << "Rechtsklick auf Zelle";
    game->mark_cell(row, col);
    updateGameGrid();
    ui->flagsLCDNumber->display(game->getMarkedCells());
    ///< wenn es mehr Felder markiert sind, als es Minen gibt, wird der Text vom Flagezähler Rot, sonst blau.
    if (game->getMarkedCells() > game->getMinesNumber()) {
        ui->flagsLCDNumber->setStyleSheet("QLCDNumber { color: red; }");
    } else {
        ui->flagsLCDNumber->setStyleSheet("QLCDNumber { color: blue; }");
    }
}

/**
 * @brief Fügt einen Button zum Spielfeld GridLayout hinzu.
 * Erstellt und verbindet einen Button für eine bestimmte Zelle.
 * @param row Zeilenindex der Zelle.
 * @param col Spaltenindex der Zelle.
 */
void MainWindow::addButtonToGrid(int row, int col) {
    QMinerPushButton *button = new QMinerPushButton(this, row, col); ///< Zeiger für den Button erstellen
    button->setFixedSize(QSize(BUTTONSIZE, BUTTONSIZE));
    button->setIcon(QIcon(iconpathByStatus.value(0)));  ///< Standardicon für geschlossene Zellen.
    button->setIconSize(QSize(BUTTONSIZE, BUTTONSIZE));

    ui->gameGrid->addWidget(button, row, col);

    ///< Verbindet die Klicksignale des Buttons mit den entsprechenden Slots.
    connect(button, &QMinerPushButton::leftClicked, this, [this, button]() {
        LMC_on_gameCell(button->get_row(), button->get_col());
    });
    connect(button, &QMinerPushButton::middleClicked, this, [this, button]() {
        MMC_on_gameCell(button->get_row(), button->get_col());
    });
    connect(button, &QMinerPushButton::rightClicked, this, [this, button]() {
        RMC_on_gameCell(button->get_row(), button->get_col());
    });
}

/**
 * @brief Erstellt das Spielfeld GridLayout.
 * Generiert die Zellen und platziert Minen sowie Zählwerte für benachbarte Minen.
 */
void MainWindow::create_grid() {
    game->createMatrix(game->getLength(), game->getWidth());
    for (int i = 0; i < game->getLength(); i++) {
        for (int j = 0; j < game->getWidth(); j++) {
            addButtonToGrid(i, j);
        }
    }
    ui->gameGrid->setSpacing(0);
    game->place_mines();
    game->count_mines_around();
}

/**
 * @brief Löscht das Spielfeld GridLayout.
 * Entfernt alle Buttons aus dem Spielfeld GridLayout.
 */
void MainWindow::clear_grid() {
    if (!firstGame) {
        for (int i = 0; i < game->getLength(); i++) {
            for (int j = 0; j < game->getWidth(); j++) {
                QLayoutItem *item = ui->gameGrid->itemAtPosition(i, j);
                QMinerPushButton *button = qobject_cast<QMinerPushButton *>(item->widget());
                ui->gameGrid->removeWidget(button);
                delete button;
            }
        }
    } else {
        firstGame = false;
    }
}

/**
 * @brief Aktualisiert das Spielfeld GridLayout.
 * Passt die Icons der Zellen basierend auf ihrem aktuellen Status an.
 */
void MainWindow::updateGameGrid() {
    qDebug() << "Aktualisiere Spielfeld";
    ///< für jeden Button der veränderten Zellen setzt das entsprechende Icon.
    for (const QPoint &coord : *game->getChangedCells()) {
        QLayoutItem *item = ui->gameGrid->itemAtPosition(coord.x(), coord.y());
        QMinerPushButton *button = qobject_cast<QMinerPushButton *>(item->widget());
        int status = game->getCellStatus(coord.x(), coord.y());

        if (status == 1) {
            button->setIcon(QIcon(iconpathByNumber.value(game->getCellMinesNumber(coord.x(), coord.y()))));
        } else {
            button->setIcon(QIcon(iconpathByStatus.value(status)));
        }
        ///< Icon anpassen und anzeigen
        button->setIconSize(QSize(BUTTONSIZE, BUTTONSIZE));
        button->update();
    }
    game->getChangedCells()->clear();

    if (!game->is_inGame()) {
        timer->stop();
    }
}

/**
 * @brief Aktualisiert die Zeit-Anzeige (LCD).
 */
void MainWindow::updateLCD() {
    int hours = game->getElapsedSeconds() / 3600;
    int minutes = (game->getElapsedSeconds() % 3600) / 60;
    int seconds = game->getElapsedSeconds() % 60;

    QString timeText = QString("%1:%2:%3") ///< QString Text, das angezeigt wird.
                           .arg(hours, 2, 10, QChar('0'))
                           .arg(minutes, 2, 10, QChar('0'))
                           .arg(seconds, 2, 10, QChar('0'));
    ui->timeLCDNumber->display(timeText);
}

/**
 * @brief Aktualisiert die verstrichene Spielzeit.
 * Wird jede Sekunde vom Timer aufgerufen.
 */
void MainWindow::updateTime() {
    game->setElapsedSeconds(game->getElapsedSeconds() + 1);
    updateLCD();
}

/**
 * @brief Setzt den Timer zurück.
 */
void MainWindow::resetTime() {
    timer->stop();
    game->setElapsedSeconds(0);
    updateLCD();
    isRunning = false;
}

/**
 * @brief Startet den Timer neu.
 */
void MainWindow::restartTime() {
    timer->start(1000);
    game->setElapsedSeconds(0);
    updateLCD();
    isRunning = true;
}

/**
 * @brief Passt die Fenstergröße basierend auf der Spielfeldgröße an.
 */
void MainWindow::resizeMainWindow() {
    if (BUTTONSIZE * game->getWidth() < ui->gameGridWidget->width()) {
        ui->gameGrid->setContentsMargins(120, 10, 120, 10);
        setFixedSize(BUTTONSIZE * game->getWidth() + 270, BUTTONSIZE * game->getLength() + 115);
    } else {
        ui->gameGrid->setContentsMargins(0, 10, 0, 10);
        setFixedSize(BUTTONSIZE * game->getWidth() + 20, BUTTONSIZE * game->getLength() + 115);
    }
}

/**
 * @brief Blendet das Spielfeld aus.
 */
void MainWindow::hideGameGrid() {
    for (int row = 0; row < game->getLength(); row++) {
        for (int col = 0; col < game->getWidth(); col++) {
            QLayoutItem *item = ui->gameGrid->itemAtPosition(row, col);
            QMinerPushButton *button = qobject_cast<QMinerPushButton *>(item->widget());
            button->hide();
        }
    }
}

/**
 * @brief Blendet das Spielfeld ein.
 */
void MainWindow::showGameGrid() {
    for (int row = 0; row < game->getLength(); row++) {
        for (int col = 0; col < game->getWidth(); col++) {
            QLayoutItem *item = ui->gameGrid->itemAtPosition(row, col);
            QMinerPushButton *button = qobject_cast<QMinerPushButton *>(item->widget());
            button->show();
        }
    }
}
