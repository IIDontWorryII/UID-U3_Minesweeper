#include "cell.h"

/**
 * @brief Benutzerdefinierter Konstruktor für die Cell-Klasse.
 *
 * Initialisiert eine Zelle mit den angegebenen Werten.
 *
 * @param mines_around Anzahl der benachbarten Minen.
 * @param hidden Gibt an, ob die Zelle versteckt ist.
 * @param marked Gibt an, ob die Zelle markiert wurde.
 * @param mined Gibt an, ob die Zelle eine Mine enthält.
 * @param exploded Gibt an, ob die Zelle explodiert ist.
 */
Cell::Cell(int mines_around, bool hidden, bool marked, bool mined, bool exploded)
    : mines_around(mines_around), hidden(hidden), marked(marked), mined(mined), exploded(exploded) {}

/**
 * @brief Gibt die Anzahl der benachbarten Minen zurück.
 * @return Anzahl der Minen um die Zelle herum.
 */
int Cell::get_mines_around() { return mines_around; }

/**
 * @brief Prüft, ob die Zelle versteckt ist.
 * @return `true`, wenn die Zelle versteckt ist, sonst `false`.
 */
bool Cell::is_hidden() { return hidden; }

/**
 * @brief Prüft, ob die Zelle markiert wurde.
 * @return `true`, wenn die Zelle markiert ist, sonst `false`.
 */
bool Cell::is_marked() { return marked; }

/**
 * @brief Prüft, ob die Zelle eine Mine enthält.
 * @return `true`, wenn die Zelle vermint ist, sonst `false`.
 */
bool Cell::is_mined() { return mined; }

/**
 * @brief Prüft, ob die Zelle explodiert ist.
 * @return `true`, wenn die Zelle explodiert ist, sonst `false`.
 */
bool Cell::is_exploded() { return exploded; }

/**
 * @brief Setzt die Anzahl der benachbarten Minen.
 * @param mines_around Anzahl der Minen.
 */
void Cell::set_mines_around(int mines_around) { this->mines_around = mines_around; }

/**
 * @brief Setzt den Status der Zelle auf versteckt oder nicht.
 * @param hidden `true`, wenn die Zelle versteckt sein soll, sonst `false`.
 */
void Cell::set_hidden(bool hidden) { this->hidden = hidden; }

/**
 * @brief Setzt den Status der Zelle auf markiert oder nicht.
 * @param marked `true`, wenn die Zelle markiert sein soll, sonst `false`.
 */
void Cell::set_marked(bool marked) { this->marked = marked; }

/**
 * @brief Setzt, ob die Zelle eine Mine enthält.
 * @param mined `true`, wenn die Zelle eine Mine enthalten soll, sonst `false`.
 */
void Cell::set_mined(bool mined) { this->mined = mined; }

/**
 * @brief Setzt, ob die Zelle explodiert ist.
 * @param exploded `true`, wenn die Zelle explodiert ist, sonst `false`.
 */
void Cell::set_exploded(bool exploded) { this->exploded = exploded; }
