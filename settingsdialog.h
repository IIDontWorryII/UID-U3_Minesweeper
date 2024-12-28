#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QSlider>
#include <QLineEdit>
#include <QComboBox>

namespace Ui {
class SettingsDialog;
}

/**
 * @file settingsdialog.h
 * @class SettingsDialog
 * @brief Dialogfenster zur Auswahl der Spieleinstellungen wie Schwierigkeit, Spielfeldgröße und Anzahl der Minen.
 *
 * Dieses Dialogfenster ermöglicht es dem Benutzer, die Schwierigkeit, Spielfeldlängen,
 * Breiten und die Anzahl der Minen für das Spiel anzupassen.
 *
 * Abhängigkeit: ist unabhängig und wird nur von dem MainWindow eingebunden.
 *
 * @author Daniel Schukin
 */
class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor für das SettingsDialog.
     *
     * Initialisiert die Benutzeroberfläche und stellt Verbindungen zu den Steuerelementen her.
     *
     * @param parent Das übergeordnete Widget (optional).
     *
     * @author Daniel Schukin
     */
    explicit SettingsDialog(QWidget *parent = nullptr);

    /**
     * @brief Destruktor für SettingsDialog-Objekt.
     *
     * @author Daniel Schukin
     */
    ~SettingsDialog();

    /**
     * @brief Gibt die aktuell ausgewählte Schwierigkeit zurück.
     *
     * @return Die Schwierigkeit als QString.
     *
     * @author Daniel Schukin
     */
    QString get_difficulty();

    /**
     * @brief Gibt die Anzahl der Minen zurück.
     *
     * @return Die Anzahl der Minen.
     *
     * @author Daniel Schukin
     */
    int get_minesNumber();

    /**
     * @brief Gibt die Länge des Spielfelds zurück.
     *
     * @return Die Länge des Spielfelds.
     *
     * @author Daniel Schukin
     */
    int get_boardLength();

    /**
     * @brief Gibt die Breite des Spielfelds zurück.
     *
     * @return Die Breite des Spielfelds.
     *
     * @author Daniel Schukin
     */
    int get_boardWidth();

private slots:
    /**
     * @brief Wird aufgerufen, wenn der OK-Button im Dialog gedrückt wird.
     * Akzeptiert die Eingaben und schließt das Dialogfenster.
     *
     * @author Daniel Schukin
     */
    void on_okBtn_clicked();

    /**
     * @brief Wird aufgerufen, wenn der Abbrechen-Button im Dialog gedrückt wird.
     * Verwirft die Eingaben und schließt das Dialogfenster.
     *
     * @author Daniel Schukin
     */
    void on_cancelBtn_clicked();

private:
    Ui::SettingsDialog *ui; ///< Die Benutzeroberfläche für das SettingsDialog.

    QComboBox *difficultyCB; ///< ComboBox für die Schwierigkeit.
    QSlider *minesSlider; ///< Slider für die Anzahl der Minen.
    QSlider *lengthSlider; ///< Slider für die Spielfeldlänge.
    QSlider *widthSlider; ///< Slider für die Spielfeldbreite.

    QLineEdit *minesLineEdit; ///< LineEdit für die Anzahl der Minen.
    QLineEdit *lengthLineEdit; ///< LineEdit für die Spielfeldlänge.
    QLineEdit *widthLineEdit; ///< LineEdit für die Spielfeldbreite.

    /**
     * @brief Stellt die Verbindungen zwischen den Widgets her.
     * Synchronisiert die Slider und LineEdits, sodass Änderungen in einem Widget
     * auch das andere Widget aktualisieren.
     *
     * @author Daniel Schukin
     */
    void setupConnections();

    /**
     * @brief Aktualisiert den Slider, wenn der Text in einem LineEdit geändert wird.
     *
     * @param lineEdit Das bearbeitete LineEdit.
     * @param slider Der zu aktualisierende Slider.
     *
     * @author Daniel Schukin
     */
    void updateSliderFromLineEdit(QLineEdit *lineEdit, QSlider *slider);

    /**
     * @brief Aktualisiert das LineEdit, wenn der Wert eines Sliders geändert wird.
     *
     * @param slider Der bearbeitete Slider.
     * @param lineEdit Das zu aktualisierende LineEdit.
     *
     * @author Daniel Schukin
     */
    void updateLineEditFromSlider(QSlider *slider, QLineEdit *lineEdit);
};

#endif // SETTINGSDIALOG_H
