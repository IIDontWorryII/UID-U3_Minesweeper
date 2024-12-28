#include "qminerpushbutton.h"

/**
 * @brief Konstruktor der QMinerPushButton-Klasse mit Angabe des Eltern-Widgets.
 *
 * @param parent Das übergeordnete Widget, in dem die Schaltfläche angezeigt wird.
 */
QMinerPushButton::QMinerPushButton(QWidget *parent) : QPushButton(parent) {}

/**
 * @brief Standardkonstruktor der QMinerPushButton-Klasse.
 */
QMinerPushButton::QMinerPushButton() : QPushButton() {}

/**
 * @brief Konstruktor mit Angabe der Zeilen- und Spaltenposition.
 *
 * @param parent Das übergeordnete Widget, in dem die Schaltfläche angezeigt wird.
 * @param row Die Zeilenposition der Schaltfläche.
 * @param col Die Spaltenposition der Schaltfläche.
 */
QMinerPushButton::QMinerPushButton(QWidget *parent, int row, int col) : QPushButton(parent) {
    this->row = row;
    this->col = col;
}

/**
 * @brief Behandelt Mausklicks auf der Schaltfläche.
 *
 * Diese Methode wird bei einem Mausklick auf die Schaltfläche aufgerufen und löst
 * die entsprechenden Signale für den linken, mittleren oder rechten Mausklick aus.
 *
 * @param event Das Mausereignis, das den Mausklick beschreibt.
 */
void QMinerPushButton::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        emit leftClicked(); ///< Signal für linken Mausklick auslösen
    } else if (event->button() == Qt::MiddleButton) {
        emit middleClicked(); ///< Signal für mittleren Mausklick auslösen
    } else if (event->button() == Qt::RightButton) {
        emit rightClicked(); ///< Signal für rechten Mausklick auslösen
    }

    ///< Aufruf der Basisklassenimplementierung für das Standardverhalten
    QPushButton::mousePressEvent(event);
}
