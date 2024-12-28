#ifndef GAMESTATISTICS_H
#define GAMESTATISTICS_H

#include <QString>
#include <QMap>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>

/**
 * @file gamestatistics.h
 * @brief Struktur zur Speicherung der Spielstatistiken für ein bestimmtes Spielfeld.
 *
 * Wird benutzt als value vom QMap statsMap.
 *
 * @author Daniel Schukin
 */
struct GameStats
{
    int gridLength;      ///< Länge des Spielfelds (Anzahl der Zeilen).
    int gridWidth;       ///< Breite des Spielfelds (Anzahl der Spalten).
    int minesNumber;     ///< Anzahl der Minen im Spielfeld.
    int gamesPlayed = 0; ///< Anzahl der gespielten Spiele.
    int gamesWon = 0;    ///< Anzahl der gewonnenen Spiele.
    int gamesLost = 0;   ///< Anzahl der verlorenen Spiele.
    int shortestTime = INT_MAX; ///< Kürzeste benötigte Zeit für ein gewonnenes Spiel.

    /**
     * @brief Konstruktor für GameStats.
     * @param gridLength Länge des Spielfelds.
     * @param gridWidth Breite des Spielfelds.
     * @param minesNumber Anzahl der Minen.
     *
     * @author Daniel Schukin
     */
    GameStats(int gridLength = 0, int gridWidth = 0, int minesNumber = 0)
        : gridLength(gridLength), gridWidth(gridWidth), minesNumber(minesNumber) {}

    /**
     * @brief Konvertiert die Statistiken in ein QJsonObject für die JSON-Speicherung.
     * @return QJsonObject, der die Statistiken enthält.
     *
     * @author Daniel Schukin
     */
    QJsonObject toJson() const {
        QJsonObject obj;
        obj["gridLength"] = gridLength;
        obj["gridWidth"] = gridWidth;
        obj["minesNumber"] = minesNumber;
        obj["gamesPlayed"] = gamesPlayed;
        obj["gamesWon"] = gamesWon;
        obj["gamesLost"] = gamesLost;
        obj["shortestTime"] = shortestTime == INT_MAX ? -1 : shortestTime; // -1, wenn kein Spiel gewonnen wurde.
        return obj;
    }

    /**
     * @brief Lädt die Statistiken aus einem QJsonObject.
     * @param obj QJsonObject, das die Statistiken enthält.
     *
     * @author Daniel Schukin
     */
    void fromJson(const QJsonObject &obj) {
        gridLength = obj["gridLength"].toInt();
        gridWidth = obj["gridWidth"].toInt();
        minesNumber = obj["minesNumber"].toInt();
        gamesPlayed = obj["gamesPlayed"].toInt();
        gamesWon = obj["gamesWon"].toInt();
        gamesLost = obj["gamesLost"].toInt();
        shortestTime = obj["shortestTime"].toInt();
        if (shortestTime == -1) {
            shortestTime = INT_MAX; ///< Falls kein Spiel gewonnen wurde, zurücksetzen.
        }
    }
};

/**
 * @class GameStatistics
 * @brief Klasse zur Verwaltung der Spielstatistiken.
 *
 * Diese Klasse speichert, aktualisiert, speichert und lädt Spielstatistiken aus einer Datei.
 *
 * Abhängigkeit: die Klasse ist unabhängig und wird nut von dem Game Modul eingebunden,
 * um die Statistiken nach dem Ende jedes Spiels zu speichern.
 *
 * @author Daniel Schukin
 */
class GameStatistics
{
public:
    /**
     * @brief Konstruktor für GameStatistics.
     *
     * @author Daniel Schukin
     */
    GameStatistics();

    /**
     * @brief Destruktor für GameStatistics.
     *
     * @author Daniel Schukin
     */
    ~GameStatistics();

    /**
     * @brief Aktualisiert die Statistiken für ein bestimmtes Spiel.
     *
     * @param length Spielfeldlänge.
     * @param width Spielfeldbreite.
     * @param mines Anzahl der Minen.
     * @param won Gibt an, ob das Spiel gewonnen wurde.
     * @param time Die benötigte Zeit für das Spiel.
     *
     * @author Daniel Schukin
     */
    void updateStats(int length, int width, int mines, bool won, int time);

    /**
     * @brief Speichert die Statistiken in einer JSON-Datei.
     * @param filePath Pfad zur Zieldatei.
     *
     * @author Daniel Schukin
     */
    void saveToFile(const QString &filePath);

    /**
     * @brief Lädt die Statistiken aus einer JSON-Datei.
     * @param filePath Pfad zur Quelldatei.
     *
     * @author Daniel Schukin
     */
    void loadFromFile(const QString &filePath);

    /**
     * @brief Ruft die Statistiken für ein bestimmtes Spielfeld ab.
     * @param length Spielfeldlänge.
     * @param width Spielfeldbreite.
     * @param mines Anzahl der Minen.
     * @return GameStats-Objekt, das die Statistiken enthält.
     *
     * @author Daniel Schukin
     */
    GameStats getStats(int length, int width, int mines) const;

    /**
     * @brief Gibt alle Statistiken zurück.
     * @return Zeiger auf eine QMap mit allen Statistiken.
     *
     * @author Daniel Schukin
     */
    QMap<QString, GameStats> *getAllStats() {
        return statsMap;
    }

private:
    QMap<QString, GameStats> *statsMap; ///< QMap zur Speicherung der Statistiken. Key: "Länge-Breite-Minen".

    /**
     * @brief Generiert einen eindeutigen Schlüssel für die Statistiken.
     * @param length Spielfeldlänge.
     * @param width Spielfeldbreite.
     * @param mines Anzahl der Minen.
     * @return QString, der als Schlüssel verwendet wird.
     *
     * @author Daniel Schukin
     */
    QString generateKey(int length, int width, int mines) const {
        return QString("%1x%2 %3mines").arg(length).arg(width).arg(mines);
    }
};

#endif // GAMESTATISTICS_H
