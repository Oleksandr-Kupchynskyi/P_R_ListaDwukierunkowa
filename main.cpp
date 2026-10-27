#include <iostream>
#include "ListaDwukierunkowa.h"

using namespace std;

int main() {
    ListaDwukierunkowa lista;

    cout << "Dodanie elementow" << endl;

    lista.dodaj_P(20);
    lista.dodaj_P(2);
    lista.dodaj_K(3);
    lista.dodaj_i(1, 4);
    lista.dodaj_i(50, 3);


    cout << "Wyswietlanie elementow" << endl;
    lista.wyswietl();

    lista.wyswietlOdwrotnie();

    lista.wyswietlNastepny(3);
    lista.wyswietlPoprzedni(2);

    cout << "Iterator" << endl;
    Iterator i = lista.poczatek();

    if (i.istnieje()) {
        cout << "Pierwszy element: " << i.wartosc()
            << '\n';

        i.nastepny();

        if (i.istnieje()) {
            cout << "Drugi element: " << i.wartosc() << endl;
        }

        i.poprzedni();

        if (i.istnieje()) {
            cout << "Po powrocie: " << i.wartosc() << endl;
        }
    }

    cout << "Usuwanie elementow" << endl;

    lista.usun_P();
    lista.wyswietl();

    lista.usun_K();
    lista.wyswietl();

    lista.usun(1);
    lista.wyswietl();

    return 0;

}