#ifndef QMINERPUSHBUTTON_H
#define QMINERPUSHBUTTON_H

#include <QObject>
#include <QPushButton>
#include <QMouseEvent>

/**
 * @file qminerpushbutton.h
 * @class QMinerPushButton
 * @brief Eine benutzerdefinierte Schaltfläche, die unterschiedliche Mausereignisse behandelt.
 *
 * Diese Klasse erweitert QPushButton und ermöglicht es, auf verschiedene Mausaktionen (linker, mittlerer und rechter Klick)
 * zu reagieren. Sie wird in der Minesweeper-Anwendung verwendet, um die Interaktion mit den Zellen des Spielfeldes zu ermöglichen.
 *
 * Abhängigkeit: ist unabhängig und wird nur von dem MainWindow eingebunden.
 *
 * @author Daniel Schukin
 */
class QMinerPushButton : public QPushButton
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor, der einen Eltern-Widget angibt.
     *
     * @param parent Das übergeordnete Widget, in dem die Schaltfläche angezeigt wird. Standardmäßig ist es nullptr.
     *
     * @author Daniel Schukin
     */
    explicit QMinerPushButton(QWidget *parent = nullptr);

    /**
     * @brief Standardkonstruktor.
     *
     * @author Daniel Schukin
     */
    QMinerPushButton();

    /**
     * @brief Konstruktor mit Angabe der Zeilen- und Spaltenposition.
     *
     * @param parent Das übergeordnete Widget.
     * @param row Die Zeilenposition der Schaltfläche auf dem Spielfeld.
     * @param col Die Spaltenposition der Schaltfläche auf dem Spielfeld.
     *
     * @author Daniel Schukin
     */
    QMinerPushButton(QWidget *parent = nullptr, int row = 0, int col = 0);

    /**
     * @brief Gibt die Zeilenposition der Schaltfläche zurück.
     *
     * @return Die Zeilenposition der Schaltfläche.
     *
     * @author Daniel Schukin
     */
    int get_row() { return row; }

    /**
     * @brief Gibt die Spaltenposition der Schaltfläche zurück.
     *
     * @return Die Spaltenposition der Schaltfläche.
     *
     * @author Daniel Schukin
     */
    int get_col() { return col; }

private:
    int row; ///< Zeilenposition der Schaltfläche.
    int col; ///< Spaltenposition der Schaltfläche.

signals:
    /**
     * @brief Signal, das bei einem linken Mausklick ausgelöst wird.
     *
     * @author Daniel Schukin
     */
    void leftClicked();

    /**
     * @brief Signal, das bei einem mittleren Mausklick ausgelöst wird.
     *
     * @author Daniel Schukin
     */
    void middleClicked();

    /**
     * @brief Signal, das bei einem rechten Mausklick ausgelöst wird.
     *
     * @author Daniel Schukin
     */
    void rightClicked();

protected:
    /**
     * @brief Überschreibt das Mausereignis, um auf Mausklicks zu reagieren.
     *
     * Diese Methode wird bei einem Mausklick auf die Schaltfläche aufgerufen und
     * löst die entsprechenden Signale aus (leftClicked, middleClicked, rightClicked).
     *
     * @param event Das Mausereignis, das den Mausklick beschreibt.
     *
     * @author Daniel Schukin
     */
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // QMINERPUSHBUTTON_H
