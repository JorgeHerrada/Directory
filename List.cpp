#ifndef LIST_H
#define LIST_H
#include "Nodo.cpp"

class List
{
private:
    Nodo head;
    Nodo tail;
    unsigned short count = 0;
public:
    List();
    ~List();
    void insertHead(Contacto* data);    // ADD NODE TO THE FIRS POSITION
    void insertTail(Contacto* data);    // ADD NODE TO THE LAST POSITION
    Contacto* deleteHead();             // DELETE FIRST NODE
    Contacto* deleteTail();             // DELETE LAST NODE
    unsigned short size();              // RETURNS NUMBER OF NODES ON THE LIST
    bool isEmpty();                     // RETURNS TRUE IF NO NODES ON THE LIST
    void printAll();                    // PRINT ALL LIST OF CONTACTS
    void printContact(Contacto* data);  // PRINT AND SPECIFIC INDEX                 **** COULD RECEIVE INDEX ONLY
    void modify(int idx,Contacto* data);// MODIFY NODE BASED ON INDEX
    Contacto* deleteIndx(int index);    // DELETE NODE BASED ON INDEX
    Contacto* find(string info);        // FIND CONTACT AND RETURN DATA WITH INDEX  **** COULD RETURN INDEX ONLY 
};

List::List()
{
    head.pNext = &tail; // Link head to tail
    tail.pPrev = &head; // Link tail to head
}

List::~List()
{
    Nodo* aux = head.pNext;

    while (aux->pNext != &tail)
    {
        aux = aux->pNext;
        delete aux->pPrev;
    }

    delete aux;   
}

void List::insertHead(Contacto* data)
{
    head.insertNext(data);
    count++;
}

void List::insertTail(Contacto* data)
{
    tail.pPrev->insertNext(data);
    count++;
}

Contacto* List::deleteHead()
{
    count--;
    return head.deleteNext();
}

Contacto* List::deleteTail()
{
    count--;
    return tail.pPrev->pPrev->deleteNext();
}

unsigned short List::size()
{
    return count;
}

bool List::isEmpty()
{
    if (head.pNext == & tail)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

void List::printAll()
{
    if(isEmpty())
    {
        cout << "El directorio se encuentra vacío. Intenta primero agregar un contacto." << endl;
    }
    else
    {
        Nodo* aux = head.pNext;
        size_t i = 1;
        while (aux != &tail)
        {
            cout << "Contacto #" << i << ":" << endl;
            cout << aux->data->getName() << endl;
            cout << aux->data->getPhone() << endl;
            cout << endl;

            aux = aux->pNext;
            i++;
        }
        cout << endl;        
    }
}

void List::printContact(Contacto* data)
{
    if (data->getIndex() > -1)
    {
        Nodo* aux = &head;

        for (size_t i = 0; i < data->getIndex(); i++)
        {
            aux = aux->pNext;
        }

        cout << aux->data->getIndex() << endl;
        cout << aux->data->getName() << endl;
        cout << aux->data->getPhone() << endl;
        cout << endl;
    }
}

void List::modify(int index, Contacto* newData)
{
    if(index > -1)
    {
        Nodo* aux = &head;

        for (size_t i = 0; i < index; i++)
        {
            aux = aux->pNext;
        }

        // cout << aux->data->getIndex() << endl;
        // cout << aux->data->getName() << endl;
        // cout << aux->data->getPhone() << endl;
        // cout << endl;

        aux->data->setName(newData->getName());
        aux->data->setPhone(newData->getPhone());
    }
}

Contacto* List::deleteIndx(int index)
{
    if (index > -1)
    {
        Nodo* aux = &head;

        for (size_t i = 0; i < index; i++)
        {
            aux = aux->pNext;
        }
        
        return aux->pPrev->deleteNext();    
    }  
}

Contacto* List::find(string info)
{
    Nodo* aux = head.pNext;
    int count = 0;

    if(isEmpty())
    {
        cout << "El directorio está vacío" << endl;
    }
    else
    {
        while (aux != &tail)
        {
            count++;
            if(aux->data->getName() == info || aux->data->getPhone() == info)
            {
                aux->data->setIndex(count);
                cout << "CONTACTO ENCONTRADO: " << endl;
                printContact(aux->data);
                return aux->data;
            }
            else
            {
                aux = aux->pNext;
            }
        }

        cout << "No se ha encontrado el contacto: " << info << "." << endl;

        Contacto* c = new Contacto("none","none");
        c->setIndex(-1);
        return c;
    }   
}


#endif