#ifndef NODE_FABRYKA_H
#define NODE_FABRYKA_H

#include "Node.h"

/**
 * @file Node_Fabryka.h
 * @brief Deklaracja fabryki węzłów.
 */

class Node_Fabryka {
    public:
        static Node* utworz(int wart);
};
#endif