
#ifndef LISTA_DWUKIERUNKOWA_H
#define LISTA_DWUKIERUNKOWA_H

/**
 * @file ListaDwukierunkowa.h
 * @brief Deklaracja listy dwukierunkowej.
 */

#include "Node.h"
#include "Iterator.h"

 /**
  * @class ListaDwukierunkowa
  * @brief Lista dwukierunkowa przechowująca liczby całkowite.
  *
  * Indeksy elementów zaczynają się od zera.
  */
class ListaDwukierunkowa {
private:
    Node* head; ///< Pierwszy węzeł listy.
    Node* tail; ///< Ostatni węzeł listy.

public:
    /**
     * @brief Tworzy pustą listę.
     */
    ListaDwukierunkowa();

    /**
     * @brief Usuwa wszystkie elementy listy.
     */
    ~ListaDwukierunkowa();

    // Lista zarządza pamięcią węzłów, dlatego
    // wyłączamy niebezpieczne kopiowanie płytkie.
    ListaDwukierunkowa(const ListaDwukierunkowa&) = delete;
    ListaDwukierunkowa& operator=(
        const ListaDwukierunkowa&
        ) = delete;

    /**
     * @brief Dodaje element na początek listy.
     * @param wart Wartość nowego elementu.
     */
    void dodaj_P(int wart);

    /**
     * @brief Dodaje element na koniec listy.
     * @param wart Wartość nowego elementu.
     */
    void dodaj_K(int wart);

    /**
     * @brief Wstawia element pod wskazany indeks.
     * @param wart Wartość nowego elementu.
     * @param indeks Indeks od zera;
     * @note Indeksy ujemne i większe od rozmiaru
     * listy są ignorowane.
     */
    void dodaj_i(int wart, int indeks);

    /**
     * @brief Usuwa pierwszy element listy.
     */
    void usun_P();

    /**
     * @brief Usuwa ostatni element listy.
     */
    void usun_K();

    /**
     * @brief Usuwa element o podanym indeksie.
     * @param indeks Indeks elementu od zera.
     */
    void usun(int indeks);

    /**
     * @brief Wyświetla listę od początku do końca.
     */
    void wyswietl() const;

    /**
     * @brief Wyświetla listę od końca do początku.
     */
    void wyswietlOdwrotnie() const;

    /**
     * @brief Wyświetla element znajdujący się
     * bezpośrednio za podanym indeksem.
     * @param indeks Indeks elementu bazowego.
     */
    void wyswietlNastepny(int indeks) const;

    /**
     * @brief Wyświetla element znajdujący się
     * bezpośrednio przed podanym indeksem.
     * @param indeks Indeks elementu bazowego.
     */
    void wyswietlPoprzedni(int indeks) const;

    /**
     * @brief Usuwa wszystkie elementy listy.
     */
    void wyczysc();

    /**
     * @brief Zwraca iterator wskazujący na początek listy.
     */
    Iterator poczatek() const;

    /**
     * @brief Zwraca iterator wskazujący na koniec listy.
     */
    Iterator koniec() const;
};

#endif
