#include <iostream>
#include "createProduct.h"
#include "UI.h"
void dataProduct::askName() {
    std::cout << "Nombre del producto: ";
    std::getline(std::cin, name);
    while (name.empty()) {
        std::cout << RED << "ERROR: Nombre no ingresado." << RESET <<std::endl;
        std::cout << "Nombre del producto: ";
        std::getline(std::cin, name);
    }
}
void dataProduct::askDescription() {
    std::cout << "Descripcion del producto: ";
    std::getline(std::cin, description);
    while (description.empty()) {
        std::cout << RED << "ERROR: Descripcion no ingresada." << RESET <<std::endl;
        std::cout << "Descripcion del producto: ";
        std::getline(std::cin, description);
    }
}
void dataProduct::askID() {
    while (true) {
        std::cout << "ID del producto: ";
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
void dataProduct::askPrice() {
    while (true) {
        std::cout << "Precio del producto: ";
        if (!(std::cin >> price)) {
            std::cout << RED << "ERROR: El precio debe ser un numero." << RESET <<std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        } else if (price < 0) {
            std::cout << RED << "ERROR: El precio no puede ser negativo." << RESET <<std::endl;
        } else {
            break;
        }
    }
}
void dataProduct::askStock() {
    while (true) {
        std::cout << "Cantidad en stock: ";
        if (!(std::cin >> stock)) {
            std::cout << RED << "ERROR: El stock debe ser un numero entero." << RESET <<std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        } else if (stock < 0) {
            std::cout << RED << "ERROR: El stock no puede ser negativo." << RESET <<std::endl;
        } else {
            break;
        }
    }
}
void dataProduct::sumaryProducto() {
    std::cout<<CLEAR;
    std::cout <<"╔═════════════════════════════════╗"<<std::endl;
    std::cout <<"║  "<< GREEN <<"La informacion registrada es:  "<< RESET <<"║"<<std::endl;
    std::cout <<"╚═════════════════════════════════╝"<<std::endl;
    std::cout << "Nombre del producto: " << name <<std::endl;
    std::cout << "Descripcion del producto: " << description <<std::endl;
    std::cout << "ID del producto: " << id <<std::endl;
    std::cout << "Precio del producto: " << price <<std::endl;
    std::cout << "Cantidad en stock: " << stock <<std::endl;
}
void createProduct(std::vector<dataProduct> &products) {
    std::cin.ignore(1000, '\n');
    std::cout<<CLEAR;
    std::cout <<"╔══════════════════════════════════════════╗"<<std::endl;
    std::cout <<"║   "<< BLUE <<"INGRESO DE DATOS PARA NUEVO PRODUCTO "<< RESET <<"║"<<std::endl;
    std::cout <<"╚══════════════════════════════════════════╝"<<std::endl;
    dataProduct newProduct;
    newProduct.askName();
    newProduct.askDescription();
    newProduct.askID();
    newProduct.askPrice();
    newProduct.askStock();
    newProduct.sumaryProducto();

    bool validOption = false;
    do{
        std::cout << "¿Desea guardar este producto? \n 1. Si \n 2. No \n 3. volver a ingresar datos \n";
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
            products.push_back(newProduct);
            std::cout << GREEN << "Producto guardado exitosamente." << RESET <<std::endl;
            validOption = true;
        }
        else if (confirmSave == 2) {
            std::cout << YELLOW << "Producto no guardado." << RESET <<std::endl;
            std::cout << "Presione Enter para continuar...";
            std::cin.ignore(1000, '\n');
            std::cin.get();
            std::cout << CLEAR;
            validOption = true;
        }
        else if (confirmSave == 3) {
            std::cout << YELLOW << "Reingresa los datos del producto." << RESET <<std::endl;
            std::cout << "Presione Enter para continuar...";
            std::cin.ignore(1000, '\n');
            std::cin.get();
            std::cout << CLEAR;
            validOption = true;
        }
        else {
            std::cout << RED << "Opción no válida. Producto no guardado." << RESET <<std::endl;
            std::cout << "Presione Enter para continuar...";
            std::cin.ignore(1000, '\n');
        }
        std::cin.get();
        std::cout << CLEAR;

    }while (!validOption);
}
