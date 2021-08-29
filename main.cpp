#include "List.cpp"
#include <string.h>


int menu();
void callMethod(int opt);
Contacto* getInformation();

// VALIDATE DATA
int getInt();
bool validInt(string numero);

List list;

int main()
{
    int opt;
    do
    {
        system("cls");
        opt = menu();
        callMethod(opt);

        // cout << opt;
        system("pause");
    } while (opt != 0);
    
    cout << "ADIOS, VAQUERO." << endl;
    


    return 0;
}


int menu()
{
    int opt;

    cout << "\n\n****************DIRECTORIO***************\n\n";
    cout << "1.-AGREGAR CONTACTO"<<endl;
    cout << "2.-ELIMINAR CONTACTO"<<endl;
    cout << "3.-BUSCAR CONTACTO"<<endl;
    cout << "4.-VER CONTACTOS"<<endl;
    cout << "5.-MODIFICAR CONTACTO"<<endl;
    cout << "0.- SALIR"<<endl;

    opt = getInt();

    return opt;
}


void callMethod(int opt)
{
    string info;
    switch (opt)
    {
    case 1:
        list.insertTail(getInformation());
        break;
    case 2:
        if(list.isEmpty())
        {
            cout << "El directorio se encuentra vacío. Intenta primero agregar un contacto." << endl;
        }
        else
        {
            cout << "Ingresa nombre o telefono a eliminar: ";
            getline(cin,info);   
            list.deleteIndx(list.find(info)->getIndex());
        }
        break;
    case 3:
        if (list.isEmpty())
        {
            cout << "El directorio se encuentra vacío. Intenta primero agregar un contacto." << endl;
        }
        else
        {
            cout << "Ingresa nombre o telefono a buscar: ";
            getline(cin,info); 
            list.find(info);
        }        
        break;
    case 4:
        list.printAll();
        break;
    case 5:
        if(list.isEmpty())
        {
            cout << "El directorio se encuentra vacío. Intenta primero agregar un contacto." << endl;
        }
        else
        {
            cout << "Ingresa nombre o telefono a modificar: ";
            getline(cin,info); 
            list.modify(list.find(info)->getIndex(),getInformation());
        }
        break;
    case 0:
        /* code */
        break;
    
    default:
        break;
    }
}

Contacto* getInformation()
{
    string name,phone;
    cout << "Inserta el nombre del contacto: ";
    getline(cin,name);
    cout << endl;
    cout << "Inserta el telefono del contacto: ";
    getline(cin,phone);
    cout << endl;

    Contacto* newContact = new Contacto(name,phone);

    return newContact;
}



// VALIDATE AND CAST STRING TO INT
int getInt() {
    string numero;
    bool esValido = false;

    while(! esValido) {
        try {
            //cout<<"Ingrese su opcion: ";
            getline(cin,numero);
            esValido = validInt(numero);

            if(! esValido) {
                throw numero;
            }
        } catch(string e) {
            cout<<"\n\nEl entero: "<<e<<" no es valido. Intenta de nuevo: "<<endl;
        }
    }
    return atoi(numero.c_str());
}

// VALIDATE INT
bool validInt(string numero) {
    int inicio=0;
    if (numero.length()==0)
        return 0; //false
    if(numero[0] == '+' || numero[0] == '-') {
        inicio = 1;
        if (numero.length() == 1)
            return 0;
    }
    for (int i=inicio; i<numero.length(); i++) {
        if(! isdigit(numero[i]))
            return 0;
    }
    return 1;
}