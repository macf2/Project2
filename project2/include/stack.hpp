#ifndef STACK_H
#define STACK_H

#include "node.hpp"
#include <iostream>
using std::cout, std::endl;

/*
 * Stack class
 * All Nodes will point to the Node below
 */
template<typename Object>
class Stack {
private:
    Node<Object>* top;

public:
    // Constructor
    Stack() {
        // Start with an empty Stack
        top = nullptr;
    }

    // De-constructor aka destructor
    // This method will automatically be called
    // at the end of the lifetime of the object
    ~Stack() {
        // Make sure no heap allocation
        while (top != nullptr) {
            pop();
        }
        cout << "No memory leaks!" << endl;
    }

    // push (add a value to the Stack)
    void push(Object item) {
        // Store the item in a Node in heap memory
        Node<Object>* newNodePtr = new Node<Object>(item);
        // Have the new Node point to top
        newNodePtr->setNext(top);
        // The new Node becomes top
        top = newNodePtr;
    }

    // pop (remove a value from the Stack)
    // Returns the value being popped
    Object pop() {
        // Check that there is a Node to pop
        if (top == nullptr) {
            // The Stack is empty
            return Object();
        }
        // Create a copy of the value to be returned
        Object item = top->getItem();
        // Store a copy of top
        Node<Object>* topCopy = top;
        // Update top
        top = top->getNext();
        // Delete the Node from heap memory
        delete topCopy;
        // Return the value being popped
        return item;
    }

    // Search for an item in the Stack
    // Return true if the item is in the Stack
    // Return false otherwise
    bool search(Object item) const {
        Node<Object>* topCopy = top;
        while (topCopy != nullptr) {
            if (topCopy->getItem() == item) {
                return true;
            }
            topCopy = topCopy->getNext();
        }
        return false;
    }

    // Print (list all the values in the Stack)
    void print() const {
        cout << "Top of Stack" << endl;
        Node<Object>* curr = top;
        while (curr != nullptr) {
            cout << curr->getItem() << endl;
            curr = curr->getNext();
        }
        cout << "Bottom of Stack" << endl;
    }
};

#endif