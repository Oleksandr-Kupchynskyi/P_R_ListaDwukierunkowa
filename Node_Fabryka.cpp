#include "Node_Fabryka.h"
#include "Node.h"

/**
 * @brief Tworzy nowy węzeł z podaną wartością.
 */
Node* Node_Fabryka::utworz(int wart) {
    return new Node(wart);
}