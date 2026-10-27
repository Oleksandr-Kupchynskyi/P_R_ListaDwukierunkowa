/**
 * @file ListaDwukierunkowa.cpp
 * @brief Implementacja listy dwukierunkowej.
 */

#include "ListaDwukierunkowa.h"
#include "Node_Fabryka.h"

#include <iostream>

using namespace std;

ListaDwukierunkowa::ListaDwukierunkowa()
    : head(nullptr), tail(nullptr) {
}

ListaDwukierunkowa::~ListaDwukierunkowa() {
    wyczysc();
}

void ListaDwukierunkowa::dodaj_P(int wart) {
    Node* nowy = Node_Fabryka::utworz(wart);

    if (head == nullptr) {
        head = tail = nowy;
    }
    else {
        nowy->next = head;
        head->prev = nowy;
        head = nowy;
    }
}

void ListaDwukierunkowa::dodaj_K(int wart) {
    Node* nowy = Node_Fabryka::utworz(wart);

    if (tail == nullptr) {
        head = tail = nowy;
    }
    else {
        tail->next = nowy;
        nowy->prev = tail;
        tail = nowy;
    }
}

void ListaDwukierunkowa::dodaj_i(int wart, int indeks) {
    if (indeks < 0) {
        return;
    }

    if (indeks == 0) {
        dodaj_P(wart);
        return;
    }

    Node* pom = head;
    int i = 0;

    // Szukanie elementu, przed którym wstawiamy nowy.
    while (pom != nullptr && i < indeks) {
        pom = pom->next;
        ++i;
    }

    if (pom == nullptr) {
        // Indeks równy rozmiarowi oznacza koniec listy.
        if (i == indeks) {
            dodaj_K(wart);
        }
        return;
    }

    Node* nowy = Node_Fabryka::utworz(wart);

    nowy->next = pom;
    nowy->prev = pom->prev;

    pom->prev->next = nowy;
    pom->prev = nowy;
}

void ListaDwukierunkowa::usun_P() {
    if (head == nullptr) {
        return;
    }

    Node* pom = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    }
    else {
        tail = nullptr;
    }

    delete pom;
}

void ListaDwukierunkowa::usun_K() {
    if (tail == nullptr) {
        return;
    }

    Node* pom = tail;
    tail = tail->prev;

    if (tail != nullptr) {
        tail->next = nullptr;
    }
    else {
        head = nullptr;
    }

    delete pom;
}

void ListaDwukierunkowa::usun(int indeks) {
    if (indeks < 0) {
        return;
    }

    Node* pom = head;
    int i = 0;

    while (pom != nullptr && i < indeks) {
        pom = pom->next;
        ++i;
    }

    if (pom == nullptr) {
        return;
    }

    if (pom->prev != nullptr) {
        pom->prev->next = pom->next;
    }
    else {
        head = pom->next;
    }

    if (pom->next != nullptr) {
        pom->next->prev = pom->prev;
    }
    else {
        tail = pom->prev;
    }

    delete pom;
}

void ListaDwukierunkowa::wyswietl() const {
    cout << "Lista od poczatku: ";

    Iterator it(head);

    while (it.istnieje()) {
        cout << it.wartosc() << " ";
        it.nastepny();
    }

    cout << '\n';
}

void ListaDwukierunkowa::wyswietlOdwrotnie() const {
    cout << "Lista od konca: ";

    Iterator it(tail);

    while (it.istnieje()) {
        cout << it.wartosc() << " ";
        it.poprzedni();
    }

    cout << '\n';
}

void ListaDwukierunkowa::wyswietlNastepny(
    int indeks
) const {
    if (indeks < 0) {
        cout << "Niepoprawny indeks.\n";
        return;
    }

    Node* pom = head;
    int i = 0;

    while (pom != nullptr && i < indeks) {
        pom = pom->next;
        ++i;
    }

    if (pom == nullptr || pom->next == nullptr) {
        cout << "Brak nastepnego elementu.\n";
        return;
    }

    cout << "Nastepny element: "
        << pom->next->data << '\n';
}

void ListaDwukierunkowa::wyswietlPoprzedni(
    int indeks
) const {
    if (indeks < 0) {
        cout << "Niepoprawny indeks.\n";
        return;
    }

    Node* pom = head;
    int i = 0;

    while (pom != nullptr && i < indeks) {
        pom = pom->next;
        ++i;
    }

    if (pom == nullptr || pom->prev == nullptr) {
        cout << "Brak poprzedniego elementu.\n";
        return;
    }

    cout << "Poprzedni element: "
        << pom->prev->data << '\n';
}

void ListaDwukierunkowa::wyczysc() {
    Node* pom = head;

    while (pom != nullptr) {
        Node* nastepny = pom->next;
        delete pom;
        pom = nastepny;
    }

    head = nullptr;
    tail = nullptr;
}

Iterator ListaDwukierunkowa::poczatek() const {
    return Iterator(head);
}

Iterator ListaDwukierunkowa::koniec() const {
    return Iterator(tail);
}