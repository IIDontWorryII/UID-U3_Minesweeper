#include "game.h"
#include "gamestatistics.h"
#include "cell.h"
#include <QRandomGenerator>
#include <algorithm>
#include <QDebug>

/**
 * @brief Standardkonstruktor der Game-Klasse.
 *
 * Initialisiert das Statistik-Objekt.
 */
Game::Game() {
    gameStatistics = new GameStatistics();
}

/**
 * @brief Parametrisierter Konstruktor der Game-Klasse.
 * @param gridLength Anzahl der Zeilen des Spielfelds.
 * @param gridWidth Anzahl der Spalten des Spielfelds.
 * @param minesNumber Anzahl der zu platzierenden Minen.
 *
 * Initialisiert das Spielfeld und lädt gespeicherte Statistiken.
 */
Game::Game(int gridLength, int gridWidth, int minesNumber)
    : gridLength(gridLength), gridWidth(gridWidth), minesNumber(minesNumber) {
    gameStatistics = new GameStatistics(); ///< neues Objekt der GameStatistics-Klasse erstellen
    gameStatistics->loadFromFile("statistics.json");
}

/**
 * @brief Destruktor der Game-Klasse.
 *
 * Gibt den Speicher für das Statistik-Objekt frei.
 */
Game::~Game() {
    delete gameStatistics;
}

/**
 * @brief Erstellt die Spielfeldmatrix mit den gegebenen Dimensionen.
 * @param length Anzahl der Zeilen.
 * @param width Anzahl der Spalten.
 */
void Game::createMatrix(int length, int width) {
    this->gameMatrix.clear(); ///< die Matrix löschen, falls schon gespielt wurde
    ///< die Matrix mit neuen Zellen einfüllen
    for (int i = 0; i < length; i++) {
        this->gameMatrix.append(QVector<Cell>());
        for (int j = 0; j < width; j++) {
            this->gameMatrix[i].append(Cell());
        }
    }
}

/**
 * @brief Ändert die Anzahl der Zeilen des Spielfelds.
 * @param length Neue Anzahl der Zeilen.
 */
void Game::changeLength(int length) {
    this->gridLength = length;
}

/**
 * @brief Ändert die Anzahl der Spalten des Spielfelds.
 * @param width Neue Anzahl der Spalten.
 */
void Game::changeWidth(int width) {
    this->gridWidth = width;
}

/**
 * @brief Ändert die Anzahl der Minen auf dem Spielfeld.
 * @param minesNumber Neue Anzahl der Minen.
 */
void Game::changeMinesNumber(int minesNumber) {
    this->minesNumber = minesNumber;
}

/**
 * @brief Setzt die Anzahl der markierten und geöffneten Zellen bei neuem Spiel zurück.
 */
void Game::resetMarkedCells() {
    this->openedCells = 0;
    this->markedCells = 0;
    this->inGame = true;
}

/**
 * @brief Platziert zufällig Minen auf dem Spielfeld.
 *
 * Stellt sicher, dass jede Mine an einer anderen Zelle platziert wird.
 */
void Game::place_mines() {
    int counter = 0; ///< counter für schon platzierte Minen
    int rand_row, rand_col; ///< Zeile, Spalte für die Minen

    ///< platziert die Minen in den zufälligen, nicht gleichen Zellen und inkrementiert den counter
    while (counter < getMinesNumber()) {
        rand_row = QRandomGenerator::global()->bounded(getLength());
        rand_col = QRandomGenerator::global()->bounded(getWidth());
        if (!gameMatrix[rand_row][rand_col].is_mined()) {
            gameMatrix[rand_row][rand_col].set_mined(true);
            counter++;
        }
    }
}

/**
 * @brief Zählt die Anzahl der Minen um jede Zelle und speichert die Werte.
 */
void Game::count_mines_around() {
    ///< geht durch die Matrix
    for (int i = 0; i < getLength(); i++) {
        for (int j = 0; j < getWidth(); j++) {
            int mines_counter = 0; ///< counter für die Minen rund um die Zelle
            ///< geht durch die Zellen herum
            for (int row = std::max(0, i - 1); row < std::min(getLength(), i + 2); row++) {
                for (int col = std::max(0, j - 1); col < std::min(getWidth(), j + 2); col++) {
                    if (gameMatrix[row][col].is_mined()) {
                        mines_counter++;
                    }
                }
            }
            gameMatrix[i][j].set_mines_around(mines_counter);
        }
    }
}

/**
 * @brief Öffnet eine Zelle auf dem Spielfeld.
 * @param row Zeilenindex der zu öffnenden Zelle.
 * @param col Spaltenindex der zu öffnenden Zelle.
 *
 * Falls die Zelle keine umliegenden Minen hat, werden benachbarte Zellen rekursiv geöffnet.
 * Bei einer Mine endet das Spiel.
 */
void Game::open_cell(int row, int col) {
    ///< falls die Zelle aufgedeckt oder markiert ist - öffnet die Zelle nicht
    if (!gameMatrix[row][col].is_hidden() || gameMatrix[row][col].is_marked()) {
        return;
    }

    ///< ändert den Status und merkt die Koordinaten der veränderten Zellen
    gameMatrix[row][col].set_hidden(false);
    openedCells++;
    this->changed_cells.append(QPoint(row, col));

    ///< falls die Zelle vermint ist
    if (gameMatrix[row][col].is_mined()) {
        gameMatrix[row][col].set_exploded(true);
        gameLost();
    }
    ///< falls die Zelle unvermint ist und an keine verminte Zelle grenzt, öffnet sie auch rekursiv
    else if (gameMatrix[row][col].get_mines_around() == 0) {
        for (int i = std::max(0, row - 1); i < std::min(getLength(), row + 2); i++) {
            for (int j = std::max(0, col - 1); j < std::min(getWidth(), col + 2); j++) {
                open_cell(i, j);
            }
        }
    }
    // prüft, ob alle Zelle schon aufgedeckt sind und beendet das Spiel
    if (openedCells == getLength() * getWidth()) {
        won = checkIfWon();
        gameEnd();
    }
}

/**
 * @brief Ermittelt den aktuellen Status einer Zelle als Kombination von Flags.
 *
 * Diese Methode berechnet den Status einer Zelle auf Basis ihrer Eigenschaften
 * (z.B. versteckt, markiert, vermint oder explodiert). Die Zustände werden
 * durch Bit-Flags dargestellt und kombiniert zurückgegeben.
 *
 * @param row Zeilenindex der Zelle im Spielfeld.
 * @param col Spaltenindex der Zelle im Spielfeld.
 * @return Ein Integer-Wert, der den Zellenstatus in Form von Bit-Flags darstellt:
 * | Flag     | Wert    | Beschreibung                          |
 * |----------|---------|---------------------------------------|
 * | 0x0001   | 1       | Die Zelle ist geöffnet (nicht versteckt). |
 * | 0x0002   | 2       | Die Zelle ist markiert.               |
 * | 0x0004   | 4       | Die Zelle enthält eine Mine.          |
 * | 0x0008   | 8       | Die Zelle ist explodiert.             |
 *
 * Die Flags werden addiert, wenn mehrere Bedingungen zutreffen.
 * Zum Beispiel: Eine markierte, versteckte Zelle ohne Mine hätte nur das `0x0002`-Flag.
 */
int Game::getCellStatus(int row, int col) {
    return !gameMatrix[row][col].is_hidden() * 0x0001
           + gameMatrix[row][col].is_marked() * 0x0002
           + gameMatrix[row][col].is_mined() * 0x0004
           + gameMatrix[row][col].is_exploded() * 0x0008;
}

/**
 * @brief Gibt die Anzahl der umliegenden Minen für eine Zelle zurück.
 * @param row Zeilenindex.
 * @param col Spaltenindex.
 * @return Anzahl der umliegenden Minen.
 */
int Game::getCellMinesNumber(int row, int col) {
    return gameMatrix[row][col].get_mines_around();
}

/**
 * @brief Markiert oder entmarkiert eine Zelle.
 * @param row Zeilenindex.
 * @param col Spaltenindex.
 */
void Game::mark_cell(int row, int col) {
    ///< markiert die Zelle, falls die demarkiert ist und umgekehrt
    if (gameMatrix[row][col].is_hidden()) {
        gameMatrix[row][col].set_marked(!gameMatrix[row][col].is_marked());
        ///< merkt die Koordinaten der veränderten Zelle und ändert die counters
        this->changed_cells.append(QPoint(row, col));
        markedCells += gameMatrix[row][col].is_marked() ? 1 : -1;
        openedCells += gameMatrix[row][col].is_marked() ? 1 : -1;
    }
    ///< prüft, ob alle Zelle schon aufgedeckt sind und beendet das Spiel
    if (openedCells == getLength() * getWidth()) {
        won = checkIfWon();
        gameEnd();
    }
}

/**
 * @brief Entfernt die Markierung einer Zelle.
 * @param row Zeilenindex.
 * @param col Spaltenindex.
 */
void Game::unmark_cell(int row, int col) {
    ///< demarkiert die Zelle, falls die markiert ist
    if(gameMatrix[row][col].is_marked()) {
        gameMatrix[row][col].set_marked(false);
        ///< merkt die Koordinaten der veränderten Zelle und ändert die counters
        this->changed_cells.append(QPoint(row, col));
        markedCells--;
        openedCells--;
    }
}

/**
 * @brief Beendet das Spiel und speichert die Statistiken.
 */
void Game::gameEnd() {
    gameStatistics->updateStats(getLength(), getWidth(), getMinesNumber(), won, getElapsedSeconds());
    gameStatistics->saveToFile("statistics.json");
    this->inGame = false;
}

/**
 * @brief Überprüft, ob der Spieler gewonnen hat.
 * @return True, wenn alle Minen korrekt markiert wurden; sonst false.
 */
bool Game::checkIfWon() {
    int markedRight = 0; ///< counter für die richtig markierte Zellen
    for (int row = 0; row < getLength(); row++) {
        for (int col = 0; col < getWidth(); col++) {
            if (gameMatrix[row][col].is_marked() && gameMatrix[row][col].is_mined()) {
                markedRight++;
            }
        }
    }
    return markedRight == getMinesNumber();
}

/**
 * @brief Öffnet alle Zellen auf dem Spielfeld.
 */
void Game::openAllCells() {
    ///< geht durch die Matrix und deckt die Zellen auf
    for (int row = 0; row < getLength(); row++) {
        for (int col = 0; col < getWidth(); col++) {
            if (gameMatrix[row][col].is_hidden()) {
                gameMatrix[row][col].set_hidden(false);
                this->changed_cells.append(QPoint(row, col));
            }
        }
    }
}

/**
 * @brief Beendet das Spiel als verloren, öffnet alle Zellen und speichert die Statistiken.
 */
void Game::gameLost() {
    won = false;
    openAllCells();
    gameEnd();
}

/**
 * @brief Debugging-Funktion zur Anzeige der Minenplatzierung.
 */
void Game::debug_checkGridGeneretion() {
    for (int i = 0; i < getLength(); i++) {
        QString tmp;
        for (int j = 0; j < getWidth(); j++) {
            tmp.append(gameMatrix[i][j].is_mined() ? "m " : QString::number(gameMatrix[i][j].get_mines_around()) + " ");
        }
        qDebug() << tmp;
    }
}

/**
 * @brief Debugging-Funktion zur Anzeige des Spielfeldstatus.
 */
void Game::debug_statuses() {
    for (int i = 0; i < getLength(); i++) {
        QString tmp;
        for (int j = 0; j < getWidth(); j++) {
            tmp.append(gameMatrix[i][j].is_hidden() ? "X " : "O ");
        }
        qDebug() << tmp;
    }
}
