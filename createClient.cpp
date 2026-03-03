#include <iostream>
#include "createClient.h"
#include "UI.h"
using namespace std;

void date::askName() {
    cout << "Nombre: ";
    getline(cin, name);

    while (name.empty()) {
        cout << RED << "ERROR: Nombre no ingresado." << RESET <<endl;
        cout << "Nombre: ";
        getline(cin, name);
    }
}
void date::askLastName() {
    cout << "Apellido(s): ";
    getline(cin, lastName);
    while (lastName.empty()) {
        cout << RED << "ERROR: Apellido no ingresado." << RESET <<endl;
        cout << "Apellido(s): ";
        getline(cin, lastName);
    }
}
void date::askID() {
    while (true) {
        cout << "ID: ";
        if (!(cin >> id)) {
            cout << RED << "ERROR: El ID no puede contener letras." << RESET <<endl;
            cin.clear();
            cin.ignore(1000, '\n');
        } else if (id <= 0) {
            cout << RED << "ERROR: El ID debe ser un numero positivo." << RESET <<endl;
        } else {
            break;
        }
    }
}
void date::askAge() {
    while (true) {
        cout << "Edad: ";
        if (!(cin >> age) || age <= 0 || age > 200) {
            cout << RED << "ERROR: Edad no valida." << RESET <<endl;
            cin.clear();
            cin.ignore(1000, '\n');
        } else {
            break;
        }
    }
}
void date::askPhoneNumber() {
    while (true) {
        cout << "Número telefonico (10 digitos): ";
        if (!(cin >> phoneNumber)) {
            cout << RED << "ERROR: El telefono no puede contener letras." << RESET <<endl;
            cin.clear();
            cin.ignore(1000, '\n');
        } else if (phoneNumber < 1000000000LL || phoneNumber > 9999999999LL) {
            cout << RED << "ERROR: El telefono debe tener exactamente 10 dígitos." << RESET <<endl;
        } else {
            break; 
        }
    }
}
void date::askEmail() {
    cout << "Correo electronico: ";
    cin>> email;
    while (email.empty() || email.find('@') == string::npos || email.find('.') == string::npos) {
        cout << RED << "ERROR: Correo electronico no válido." << RESET <<endl;
        cout << "Correo electronico: ";
        cin >> email;
    }
}
void date::askAddress() {
    cout << "Direccion: ";
    getline(cin, address);
    while (address.empty()) {
        cout << RED << "ERROR: Direccion no ingresada." << RESET <<endl;
        cout << "Direccion: ";
        getline(cin, address);
    }
}
void date::sumaryDate() {
    cout <<"╔═════════════════════════════════╗"<<endl;
    cout <<"║  "<< GREEN <<"La informacion registrada es:  "<< RESET <<"║"<<endl;
    cout <<"╚═════════════════════════════════╝"<<endl;
    cout << "Nombre: " << name <<endl;
    cout << "Apellido(s): " << lastName <<endl;
    cout << "ID: " << id <<endl;
    cout << "Edad: " << age <<endl;
    cout << "Numero telefonico: " << phoneNumber <<endl;
    cout << "Correo electronico: " << email <<endl;
    cout << "Direccion: " << address <<endl;
}

void createClients(vector<date> &clients) {
    bool repeatEntry = false;
    do{
        //clear bufer
        cin.ignore(1000, '\n');

        date newClient;

        cout <<"╔══════════════════════════════════════════╗"<<endl;
        cout <<"║   "<< BLUE <<"INGRESO DE DATOS PARA NUEVA PERSONA    "<< RESET <<"║"<<endl;
        cout <<"╚══════════════════════════════════════════╝"<<endl;

        newClient.askName();
        newClient.askLastName();
        newClient.askID();
        newClient.askAge();
        newClient.askPhoneNumber();
        newClient.askEmail();
        newClient.askAddress();
        newClient.sumaryDate();

        bool validOption = false;
        do{
            cout << "¿Desea guardar este cliente? \n 1. Si \n 2. No \n 3. volver a ingresar datos \n";
            int confirmSave;
            cin >> confirmSave;
            if (!(cin >> confirmSave)) { 
                    cout << RED << "ERROR: Ingrese un numero valido." << RESET << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout<<CLEAR;
                    continue; 
                }
            if (confirmSave == 1)  
            {
                clients.push_back(newClient);
                cout << GREEN << "Cliente guardado exitosamente." << RESET <<endl;
                validOption = true;
            }
            else if (confirmSave == 2) {
                cout << YELLOW << "Cliente no guardado." << RESET <<endl;
                cout << "Presione Enter para continuar...";
                cin.ignore(1000, '\n');
                cin.get();
                cout << CLEAR;
                validOption = true;
            }
            else if (confirmSave == 3) {
                cout << YELLOW << "Reingresa los datos del cliente." << RESET <<endl;
                cout << "Presione Enter para continuar...";
                cin.ignore(1000, '\n');
                cin.get();
                cout << CLEAR;
                validOption = true;
                repeatEntry = true;
            }
            else {
                cout << RED << "Opción no válida. Cliente no guardado." << RESET <<endl;
                cout << "Presione Enter para continuar...";
                cin.ignore(1000, '\n');
            }
            cin.get();
            cout << CLEAR;

        }while (!validOption);
        

    }while (repeatEntry);
   
}

