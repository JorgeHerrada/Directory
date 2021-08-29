#ifndef NODO_H
#define NODO_H
#include "Contacto.cpp"

class Nodo
{
private: 
    Nodo* pNext;
    Nodo* pPrev;
    Contacto* data;
public: 
    void insertNext(Contacto* data);    // INSERT NEW NODO NEXT TO "THIS"
    Contacto* deleteNext();             // DELETE OLD NODO NEXT TO "THIS"

    friend class List;
};

// INSERT NEW NODO NEXT TO "THIS"
void Nodo::insertNext(Contacto* data)
{
    Nodo* nNodo = new Nodo;     //CREATE THE NEW NODO
    nNodo->data = data;         // SAVE THE DATA ON THE NEW NODO
    
    //LINK THE POINTERS TO INSERT THE NEW NODO
    nNodo->pNext = this->pNext; 
    nNodo->pPrev = this;
    nNodo->pNext->pPrev = nNodo;
    this->pNext = nNodo;
}

Contacto* Nodo::deleteNext()
{
    Contacto* data = this->pNext->data; // SAVE THE DATA
    
    // LINK THE NODES, NOW EXCLUDING THE NEXT TO "THIS"
    this->pNext = this->pNext->pNext;   
    this->pNext->pPrev = this;

    return data; // return DATA
}


#endif