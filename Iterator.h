#ifndef ITERATOR_H
#define ITERATOR_H
#include <iostream>

using namespace std;

#include "Node.h"

/**
 * @file Iterator.h
 * @brief Deklaracja iteratora listy dwukierunkowej.
 */


 /**
  * @class Iterator
  * @brief Iterator umożliwiający przechodzenie po węzłach listy.
  */

class Iterator {
private:
    Node* current;

public:

    /**
     * @brief Tworzy iterator wskazujący na podany węzeł.
     * @param start Początkowy węzeł, domyślnie nullptr.
     */
    Iterator(Node* start = nullptr);

    /**
     * @brief Sprawdza, czy iterator wskazuje na element.
     * @return true, jeśli element istnieje.
     */
    bool istnieje() const;

    /**
     * @brief Zwraca wartość aktualnego elementu.
     * @return Wartość elementu.
     * @throws std::out_of_range Gdy iterator nie wskazuje na element.
     */
    int wartosc() const;

    /**
     * @brief Przechodzi do następnego elementu.
     */
    void nastepny();

    /**
     * @brief Przechodzi do poprzedniego elementu.
     */
    void poprzedni();
};

#endif
