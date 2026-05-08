#include <iostream>
#include "createProduct.h"
#include "UI.h"
using namespace std;
void dateProduct::askName() {
    cout << "Nombre del producto: ";
    getline(cin, name);
    while (name.empty()) {
        cout << RED << "ERROR: Nombre no ingresado." << RESET <<endl;
        cout << "Nombre del producto: ";
        getline(cin, name);
    }
}
void dateProduct::askDescription() {
    cout << "Descripcion del producto: ";
    getline(cin, description);
    while (description.empty()) {
        cout << RED << "ERROR: Descripcion no ingresada." << RESET <<endl;
        cout << "Descripcion del producto: ";
        getline(cin, description);
    }
}
void dateProduct::askID() {
    while (true) {
        cout << "ID del producto: ";
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
void dateProduct::askPrice() {
    while (true) {
        cout << "Precio del producto: ";
        if (!(cin >> price)) {
            cout << RED << "ERROR: El precio debe ser un numero." << RESET <<endl;
            cin.clear();
            cin.ignore(1000, '\n');
        } else if (price < 0) {
            cout << RED << "ERROR: El precio no puede ser negativo." << RESET <<endl;
        } else {
            break;
        }
    }
}
void dateProduct::askStock() {
    while (true) {
        cout << "Cantidad en stock: ";
        if (!(cin >> stock)) {
            cout << RED << "ERROR: El stock debe ser un numero entero." << RESET <<endl;
            cin.clear();
            cin.ignore(1000, '\n');
        } else if (stock < 0) {
            cout << RED << "ERROR: El stock no puede ser negativo." << RESET <<endl;
        } else {
            break;
        }
    }
}
void dateProduct::sumaryProducto() {
    cout <<"╔═════════════════════════════════╗"<<endl;
    cout <<"║  "<< GREEN <<"La informacion registrada es:  "<< RESET <<"║"<<endl;
    cout <<"╚═════════════════════════════════╝"<<endl;
    cout << "Nombre del producto: " << name <<endl;
    cout << "Descripcion del producto: " << description <<endl;
    cout << "ID del producto: " << id <<endl;
    cout << "Precio del producto: " << price <<endl;
    cout << "Cantidad en stock: " << stock <<endl;
}
void createProduct(vector<dateProduct> &products) {
    cin.ignore(1000, '\n');
    dateProduct newProduct;
    newProduct.askName();
    newProduct.askDescription();
    newProduct.askID();
    newProduct.askPrice();
    newProduct.askStock();
    newProduct.sumaryProducto();

    bool validOption = false;
    do{
        cout << "¿Desea guardar este producto? \n 1. Si \n 2. No \n 3. volver a ingresar datos \n";
        int confirmSave;
        if (!(cin >> confirmSave)) { 
                cout << RED << "ERROR: Ingrese un numero valido." << RESET << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                cout<<CLEAR;
                continue; 
            }
        if (confirmSave == 1)  
        {
            products.push_back(newProduct);
            cout << GREEN << "Producto guardado exitosamente." << RESET <<endl;
            validOption = true;
        }
        else if (confirmSave == 2) {
            cout << YELLOW << "Producto no guardado." << RESET <<endl;
            cout << "Presione Enter para continuar...";
            cin.ignore(1000, '\n');
            cin.get();
            cout << CLEAR;
            validOption = true;
        }
        else if (confirmSave == 3) {
            cout << YELLOW << "Reingresa los datos del producto." << RESET <<endl;
            cout << "Presione Enter para continuar...";
            cin.ignore(1000, '\n');
            cin.get();
            cout << CLEAR;
            validOption = true;
        }
        else {
            cout << RED << "Opción no válida. Producto no guardado." << RESET <<endl;
            cout << "Presione Enter para continuar...";
            cin.ignore(1000, '\n');
        }
        cin.get();
        cout << CLEAR;

    }while (!validOption);
}
