#ifndef NODE_H 
#define NODE_H

/**
 * @file Node.h
 * @brief Definicja wêz³a listy dwukierunkowej.
 */

 /**
  * @class Node
  * @brief Pojedynczy wêze³ listy dwukierunkowej.
  */

using namespace std;

class Node {

private:
    int data;
    Node* prev;
    Node* next;

public:
    /**
     * @brief Tworzy nowy wêze³.
     * @param wart Wartoœæ przechowywana w wêŸle.
     */
    Node(int wart) : data(wart), prev(nullptr), next(nullptr) {}

    friend class ListaDwukierunkowa;
    friend class Iterator;
};

#endif