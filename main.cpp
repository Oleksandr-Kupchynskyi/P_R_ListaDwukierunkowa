#include <iostream>
#include "ListaDwukierunkowa.h"

using namespace std;

int main(){
    ListaDwukierunkowa lista;
    lista.dodaj_P(2);
    lista.dodaj_K(3);
    lista.dodaj_i(1,4);

    lista.wyswietl();
}