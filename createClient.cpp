#include <iostream>
#include "createClient.h"
#include "UI.h"


void data::askName() {
    std::cout << "Nombre(s): ";
    std::getline(std::cin, name);

    while (name.empty()) {
        std::cout << RED << "ERROR: Nombre no ingresado." << RESET <<std::endl;
        std::cout << "Nombre(s): ";
        std::getline(std::cin, name);
    }
}
void data::askLastName() {
    std::cout << "Apellido(s): ";
    std::getline(std::cin, lastName);
    while (lastName.empty()) {
        std::cout << RED << "ERROR: Apellido no ingresado." << RESET <<std::endl;
        std::cout << "Apellido(s): ";
        std::getline(std::cin, lastName);
    }
}
void data::askID() {
    while (true) {
        std::cout << "ID: ";
        if (!(std::cin >> id)) {
            std::cout << RED << "ERROR: El ID no puede contener letras." << RESET <<std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        } else if (id <= 0) {
            std::cout << RED << "ERROR: El ID debe ser un numero positivo." << RESET <<std::endl;
        } else {
            break;
        }
    }
}
void data::askAge() {
    while (true) {
        std::cout << "Edad: ";
        if (!(std::cin >> age) || age <= 0 || age > 200) {
            std::cout << RED << "ERROR: Edad no valida." << RESET <<std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        } else {
            break;
        }
    }
}
void data::askPhoneNumber() {
    while (true) {
        std::cout << "Número telefonico (10 digitos): ";
        if (!(std::cin >> phoneNumber)) {
            std::cout << RED << "ERROR: El telefono no puede contener letras." << RESET <<std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        } else if (phoneNumber < 1000000000LL || phoneNumber > 9999999999LL) {
            std::cout << RED << "ERROR: El telefono debe tener exactamente 10 dígitos." << RESET <<std::endl;
        } else {
            break; 
        }
    }
}
void data::askEmail() {
    std::cout << "Correo electronico: ";
    std::cin>> email;
    while (email.empty() || email.find('@') == std::string::npos || email.find('.') == std::string::npos) {
        std::cout << RED << "ERROR: Correo electronico no válido." << RESET <<std::endl;
        std::cout << "Correo electronico: ";
        std::cin >> email;
    }
}
void data::askAddress() {
    std::cin.ignore(1000, '\n');
    std::cout << "Direccion: ";
    std::getline(std::cin, address);
    while (address.empty()) {
        std::cout << RED << "ERROR: Direccion no ingresada." << RESET <<std::endl;
        std::cout << "Direccion: ";
        std::getline(std::cin, address);
    }
}
void data::sumaryDate() {
    std::cout<<CLEAR;
    std::cout <<"╔═════════════════════════════════╗"<<std::endl;
    std::cout <<"║  "<< GREEN <<"La informacion registrada es:  "<< RESET <<"║"<<std::endl;
    std::cout <<"╚═════════════════════════════════╝"<<std::endl;
    std::cout << "Nombre: " << name <<std::endl;
    std::cout << "Apellido(s): " << lastName <<std::endl;
    std::cout << "ID: " << id <<std::endl;
    std::cout << "Edad: " << age <<std::endl;
    std::cout << "Numero telefonico: " << phoneNumber <<std::endl;
    std::cout << "Correo electronico: " << email <<std::endl;
    std::cout << "Direccion: " << address <<std::endl;
}

void createClients(std::vector<data> &clients) {
    bool repeatEntry = false;
    do{
        std::cin.ignore(1000, '\n');
        data newClient;
        std::cout<<CLEAR;
        std::cout <<"╔══════════════════════════════════════════╗"<<std::endl;
        std::cout <<"║   "<< BLUE <<"INGRESO DE DATOS PARA NUEVA PERSONA    "<< RESET <<"║"<<std::endl;
        std::cout <<"╚══════════════════════════════════════════╝"<<std::endl;

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
            std::cout << "¿Desea guardar este cliente? \n 1. Si \n 2. No \n 3. volver a ingresar datos \n";
            int confirmSave;
            if (!(std::cin >> confirmSave)) { 
                    std::cout << RED << "ERROR: Ingrese un numero valido." << RESET << std::endl;
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cout<<CLEAR;
                    continue; 
                }
            if (confirmSave == 1)  
            {
                clients.push_back(newClient);
                std::cout << GREEN << "Cliente guardado exitosamente." << RESET <<std::endl;
                validOption = true;
            }
            else if (confirmSave == 2) {
                std::cout << YELLOW << "Cliente no guardado." << RESET <<std::endl;
                std::cout << "Presione Enter para continuar...";
                std::cin.ignore(1000, '\n');
                std::cin.get();
                std::cout << CLEAR;
                validOption = true;
            }
            else if (confirmSave == 3) {
                std::cout << YELLOW << "Reingresa los datos del cliente." << RESET <<std::endl;
                std::cout << "Presione Enter para continuar...";
                std::cin.ignore(1000, '\n');
                std::cin.get();
                std::cout << CLEAR;
                validOption = true;
                repeatEntry = true;
            }
            else {
                std::cout << RED << "Opción no válida. Cliente no guardado." << RESET <<std::endl;
                std::cout << "Presione Enter para continuar...";
                std::cin.ignore(1000, '\n');
            }
            std::cin.get();
            std::cout << CLEAR;

        }while (!validOption);
        

    }while (repeatEntry);
   
}

