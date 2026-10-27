/**
 * @file Iterator.cpp
 * @brief Implementacja iteratora.
 */

#include "Iterator.h"
#include <stdexcept>

Iterator::Iterator(Node* start)
    : current(start) {
}

bool Iterator::istnieje() const {
    return current != nullptr;
}

int Iterator::wartosc() const {
    if (!current) {
        throw std::out_of_range(
            "Iterator nie wskazuje na element."
        );
    }

    return current->data;
}

void Iterator::nastepny() {
    if (current) {
        current = current->next;
    }
}

void Iterator::poprzedni() {
    if (current) {
        current = current->prev;
    }
}
