#include "gamestatistics.h"

/**
 * @brief Konstruktor für die GameStatistics-Klasse.
 *
 * Initialisiert die QMap zur Speicherung der Statistiken für verschiedene Spielfeldkonfigurationen.
 */
GameStatistics::GameStatistics() {
    statsMap = new QMap<QString, GameStats>(); ///< Dynamische Allokation der QMap für Statistiken.
}

/**
 * @brief Destruktor für die GameStatistics-Klasse.
 *
 * Gibt den Speicher für die QMap frei, um Speicherlecks zu vermeiden.
 */
GameStatistics::~GameStatistics() {
    delete statsMap; ///< Speicherfreigabe für die QMap.
}

/**
 * @brief Aktualisiert die Spielstatistiken für eine bestimmte Spielfeldkonfiguration.
 *
 * Fügt eine neue Konfiguration hinzu, falls sie noch nicht existiert, und aktualisiert
 * die gespielten Spiele, gewonnenen Spiele und die kürzeste Zeit bei einem Sieg.
 *
 * @param length Länge des Spielfelds (Anzahl der Zeilen).
 * @param width Breite des Spielfelds (Anzahl der Spalten).
 * @param mines Anzahl der Minen im Spielfeld.
 * @param won Gibt an, ob das Spiel gewonnen wurde (true) oder verloren wurde (false).
 * @param time Die Zeit (in Sekunden), die für das Spiel benötigt wurde.
 */
void GameStatistics::updateStats(int length, int width, int mines, bool won, int time) {
    QString key = generateKey(length, width, mines); ///< Generiere einen Schlüssel für die aktuelle Konfiguration.

    ///< Prüfe, ob die Konfiguration bereits existiert. Wenn nicht, füge sie hinzu.
    if (!statsMap->contains(key)) {
        (*statsMap)[key] = GameStats(length, width, mines);
    }

    ///< Hole einen Zeiger auf die Statistiken für die aktuelle Konfiguration.
    GameStats *stats = &(*statsMap)[key];

    stats->gamesPlayed++; ///< Erhöhe die Anzahl der gespielten Spiele.

    if (won) {
        stats->gamesWon++; ///< Erhöhe die Anzahl der gewonnenen Spiele.
        if (time < stats->shortestTime) {
            stats->shortestTime = time; ///< Aktualisiere die kürzeste benötigte Zeit.
        }
    } else {
        stats->gamesLost++; ///< Erhöhe die Anzahl der verlorenen Spiele.
    }
}

/**
 * @brief Speichert die aktuellen Spielstatistiken in einer JSON-Datei.
 *
 * Wandelt die gespeicherten Statistiken in ein JSON-Array um und schreibt es in die Datei.
 *
 * @param filePath Der Pfad zur Datei, in die die Statistiken gespeichert werden sollen.
 */
void GameStatistics::saveToFile(const QString &filePath) {
    QJsonArray statsArray; ///< JSON-Array zur Speicherung der Statistiken.

    ///< Iteriere durch die QMap und konvertiere jede Statistik in ein JSON-Objekt.
    for (auto it = statsMap->begin(); it != statsMap->end(); ++it) {
        statsArray.append(it.value().toJson());
    }

    ///< Erstelle ein JSON-Dokument aus dem Array.
    QJsonDocument doc(statsArray);
    QFile file(filePath);

    ///< Öffne die Datei im Schreibmodus und schreibe die JSON-Daten hinein.
    if (file.open(QIODevice::WriteOnly)) {
        file.write(doc.toJson());
        file.close();
    } else {
        qWarning() << "Failed to open file for saving: " << filePath; ///< Fehlermeldung bei fehlgeschlagenem Speichern.
    }
}

/**
 * @brief Lädt Spielstatistiken aus einer JSON-Datei.
 *
 * Liest die Datei ein, konvertiert das JSON-Array zurück in Statistiken und
 * speichert sie in der QMap.
 *
 * @param filePath Der Pfad zur Datei, aus der die Statistiken geladen werden sollen.
 */
void GameStatistics::loadFromFile(const QString &filePath) {
    QFile file(filePath);

    ///< Öffne die Datei im Lesemodus und lese den Inhalt.
    if (file.open(QIODevice::ReadOnly)) {
        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        file.close();

        QJsonArray statsArray = doc.array(); ///< JSON-Array aus der Datei.
        for (const QJsonValue &value : statsArray) {
            QJsonObject obj = value.toObject();
            GameStats stats;
            stats.fromJson(obj); ///< Lade die Statistik aus dem JSON-Objekt.

            ///< Generiere einen Schlüssel für die aktuelle Konfiguration und füge sie zur QMap hinzu.
            QString key = generateKey(stats.gridLength, stats.gridWidth, stats.minesNumber);
            (*statsMap)[key] = stats;
        }
    } else {
        qWarning() << "Failed to open file for loading: " << filePath; ///< Fehlermeldung bei fehlgeschlagenem Laden.
    }
}

/**
 * @brief Gibt die Statistiken für eine bestimmte Spielfeldkonfiguration zurück.
 *
 * Falls die Konfiguration nicht existiert, wird ein Standardobjekt für diese Konfiguration erstellt.
 *
 * @param length Länge des Spielfelds (Anzahl der Zeilen).
 * @param width Breite des Spielfelds (Anzahl der Spalten).
 * @param mines Anzahl der Minen im Spielfeld.
 * @return Ein GameStats-Objekt mit den Statistiken für die gegebene Konfiguration.
 */
GameStats GameStatistics::getStats(int length, int width, int mines) const {
    QString key = generateKey(length, width, mines); ///< Generiere einen Schlüssel für die Konfiguration.
    return statsMap->value(key, GameStats(length, width, mines)); ///< Gib die Statistik zurück.
}
