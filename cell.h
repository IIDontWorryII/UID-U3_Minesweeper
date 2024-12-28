#ifndef CELL_H
#define CELL_H

/**
 * @file cell.h
 * @class Cell
 * @brief Definition der Cell-Klasse für das Minesweeper-Spiel.
 *
 * Die Klasse Cell repräsentiert eine einzelne Zelle im Minesweeper-Spiel.
 * Jede Zelle kann verschiedene Zustände haben, wie versteckt, markiert,
 * vermint oder explodiert. Zusätzlich speichert sie die Anzahl der benachbarten Minen.
 *
 * Abhängigkeiten: Die Cell-Klasse ist unabhängig und wird nur im Modul Game verwendet, um das Spielfeld
 * zu initialisieren und die Zustände der einzelnen Zellen auf dem Spielfeld zu verwalten.
 *
 * Technische Entscheidung:
 * Die Cell-Klasse verwendet einfache boolesche Flags, um die Effizienz und Lesbarkeit zu erreichen.
 * Eine komplexere Lösung wie Enums war für dieses Szenario nicht notwendig.
 *
 * @author Daniel Schukin
 */
class Cell
{
public:
    /**
     * @brief Standardkonstruktor für die Cell-Klasse.
     *
     * Initialisiert alle Zustände der Zelle auf Standardwerte:
     * - `mines_around` = 0
     * - `hidden` = true
     * - `marked` = false
     * - `mined` = false
     * - `exploded` = false
     * @author Daniel Schukin
     */
    Cell() : mines_around(0), hidden(true), marked(false), mined(false), exploded(false) {}

    /**
     * @brief Benutzerdefinierter Konstruktor für die Cell-Klasse.
     *
     * Ermöglicht das Setzen von initialen Werten für alle Attribute.
     *
     * @param mines_around Anzahl der benachbarten Minen.
     * @param hidden Gibt an, ob die Zelle versteckt ist.
     * @param marked Gibt an, ob die Zelle markiert wurde.
     * @param mined Gibt an, ob die Zelle eine Mine enthält.
     * @param exploded Gibt an, ob die Zelle explodiert ist.
     *
     * @author Daniel Schukin
     */
    Cell(int mines_around, bool hidden, bool marked, bool mined, bool exploded);

    /// @name Getter-Methoden
    /// Diese Methoden liefern die aktuellen Werte der Attribute zurück.
    /// @author Daniel Schukin
    /// @{
    int get_mines_around();
    bool is_hidden();
    bool is_marked();
    bool is_mined();
    bool is_exploded();
    /// @}

    /// @name Setter-Methoden
    /// Diese Methoden setzen die Werte der Attribute.
    /// @author Daniel Schukin
    /// @{
    void set_mines_around(int mines_around);
    void set_hidden(bool hidden);
    void set_marked(bool marked);
    void set_mined(bool mined);
    void set_exploded(bool exploded);
    /// @}

private: // Attribute
    int mines_around; ///< Anzahl der Minen um die Zelle herum.
    bool hidden;      ///< Zeigt an, ob die Zelle versteckt ist.
    bool marked;      ///< Zeigt an, ob die Zelle markiert wurde.
    bool mined;       ///< Zeigt an, ob die Zelle eine Mine enthält.
    bool exploded;    ///< Zeigt an, ob die Zelle explodiert ist.
};

#endif // CELL_H
