#ifndef HELPDIALOG_H
#define HELPDIALOG_H

#include <QDialog>

/**
 * @namespace Ui
 * @brief Der Namespace für die automatisch generierte Benutzeroberfläche.
 *
 * @author Daniel Schukin
*/
namespace Ui {
class HelpDialog; ///< Vorwärtsdeklaration der automatisch generierten Klasse für die UI.
}

/**
 * @file helpdialog.h
 * @class HelpDialog
 * @brief Eine Dialogklasse zur Anzeige der Hilfeseite.
 *
 * Diese Klasse verwaltet einen einfachen Dialog, der Hilfeinformationen anzeigt.
 * Ein Button ermöglicht das Schließen des Dialogs und die Rückkehr zur vorherigen Ansicht.
 *
 * Abhängigkeit: ist unabhängig und wird nur von dem MainWindow eingebunden.
 *
 * @author Daniel Schukin
 */
class HelpDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor für die HelpDialog-Klasse.
     * @param parent Ein optionaler Zeiger auf das übergeordnete QWidget.
     *
     * @author Daniel Schukin
     */
    explicit HelpDialog(QWidget *parent = nullptr);

    /**
     * @brief Destruktor für die HelpDialog-Klasse.
     *
     * @author Daniel Schukin
     */
    ~HelpDialog();

private slots:
    /**
     * @brief Slot-Methode für den "Zurück"-Button.
     *
     * Diese Methode wird aufgerufen, wenn der Benutzer den "Zurück"-Button klickt.
     * Der Dialog wird geschlossen und der Benutzer kehrt zur vorherigen Ansicht zurück.
     *
     * @author Daniel Schukin
     */
    void on_goBackButton_clicked();

private:
    Ui::HelpDialog *ui; ///< Zeiger auf die automatisch generierte Benutzeroberfläche.
};

#endif // HELPDIALOG_H
