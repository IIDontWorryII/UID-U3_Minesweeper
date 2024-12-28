/**
 * @file main.cpp
 * @brief Einstiegspunkt für die Anwendung.
 *
 * Initialisiert die Qt-Anwendung, erstellt das Spiel und das Hauptfenster
 * und startet die Ereignisschleife.
 *
 * @author Daniel Schukin
 */

#include "mainwindow.h"
#include "game.h"
#include <QApplication>
#include <QFile>

/**
 * @brief Hauptfunktion der Anwendung.
 *
 * Die Funktion initialisiert die Qt-Umgebung, lädt optional ein Stylesheet,
 * erstellt ein Spielobjekt und das Hauptfenster, zeigt das Fenster an und
 * startet die Ereignisschleife.
 *
 * @param argc Anzahl der Kommandozeilenargumente.
 * @param argv Array der Kommandozeilenargumente.
 * @return Rückgabewert der Anwendung (0 bei normalem Beenden).
 *
 * @author Daniel Schukin
 */
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    /**
     * @brief Optional: Lädt eine benutzerdefinierte QSS-Datei, um die Anwendung zu stylen.
     *
     * Hinweis: Der QSS-Dateiladevorgang ist derzeit auskommentiert. Entfernen Sie die Kommentare,
     * um ein benutzerdefiniertes Stylesheet zu verwenden.
     */
    /*
    QFile styleSheetFile(":/resources/Adaptic/Adaptic.qss");
    if (styleSheetFile.open(QFile::ReadOnly)) {
        QString styleSheet = QLatin1String(styleSheetFile.readAll());
        a.setStyleSheet(styleSheet);
        styleSheetFile.close();
    } else {
        qDebug() << "Konnte die Stylesheet-Datei nicht laden.";
    }
    */

    /**
     * @brief Erstellt das Spielobjekt.
     *
     * @details Das Spiel wird mit einer Spielfeldgröße von 10x10 und 10 Minen initialisiert.
     *
     * @author Daniel Schukin
     */
    Game game(10, 10, 10);

    /**
     * @brief Erstellt das Hauptfenster der Anwendung.
     *
     * @details Das Hauptfenster erhält das Spielobjekt als Parameter,
     * um die Interaktionen zwischen UI und Spiel zu ermöglichen.
     *
     * @author Daniel Schukin
     */
    MainWindow w(nullptr, &game);

    /**
     * @brief Zeigt das Hauptfenster an.
     */
    w.show();

    /**
     * @brief Startet die Qt-Ereignisschleife.
     *
     * @return Gibt den Rückgabewert der Ereignisschleife zurück (0 bei normalem Beenden).
     *
     * @author Daniel Schukin
     */
    return a.exec();
}
