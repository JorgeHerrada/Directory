#ifndef CONTACTO_H
#define CONTACTO_H
#include <iostream>
using namespace std;

class Contacto
{
private:
    string name;
    string phone;
    int index;
public:
    Contacto(string name,string phone);
    void setName(string _name);
    void setPhone(string _phone);
    void setIndex(int index);
    string getName();
    string getPhone();
    int getIndex();
};

Contacto::Contacto(string _name,string _phone)
{
    name = _name;
    phone = _phone;
}

void Contacto::setName(string _name)
{
    name = _name;
}

void Contacto::setPhone(string _phone)
{
    phone = _phone;
}

string Contacto::getName()
{
    return name;
}

string Contacto::getPhone()
{
    return phone;
}

void Contacto::setIndex(int _index)
{
    index = _index;
}

int Contacto::getIndex()
{
    return index;
}






#endif