#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "game.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

/**
 * @file mainwindow.h
 * @class MainWindow
 * @brief Hauptfenster der Minesweeper-Anwendung.
 *
 * Die MainWindow-Klasse verwaltet grafische Oberfläche und die visuelle Logik des Spiels,
 * einschließlich der Spielfläche, der Timersteuerung, der Benutzerinteraktionen und der Menüaktionen.
 *
 * @author Daniel Schukin
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor für das Hauptfenster.
     * @param parent Pointer auf das übergeordnete Widget.
     * @param game Pointer auf das Game-Objekt.
     *
     * @author Daniel Schukin
     */
    MainWindow(QWidget *parent, Game *game);

    /**
     * @brief Destruktor für MainWindow.
     *
     * @author Daniel Schukin
     */
    ~MainWindow();

    /**
     * @brief Erstellt ein neues Spielfeld (Grid).
     *
     * @author Daniel Schukin
     */
    void create_grid();

    /**
     * @brief Löscht das aktuelle Spielfeld.
     *
     * @author Daniel Schukin
     */
    void clear_grid();

    /**
     * @brief Fügt einen Button zur Spielfläche hinzu.
     * @param row Zeilenindex des Buttons.
     * @param col Spaltenindex des Buttons.
     *
     * @author Daniel Schukin
     */
    void addButtonToGrid(int row, int col);

    /**
     * @brief Aktualisiert den Zustand des Spielfelds.
     *
     * @author Daniel Schukin
     */
    void updateGameGrid();

    /**
     * @brief Versteckt das Spielfeld.
     *
     * @author Daniel Schukin
     */
    void hideGameGrid();

    /**
     * @brief Zeigt das Spielfeld.
     *
     * @author Daniel Schukin
     */
    void showGameGrid();

    /**
     * @brief Passt die Größe des Hauptfensters basierend auf dem Spielfeld an.
     *
     * @author Daniel Schukin
     */
    void resizeMainWindow();

private slots:
    /// @name Slots für Spielaktionen
    /// @author Daniel Schukin
    /// @{
    void on_newGameBtn_clicked(); ///< Startet ein neues Spiel.
    void on_pauseGameBtn_clicked(); ///< Pausiert oder setzt das Spiel fort.
    void on_endGameBtn_clicked(); ///< Beendet das aktuelle Spiel.
    /// @}

    /// @name Slots für Menüaktionen
    /// @author Daniel Schukin
    /// @{
    void on_settingsAction_clicked(); ///< Öffnet die Einstellungen.
    void on_statsAction_clicked(); ///< Zeigt die Spielstatistiken.
    void on_helpAction_clicked(); ///< Zeigt die Hilfsinformationen.
    /// @}

    /// @name Slots für Interaktionen mit Spielfeldzellen
    /// @author Daniel Schukin
    /// @{
    void LMC_on_gameCell(int row, int col); ///< Linksklick auf eine Spielfeldzelle.
    void MMC_on_gameCell(int row, int col); ///< Mittelklick auf eine Spielfeldzelle.
    void RMC_on_gameCell(int row, int col); ///< Rechtsklick auf eine Spielfeldzelle.
    /// @}

    /// @name Slots für Timer-Steuerung
    /// @author Daniel Schukin
    /// @{
    void updateTime(); ///< Aktualisiert die Zeit auf der Anzeige.
    void resetTime(); ///< Setzt die Spielzeit zurück.
    void restartTime(); ///< Startet die Spielzeit neu.
    /// @}

private:
    Ui::MainWindow *ui; ///< Pointer auf die UI-Komponenten.
    Game *game; ///< Pointer auf das Game-Objekt.

    /// @brief Zuordnung von Spielstatus zu Icon-Pfaden.
    QMap<int, QString> iconpathByStatus{
        {0, ":/resources/icons/covered_cell.png"},
        {4, ":/resources/icons/covered_cell.png"},
        {2, ":/resources/icons/flag.png"},
        {6, ":/resources/icons/flag.png"},
        {3, ":/resources/icons/wrong_mark.png"},
        {5, ":/resources/icons/mine.png"},
        {7, ":/resources/icons/right_mark.png"},
        {13, ":/resources/icons/exploded_mine.png"}
    };

    /// @brief Zuordnung von Zahlen zu Icon-Pfaden.
    QMap<int, QString> iconpathByNumber{
        {0, ":/resources/icons/opened_cell.png"},
        {1, ":/resources/icons/number_1.png"},
        {2, ":/resources/icons/number_2.png"},
        {3, ":/resources/icons/number_3.png"},
        {4, ":/resources/icons/number_4.png"},
        {5, ":/resources/icons/number_5.png"},
        {6, ":/resources/icons/number_6.png"},
        {7, ":/resources/icons/number_7.png"},
        {8, ":/resources/icons/number_8.png"}
    };

    QTimer *timer; ///< Timer zur Zeitsteuerung.
    bool isRunning = false; ///< Gibt an, ob der Timer läuft.
    bool firstGame = true; ///< Gibt an, ob es das erste Spiel ist.
    int BUTTONSIZE = 25; ///< Größe der Spielfeldzellen (in Pixeln).

    /**
     * @brief Aktualisiert die Anzeige der Spielzeit.
     *
     * @author Daniel Schukin
     */
    void updateLCD();
};

#endif // MAINWINDOW_H
