#include "settingsdialog.h"
#include "ui_settingsdialog.h"

/**
 * @brief Konstruktor für das SettingsDialog.
 *
 * Initialisiert die Benutzeroberfläche und stellt Verbindungen zu den Steuerelementen her.
 *
 * @param parent Das übergeordnete Widget (optional).
 */
SettingsDialog::SettingsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Settings");

    ///< Widgets initialisieren
    difficultyCB = ui->difficultyCB;
    minesSlider = ui->minesSlider;
    lengthSlider = ui->lengthSlider;
    widthSlider = ui->widthSlider;

    minesLineEdit = ui->minesLineEdit;
    lengthLineEdit = ui->lengthLineEdit;
    widthLineEdit = ui->widthLineEdit;

    ///< Verbindungen zu den Buttons
    connect(ui->cancelButton, &QPushButton::clicked, this, &SettingsDialog::on_cancelBtn_clicked);
    connect(ui->okButton, &QPushButton::clicked, this, &SettingsDialog::on_okBtn_clicked);

    setupConnections();
    adjustSize();
}

/**
 * @brief Zerstört das SettingsDialog-Objekt.
 */
SettingsDialog::~SettingsDialog()
{
    delete ui;
}

/**
 * @brief Wird aufgerufen, wenn der OK-Button im Dialog gedrückt wird.
 * Akzeptiert die Eingaben und schließt das Dialogfenster.
 */
void SettingsDialog::on_okBtn_clicked(){
    accept();
}

/**
 * @brief Wird aufgerufen, wenn der Abbrechen-Button im Dialog gedrückt wird.
 * Verwirft die Eingaben und schließt das Dialogfenster.
 */
void SettingsDialog::on_cancelBtn_clicked(){
    reject();
}

/**
 * @brief Stellt die Verbindungen zwischen den Widgets her.
 * Synchronisiert die Slider und LineEdits, sodass Änderungen in einem Widget
 * auch das andere Widget aktualisieren.
 */
void SettingsDialog::setupConnections()
{
    ///< Synchronisieren von minesSlider und minesLineEdit
    connect(minesSlider, &QSlider::valueChanged, this, [=]() {
        updateLineEditFromSlider(minesSlider, minesLineEdit);
    });
    connect(minesLineEdit, &QLineEdit::textChanged, this, [=]() {
        updateSliderFromLineEdit(minesLineEdit, minesSlider);
    });

    ///< Synchronisieren von lengthSlider und lengthLineEdit
    connect(lengthSlider, &QSlider::valueChanged, this, [=]() {
        updateLineEditFromSlider(lengthSlider, lengthLineEdit);
    });
    connect(lengthLineEdit, &QLineEdit::textChanged, this, [=]() {
        updateSliderFromLineEdit(lengthLineEdit, lengthSlider);
    });

    ///< Synchronisieren von widthSlider und widthLineEdit
    connect(widthSlider, &QSlider::valueChanged, this, [=]() {
        updateLineEditFromSlider(widthSlider, widthLineEdit);
    });
    connect(widthLineEdit, &QLineEdit::textChanged, this, [=]() {
        updateSliderFromLineEdit(widthLineEdit, widthSlider);
    });
}

/**
 * @brief Aktualisiert den Slider, wenn der Text in einem LineEdit geändert wird.
 *
 * @param lineEdit Das bearbeitete LineEdit.
 * @param slider Der zu aktualisierende Slider.
 */
void SettingsDialog::updateSliderFromLineEdit(QLineEdit *lineEdit, QSlider *slider)
{
    bool ok;
    int value = lineEdit->text().toInt(&ok);
    if (ok && value >= slider->minimum() && value <= slider->maximum()) {
        slider->setValue(value); // Aktualisiert den Slider, wenn der Wert gültig ist
    }
}

/**
 * @brief Aktualisiert das LineEdit, wenn der Wert eines Sliders geändert wird.
 *
 * @param slider Der bearbeitete Slider.
 * @param lineEdit Das zu aktualisierende LineEdit.
 */
void SettingsDialog::updateLineEditFromSlider(QSlider *slider, QLineEdit *lineEdit)
{
    lineEdit->setText(QString::number(slider->value())); // Aktualisiert das LineEdit mit dem Slider-Wert
}

/**
 * @brief Gibt die aktuell ausgewählte Schwierigkeit zurück.
 *
 * @return Die Schwierigkeit als QString.
 */
QString SettingsDialog::get_difficulty() { return difficultyCB->currentText(); }

/**
 * @brief Gibt die Anzahl der Minen zurück.
 *
 * @return Die Anzahl der Minen.
 */
int SettingsDialog::get_minesNumber() { return minesSlider->value(); }

/**
 * @brief Gibt die Länge des Spielfelds zurück.
 *
 * @return Die Länge des Spielfelds.
 */
int SettingsDialog::get_boardLength() { return lengthSlider->value(); }

/**
 * @brief Gibt die Breite des Spielfelds zurück.
 *
 * @return Die Breite des Spielfelds.
 */
int SettingsDialog::get_boardWidth() { return widthSlider->value(); }
