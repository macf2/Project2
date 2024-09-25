#pragma once

#include "node.hpp"

template <typename T>
class Queue
{
public:
        Queue()
        {
                pfront = new Node<T>(T());
                pback = pfront;
        }

        void enqueue(T elem)
        {
                Node<T> *pnode = new Node<T>(elem);
                pback->setNext(pnode);
                pback = pnode;
        }

        T dequeue()
        {       
                Node<T> *ptemp = pfront;
                T item = ptemp->getItem();
                pfront = pfront->getNext();
                delete ptemp;
                return item;
        }

        bool search(T elem)
        {
                Node<T> *pcurrent = pfront;
                while ((pcurrent = pfront->getNext()) != NULL)
                {
                        if (pcurrent->object == elem)
                                return true;
                }
        }

        void print()
        {
                Node<T> *pcurrent = pfront;
                while ((pcurrent = pcurrent->getNext()) != NULL)
                {
                        std::cout << pcurrent->getItem() << '\n';
                }
        }

private:        

        Node<T> *pfront, *pback;
};