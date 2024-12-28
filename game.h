#ifndef GAME_H
#define GAME_H

#include <cell.h>
#include <gamestatistics.h>
#include <QVector>
#include <QPoint>
#include <QIcon>
#include <QTimer>

/**
 * @file game.h
 * @class Game
 * @brief Die Game-Klasse verwaltet die Spiellogik für Minesweeper.
 *
 * Die Klasse Game steuert das Spiel auf dem logischen Niveau: verwaltet das Spielfeld,
 * die Spielmechanik wie Minenlegung, Zellenöffnung und -markierung sowie die Kontrolle
 * von Spielendebedingungen. Zudem verwaltet sie den aktuellen Status des Spiels.
 *
 * Abhängigkeiten: Die Game-Klasse wurde so entworfen, dass die Logik und Visualisierung
 * maximal von einander getrennt sind. Das Modul ist aber in "mainwindow" verwendet,
 * damit die beide Spielebene verbunden werden.
 *
 * @author Daniel Schukin
 */
class Game
{
public:
    /**
     * @brief Standardkonstruktor für die Game-Klasse.
     * Initialisiert das Spiel mit Standardwerten.
     *
     * @author Daniel Schukin
     */
    Game();

    /**
     * @brief Parametrisierter Konstruktor für die Game-Klasse.
     * @param gridLength Anzahl der Zeilen des Spielfelds.
     * @param gridWidth Anzahl der Spalten des Spielfelds.
     * @param minesNumber Anzahl der zu platzierenden Minen.
     *
     * Lädt zusätzlich gespeicherte Spielstatistiken.
     *
     * @author Daniel Schukin
     */
    Game(int gridLength = 10, int gridWidth = 10, int minesNumber = 10);

    /**
     * @brief Destruktor für die Game-Klasse.
     * Gibt dynamisch zugewiesenen Speicher für Statistiken frei.
     *
     * @author Daniel Schukin
     */
    ~Game();

    /// @name Spielfeld-Management
    /// @{
    /**
     * @brief Erstellt die Spielfeldmatrix aus Objekten der Cell-Klasse mit der gegebenen Größe.
     * @param length Anzahl der Zeilen.
     * @param width Anzahl der Spalten.
     *
     * @author Daniel Schukin
     */
    void createMatrix(int length, int width);

    /**
     * @brief Löscht die Spielfeldmatrix und setzt sie zurück.
     *
     * @author Daniel Schukin
     */
    void resetMatrix();

    /**
     * @brief Ändert die Anzahl der Zeilen des Spielfelds.
     * @param length Neue Anzahl der Zeilen.
     *
     * @author Daniel Schukin
     */
    void changeLength(int length);

    /**
     * @brief Ändert die Anzahl der Spalten des Spielfelds.
     * @param width Neue Anzahl der Spalten.
     *
     * @author Daniel Schukin
     */
    void changeWidth(int width);

    /**
     * @brief Ändert die Anzahl der Minen auf dem Spielfeld.
     * @param minesNumber Neue Anzahl der Minen.
     *
     * @author Daniel Schukin
     */
    void changeMinesNumber(int minesNumber);

    /**
     * @brief Setzt die Anzahl der markierten Zellen zurück.
     *
     * @author Daniel Schukin
     */
    void resetMarkedCells();
    /// @}

    /// @name Getter-Methoden
    /// @{
    /**
     * @brief Gibt die Anzahl der Zeilen zurück.
     * @return Anzahl der Zeilen im Spielfeld.
     *
     * @author Daniel Schukin
     */
    int getLength() { return gridLength; }
    /**
     * @brief Gibt die Anzahl der Spalten zurück.
     * @return Anzahl der Spalten im Spielfeld.
     *
     * @author Daniel Schukin
     */
    int getWidth() { return gridWidth; }
    /**
     * @brief Gibt die Anzahl der Minen zurück.
     * @return Anzahl der Minen im Spielfeld.
     *
     * @author Daniel Schukin
     */
    int getMinesNumber() { return minesNumber; }
    /**
     * @brief Gibt die vergangene Zeit seit Spielbeginn zurück.
     * @return Anzahl der Sekunden.
     *
     * @author Daniel Schukin
     */
    int getElapsedSeconds() { return elapsedSeconds; }

    /**
     * @brief Gibt die Anzahl der markierten Zellen zurück.
     * @return Anzahl der markierten Zellen.
     *
     * @author Daniel Schukin
     */
    int getMarkedCells() { return markedCells; }

    /**
     * @brief Gibt eine Liste der zuletzt geänderten Zellen zurück.
     * @return Zeiger auf die Liste der geänderten Zellen.
     *
     * @author Daniel Schukin
     */
    QVector<QPoint>* getChangedCells() { return &changed_cells; }

    /**
     * @brief Überprüft, ob das Spiel noch läuft.
     * @return True, wenn das Spiel aktiv ist; sonst false.
     *
     * @author Daniel Schukin
     */
    bool is_inGame() { return inGame; }
    /// @}

    /// @name Setter-Methoden
    /// @{
    /**
     * @brief Setzt die vergangene Spielzeit.
     * @param value Neue Zeit in Sekunden.
     *
     * @author Daniel Schukin
     */
    void setElapsedSeconds(int value) { this->elapsedSeconds = value; };

    /**
     * @brief Setzt den Siegstatus des Spiels.
     * @param value True, wenn das Spiel gewonnen wurde; sonst false.
     *
     * @author Daniel Schukin
     */
    void setWon(bool value) { this->won = value; }
    /// @}

    /// @name Zellstatus und Minenzählung
    /// @{
    /**
     * @brief Gibt den Status einer bestimmten Zelle zurück.
     * @param row Zeilenindex der Zelle.
     * @param col Spaltenindex der Zelle.
     * @return Status der Zelle (z.B. versteckt, markiert).
     *
     * @author Daniel Schukin
     */
    int getCellStatus(int row, int col);

    /**
     * @brief Gibt die Anzahl der Minen um eine bestimmte Zelle zurück.
     * @param row Zeilenindex der Zelle.
     * @param col Spaltenindex der Zelle.
     * @return Anzahl der Minen um die Zelle.
     *
     * @author Daniel Schukin
     */
    int getCellMinesNumber(int row, int col);
    /// @}

    /// @name Spiellogik
    /// @{
    /**
     * @brief Platziert zufällig die Minen auf dem Spielfeld.
     *
     * @author Daniel Schukin
     */
    void place_mines();

    /**
     * @brief Zählt die Anzahl der Minen um jede Zelle.
     *
     * @author Daniel Schukin
     */
    void count_mines_around();

    /**
     * @brief Öffnet eine bestimmte Zelle.
     * @param row Zeilenindex der zu öffnenden Zelle.
     * @param col Spaltenindex der zu öffnenden Zelle.
     *
     * @author Daniel Schukin
     */
    void open_cell(int row, int col);

    /**
     * @brief Markiert/demarkiert eine Zelle als potenzielle Mine.
     * @param row Zeilenindex der zu markierenden Zelle.
     * @param col Spaltenindex der zu markierenden Zelle.
     *
     * @author Daniel Schukin
     */
    void mark_cell(int row, int col);

    /**
     * @brief Entfernt die Markierung von einer Zelle.
     * @param row Zeilenindex der Zelle.
     * @param col Spaltenindex der Zelle.
     *
     * @author Daniel Schukin
     */
    void unmark_cell(int row, int col);

    /**
     * @brief Beendet das Spiel und aktualisiert die Statistiken.
     *
     * @author Daniel Schukin
     */
    void gameEnd();

    /**
     * @brief Überprüft, ob das Spiel gewonnen wurde.
     * @return True, wenn alle Minen korrekt markiert sind; sonst false.
     *
     * @author Daniel Schukin
     */
    bool checkIfWon();

    /**
     * @brief Öffnet alle Zellen des Spielfelds.
     *
     * @author Daniel Schukin
     */
    void openAllCells();

    /**
     * @brief Aktualisiert die Spielstatistiken.
     *
     * @author Daniel Schukin
     */
    void updateStatistics();
    /// @}

    /**
     * @brief Beendet das Spiel als verloren und zeigt das Spielfeld.
     *
     * @author Daniel Schukin
     */
    void gameLost();

    /// @name Debugging-Funktionen
    /// @{
    /**
     * @brief Debugging-Funktion zur Überprüfung der Minenplatzierung.
     *
     * @author Daniel Schukin
     */
    void debug_checkGridGeneretion();

    /**
     * @brief Zeigt den Status aller Zellen für Debugging-Zwecke.
     *
     * @author Daniel Schukin
     */
    void debug_statuses();
    /// @}

private:
    int gridLength; ///< Anzahl der Zeilen im Spielfeld.
    int gridWidth; ///< Anzahl der Spalten im Spielfeld.
    int minesNumber; ///< Anzahl der Minen im Spielfeld.
    bool won; ///< True, wenn das Spiel gewonnen wurde.
    bool inGame = false; ///< True, wenn das Spiel noch läuft.
    int elapsedSeconds = 0; ///< Spielzeit in Sekunden.
    int markedCells; ///< Anzahl der markierten Zellen.
    int openedCells; ///< Anzahl der geöffneten Zellen.

    QVector<QPoint> changed_cells; ///< Liste der kürzlich veränderten Zellen.
    QVector<QVector<Cell>> gameMatrix; ///< Matrix, die alle Zellen des Spielfelds enthält.
    GameStatistics *gameStatistics; ///< Zeiger auf das Statistik-Objekt.
};

#endif // GAME_H
