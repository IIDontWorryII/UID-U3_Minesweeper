#include "statisticsdialog.h"
#include "ui_statisticsdialog.h"
#include "gamestatistics.h"

/**
 * @brief Konstruktor für das StatisticsDialog.
 *
 * Lädt die Spielstatistiken aus einer Datei und zeigt sie in einer Tabelle an.
 *
 * @param parent Das übergeordnete Widget (optional).
 */
StatisticsDialog::StatisticsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StatisticsDialog)
{
    ui->setupUi(this);

    ///< Statistikdaten aus Datei laden
    statisticManager.loadFromFile("statistics.json");

    ///< Die Tabelle mit den geladenen Statistiken füllen
    populateStatisticsTable();
    adjustSize();

    ///< Verbindung für den Zurück-Button herstellen
    connect(ui->goBackButton, &QPushButton::clicked, this, &StatisticsDialog::on_goBackButton_clicked);
}

/**
 * @brief Zerstört das StatisticsDialog-Objekt.
 */
StatisticsDialog::~StatisticsDialog()
{
    delete ui;
}

/**
 * @brief Wird aufgerufen, wenn der Zurück-Button im Dialog gedrückt wird.
 * Schließt das Dialogfenster.
 */
void StatisticsDialog::on_goBackButton_clicked() {
    accept();
}

/**
 * @brief Befüllt die Tabelle mit den Spielstatistiken.
 *
 * Diese Methode füllt die Tabelle mit den geladenen Statistiken.
 * Jedes Spiel wird in einer neuen Zeile angezeigt.
 */
void StatisticsDialog::populateStatisticsTable() {
    ///< Tabelle leeren und die Spaltenbreiten anpassen
    ui->statisticsTable->clearContents();
    ui->statisticsTable->resizeColumnsToContents();

    ///< Die Anzahl der Zeilen auf die Anzahl der Spielstatistiken setzen
    ui->statisticsTable->setRowCount(statisticManager.getAllStats()->size());

    int row = 0;
    ///< Durch alle Statistiken iterieren und die Werte in die Tabelle einfügen
    for (auto it = statisticManager.getAllStats()->begin(); it != statisticManager.getAllStats()->end(); ++it) {
        const GameStats &stats = it.value();
        ///< Zeit in das Format "00:00:00" umwandeln
        QString time;
        int hours, minutes, seconds;
        if(stats.shortestTime == INT_MAX) {
            time = "-";
        }
        else {
            hours = stats.shortestTime / 3600;
            minutes = (stats.shortestTime % 3600) / 60;
            seconds = stats.shortestTime % 60;
            time = QString("%1:%2:%3").arg(hours, 2, 10, QChar('0')).arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0'));
        }

        ///< Werte für ein Spiel in die Tabelle einfügen
        ui->statisticsTable->setItem(row, 0, new QTableWidgetItem(QString::number(stats.gridLength)));
        ui->statisticsTable->setItem(row, 1, new QTableWidgetItem(QString::number(stats.gridWidth)));
        ui->statisticsTable->setItem(row, 2, new QTableWidgetItem(QString::number(stats.minesNumber)));
        ui->statisticsTable->setItem(row, 3, new QTableWidgetItem(QString::number(stats.gamesPlayed)));
        ui->statisticsTable->setItem(row, 4, new QTableWidgetItem(QString::number(stats.gamesWon)));
        ui->statisticsTable->setItem(row, 5, new QTableWidgetItem(QString::number(stats.gamesLost)));
        ui->statisticsTable->setItem(row, 6, new QTableWidgetItem(time));
        row++;
    }
}
