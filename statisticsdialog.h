#ifndef STATISTICSDIALOG_H
#define STATISTICSDIALOG_H

#include <QDialog>
#include "gamestatistics.h"

namespace Ui {
class StatisticsDialog;
}

/**
 * @file statisticsdialog.h
 * @class StatisticsDialog
 * @brief Dialog zur Anzeige der Spielstatistiken.
 *
 * Dieses Dialogfenster zeigt eine Tabelle mit den Statistiken des Spiels,
 * einschließlich der Anzahl gespielter Spiele, gewonnener Spiele, verlorener Spiele
 * und der kürzesten Spielzeit. Es ermöglicht es, die Statistikdaten aus einer Datei zu laden und anzuzeigen.
 *
 * @author Daniel Schukin
 */
class StatisticsDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor für das StatisticsDialog.
     *
     * Lädt die Spielstatistiken aus einer Datei und zeigt sie in einer Tabelle an.
     *
     * @param parent Das übergeordnete Widget (optional).
     *
     * @author Daniel Schukin
     */
    explicit StatisticsDialog(QWidget *parent = nullptr);

    /**
     * @brief Destruktor für StatisticsDialog-Objekt.
     *
     * @author Daniel Schukin
     */
    ~StatisticsDialog();

    /**
     * @brief Befüllt die Tabelle mit den Spielstatistiken.
     *
     * Diese Methode füllt die Tabelle mit den geladenen Statistiken.
     * Jedes Spiel wird in einer neuen Zeile angezeigt.
     *
     * Abhängigkeit: ist unabhängig und wird nur von dem MainWindow eingebunden.
     *
     * @author Daniel Schukin
     */
    void populateStatisticsTable();

    GameStatistics statisticManager; ///< Objekt zur Verwaltung der Spielstatistiken.

private slots:
    /**
     * @brief Wird aufgerufen, wenn der Zurück-Button im Dialog gedrückt wird.
     * Schließt das Dialogfenster.
     *
     * @author Daniel Schukin
     */
    void on_goBackButton_clicked();

private:
    Ui::StatisticsDialog *ui; ///< Die Benutzeroberfläche für das StatisticsDialog.
};

#endif // STATISTICSDIALOG_H
