#include <iostream>
#include <vector>
#include <string>
#include "createClient.h"
#include "UI.h"
using namespace std;
void createClients(vector<date> &personas) {
    date newClient;
    //clear bufer
    cin.ignore(1000, '\n');
    cout <<"╔══════════════════════════════════════════╗"<<endl;
    cout <<"║   "<< BLUE <<"INGRESO DE DATOS PARA NUEVA PERSONA    "<< RESET <<"║"<<endl;
    cout <<"╚══════════════════════════════════════════╝"<<endl;

    // input and validation of name
    cout << "Nombre: ";
    getline(cin, newClient.name);
    //validation of name is not empty
    while (newClient.name.empty()) {
        cout << RED << "ERROR: Nombre no ingresado." << RESET <<endl;
        cout << "Nombre: ";
        getline(cin, newClient.name);
    }

    // input and validation of last name
    cout << "Apellido(s): ";
    getline(cin, newClient.lastName);
    //validation of last name is not empty
    while (newClient.lastName.empty()) {
        cout << RED << "ERROR: Apellido no ingresado." << RESET <<endl;
        cout << "Apellido(s): ";
        getline(cin, newClient.lastName);
    }

    // input and validation of ID
    while (true) {
        cout << "ID: ";
        //validation of ID is a number and positive
        if (!(cin >> newClient.id)) {
            cout << RED << "ERROR: El ID no puede contener letras." << RESET <<endl;
            cin.clear();
            cin.ignore(1000, '\n');
        } else if (newClient.id <= 0) {
            cout << RED << "ERROR: El ID debe ser un numero positivo." << RESET <<endl;
        } else {
            break; // ID correcto
        }
    }

    // INPUT AND VALIDATION OF AGE
    while (true) {
        cout << "Edad: ";
        //validation of age is a number and between 1 and 200
        if (!(cin >> newClient.age) || newClient.age <= 0 || newClient.age > 200) {
            cout << RED << "ERROR: Edad no valida." << RESET <<endl;
            cin.clear();
            cin.ignore(1000, '\n');
        } else {
            break;
        }
    }

    // input and validation of phone number
    while (true) {
        cout << "Número telefonico (10 digitos): ";
        //validation of phone number is a number and has exactly 10 digits
        if (!(cin >> newClient.phoneNumber)) {
            cout << RED << "ERROR: El telefono no puede contener letras." << RESET <<endl;
            cin.clear();
            cin.ignore(1000, '\n');
        } else if (newClient.phoneNumber < 1000000000LL || newClient.phoneNumber > 9999999999LL) {
            cout << RED << "ERROR: El telefono debe tener exactamente 10 dígitos." << RESET <<endl;
        } else {
            break; 
        }
    }

    // input and validation of email
    cout << "Correo electronico: ";
    cin>> newClient.email;
    //validation of email is not empty and contains '@' and '.' (returns string::npos if the character is not found)
    while (newClient.email.empty() || newClient.email.find('@') == string::npos || newClient.email.find('.') == string::npos) {
        cout << RED << "ERROR: Correo electronico no válido." << RESET <<endl;
        cout << "Correo electronico: ";
        cin >> newClient.email;
    }

    // input and validation of address
    cout << "Direccion: ";
    cin.ignore(1000, '\n');
    getline(cin, newClient.address);
    //validation of address is not empty
    while (newClient.address.empty()) {
        cout << RED << "ERROR: Direccion no ingresada." << RESET <<endl;
        cout << "Direccion: ";
        getline(cin, newClient.address);
    }
    cout << CLEAR;
    //confirmation of client creation
    cout <<"╔═════════════════════════════════╗"<<endl;
    cout <<"║  "<< GREEN <<"Cliente registrado con exito.  "<< RESET <<"║"<<endl;
    cout <<"╚═════════════════════════════════╝"<<endl;
    cout << "Nombre: " << newClient.name <<endl;
    cout << "Apellido(s): " << newClient.lastName <<endl;
    cout << "ID: " << newClient.id <<endl;
    cout << "Edad: " << newClient.age <<endl;
    cout << "Numero telefonico: " << newClient.phoneNumber <<endl;
    cout << "Correo electronico: " << newClient.email <<endl;
    cout << "Direccion: " << newClient.address <<endl;
    cout << "¿Desea guardar este cliente? \n 1. Si \n 2. No \n 3. volver a ingresar datos \n";
    int confirmSave;
    cin >> confirmSave;
    if (confirmSave == 1)  
    {
        personas.push_back(newClient);
        cout << GREEN << "Cliente guardado exitosamente." << RESET <<endl;
    }
    else if (confirmSave == 2) {
        cout << YELLOW << "Cliente no guardado." << RESET <<endl;
        cout << "Presione Enter para continuar...";
        cin.ignore(1000, '\n');
        cin.get();
        cout << CLEAR;
    }
    else if (confirmSave == 3) {
        createClients(personas);
    }
    else {
        cout << RED << "Opción no válida. Cliente no guardado." << RESET <<endl;
        cout << "Presione Enter para continuar...";
        cin.ignore(1000, '\n');
    }
    cin.get();
    cout << CLEAR;
}