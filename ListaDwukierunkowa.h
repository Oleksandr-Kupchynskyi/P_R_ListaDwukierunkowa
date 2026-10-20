#ifndef LISTA_Dwukierunkowa_H
#define LISTA_Dwukierunkowa_H

#include "Node.h"
using namespace std;

class ListaDwukierunkowa {
    private:
    Node* head;
    Node* tail;

    public:

    ListaDwukierunkowa() : head(nullptr), tail(nullptr) {}

    //metody 


    void dodaj_P(int wart) // dodaje na poczatek
    {
        Node* newNode = new Node(wart);
        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void dodaj_K(int wart) // dodaje do koniec
    {
        Node* newNode = new Node(wart);
        if (!tail) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void dodaj_i(int wart, int indeks) // dodaje pod wskazany indeks
    {

    }
    void usun(int indeks) // usuwa element o wskazanym indeksu
    {

    }
    void wyswietl() // wyswietla liste
    {

    }
    void wyczysc() // wyczyscza liste
    {

    }
};

#endif