#include "helpdialog.h"
#include "ui_helpdialog.h"

/**
 * @brief Konstruktor für die HelpDialog-Klasse.
 *
 * Initialisiert die Benutzeroberfläche und stellt die Verbindung zum "Zurück"-Button her.
 *
 * @param parent Ein optionaler Zeiger auf das übergeordnete QWidget.
 */
HelpDialog::HelpDialog(QWidget *parent)
    : QDialog(parent) ///< Ruft den QDialog-Konstruktor mit dem übergeordneten Widget auf.
    , ui(new Ui::HelpDialog) ///< Erstellt die Instanz der automatisch generierten UI-Klasse.
{
    ui->setupUi(this); ///< Setzt die Benutzeroberfläche auf.
    adjustSize(); ///< Passt die Größe des Dialogs an die UI-Elemente an.

    ///< Verbindet das "goBackButton"-Signal mit dem Slot zum Schließen des Dialogs.
    connect(ui->goBackButton, &QPushButton::clicked, this, &HelpDialog::on_goBackButton_clicked);
}

/**
 * @brief Destruktor für die HelpDialog-Klasse.
 *
 * Löscht die automatisch generierte UI, um Speicher freizugeben.
 */
HelpDialog::~HelpDialog()
{
    delete ui; ///< Löscht die Benutzeroberfläche.
}

/**
 * @brief Slot-Methode für den "Zurück"-Button.
 *
 * Schließt den Dialog und gibt ein akzeptiertes Ergebnis zurück.
 */
void HelpDialog::on_goBackButton_clicked() {
    accept(); ///< Beendet den Dialog mit dem Status "accept".
}
