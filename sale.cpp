#include <iostream>
#include "UI.h"
#include "pos.h"
#include "sale.h"
#include "createProduct.h"
#include "createClient.h"
void sale::askClient(const std::vector<data> &clients) {
    int seleccion = -1;
    int tipo;
    double searchId;
    std::string searchName;
    std::vector<int>matchIndices;
    bool validOption = false;
    std::cout <<"buscar cliente por [1] nombre [2] ID \n ";
    if(!(std::cin>>tipo))
    {
        std::cout << RED << "ERROR: Ingrese un numero valido." << RESET << std::endl;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        return; 
    }
    if(tipo==2){
        std::cout << "\nIngrese el ID del cliente: ";
        std::cin >> searchId;
         for (size_t i = 0; i < clients.size(); ++i) {
            if (clients[i].id == searchId) {
                matchIndices.push_back(i);
                std::cout << "[" << matchIndices.size() << "] " 
                          << "Nombre: " << clients[i].name
                          << " | ID: " << clients[i].id << "\n";
            }
        }
        if (matchIndices.empty()) {
            std::cout << "No se encontraron coincidencias. Intente de nuevo.\n";
            return;
        }
    }
    else
    do {
        std::cout << "\nIngrese el nombre (o parte del nombre) del cliente(primera letra en mayuscula) : ";
        std::getline(std::cin >> std::ws, searchName); 
        std::cout << "\n--- Resultados de busqueda ---\n";
        
        for (size_t i = 0; i < clients.size(); ++i) {
            if (clients[i].name.find(searchName) != std::string::npos) {
                matchIndices.push_back(i);
                std::cout << "[" << matchIndices.size() << "] " 
                          << "Nombre: " << clients[i].name
                          << " | ID: " << clients[i].id << "\n";
            }
        }

        if (matchIndices.empty()) {
            std::cout << "No se encontraron coincidencias. Intente de nuevo.\n";
            continue;
        }

        std::cout << "\nSeleccione el cliente el numero de cliente [1 - " << matchIndices.size() << "] o [0] para omitir: ";
        if (!(std::cin >> seleccion)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }

        if (seleccion > 0 && seleccion <= static_cast<int>(matchIndices.size())) {
            int indiceReal = matchIndices[seleccion - 1];
            client = clients[indiceReal];
            std::cout << "Cliente '" << client.name << "' seleccionado.\n";
            validOption = true;
        } else if (seleccion == 0) {
            std::cout << "Continuando con cliente por defecto.\n";
            client = clients[0];
            validOption = true;
        } else {
            std::cout << "Opcion invalida.\n";
        }

    } while (!validOption);

}
void saleItem::askProducts(const std::vector<dataProduct> &products) {
    int seleccion = 0;
    double searchId;
    std::string searchName;
    std::vector<int> matchIndices;
    bool productSelected = false;
    std::cout <<"Buscar producto por [1] nombre [2] ID \n ";
    int tipo;
    if(!(std::cin>>tipo))
    {
        std::cout << RED << "ERROR: Ingrese un numero valido." << RESET << std::endl;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        return; 
    }
    if(tipo==2){
        
        std::cout << "\nIngrese el ID del producto: ";
        std::cin >> searchId;
         for (size_t i = 0; i < products.size(); ++i) {
            if (products[i].id == searchId) {
                product = products[i];
                std::cout << "Producto '" << product.name << "' seleccionado.\n";
                productSelected = true;
                break;
            }
        }
        if (!productSelected) {
            std::cout << "No se encontraron productos con ese ID.\n";
            return;
        }
    }
    else
    do {
        std::cout << "\nIngrese el nombre del producto a buscar: ";
        std::getline(std::cin >> std::ws, searchName); 
        std::cout << "\n--- Resultados de busqueda ---\n";
        
        for (size_t i = 0; i < products.size(); ++i) {
            if (products[i].name.find(searchName) != std::string::npos) {
                matchIndices.push_back(i);
                std::cout << "[" << matchIndices.size() << "] " 
                          << "Nombre: " << products[i].name
                          << " | Stock: " << products[i].stock
                          << " | Precio: " << products[i].price << "\n";
            }
        }

        if (matchIndices.empty()) {
            std::cout << "No se encontraron productos con ese nombre.\n";
            continue; 
        }

        std::cout << "\nSeleccione el numero [1-" << matchIndices.size() << "] o [0] para buscar de nuevo: ";
        if (!(std::cin >> seleccion)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }

        if (seleccion > 0 && seleccion <= static_cast<int>(matchIndices.size())) {
            int indiceReal = matchIndices[seleccion - 1];
            product = products[indiceReal];
            std::cout << "Seleccionado: " << product.name << "\n";
            productSelected = true;
        } else if (seleccion != 0) {
            std::cout << "Opcion fuera de rango.\n";
        }

    } while (!productSelected);

    askQuantity();
}
void saleItem::askQuantity() {
    do {
        std::cout << "Ingrese la cantidad a comprar: ";
        if (!(std::cin >> quantity)) {
            std::cout << "Entrada invalida. Ingrese un numero.\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        } else if (quantity <= 0) {
            std::cout << "La cantidad debe ser mayor a cero.\n";
        } else if (quantity > product.stock) {
            std::cout << "No hay suficiente stock disponible. Stock actual: " << product.stock << "\n";
        } else {
            break;
        }
    } while (true);
    calculateSubTotalPrice();
}
void saleItem::calculateSubTotalPrice() {
    subTotalPrice = quantity * product.price;
}
void sale::calculateTotalPrice() {
    totalPrice = 0;
    for (const auto& item : items) {
        totalPrice += item.subTotalPrice;
    }
}
void sale::summarySale() {
    std::cout << CLEAR;
    std::cout <<"╔══════════════════════════════════════════╗"<<std::endl;
    std::cout <<"║ "<<BLUE"  RESUMEN DE LA VENTA "<<RESET"              ║"<<std::endl;
    std::cout <<"╚══════════════════════════════════════════╝"<<std::endl;
    std::cout << "Cliente: " << client.name << " " << client.lastName << "\n";
    std::cout << "ID del cliente: " << client.id << "\n";
    std::cout << "Productos comprados:\n";
    for (const auto& item : items) {
        std::cout << "- " << item.product.name 
                  << " | Cantidad: " << item.quantity 
                  << " | Precio unitario: " << item.product.price 
                  << " | Subtotal: " << item.subTotalPrice << "\n";
    }
}
void saleProcess(std::vector<dataProduct> &products , const std::vector<data> &clients, std::vector<sale> &sales) {
    std::cout <<CLEAR;
    sale newSale;
    newSale.askClient(clients);
    bool moreProducts = true;
    do{
        std::cout << "¿Desea agregar un producto? \n 1. Si \n 2. No \n";
        int addProduct;
        if (!(std::cin >> addProduct)) { 
                std::cout << RED << "ERROR: Ingrese un numero valido." << RESET << std::endl;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout<<CLEAR;
                continue; 
            }
        if (addProduct == 1)  
        {
            saleItem newItem;
            newItem.askProducts(products);
            newSale.items.push_back(newItem);
        }
        else if (addProduct == 2) {
            std::cout << CLEAR;
            break;
        }
        else {
            std::cout << RED << "Opción no válida. Intente de nuevo." << RESET <<std::endl;
            std::cout << "Presione Enter para continuar...";
            std::cin.ignore(1000, '\n');
            std::cin.get();
            std::cout << CLEAR;
        }
    }while (moreProducts);
    //comfimar venta
    int confirmSale;
    newSale.summarySale();
    do{
        std::cout << "¿Desea confirmar esta venta? \n 1. Si \n 2. No \n";
        if (!(std::cin >> confirmSale)) { 
                std::cout << RED << "ERROR: Ingrese un numero valido." << RESET << std::endl;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout<<CLEAR;
                return; 
            }
        if (confirmSale == 1)
        {
            newSale.calculateTotalPrice();
            std::cout << GREEN << "Venta confirmada. Total a pagar: " << newSale.totalPrice << RESET <<std::endl;
            for (auto& item : newSale.items) {
                for (auto& product : products) {
                    if (product.id == item.product.id) {
                        product.stock -= item.quantity;
                        break;
                    }
                }
            }
        }
        else if (confirmSale == 2) {
            std::cout << YELLOW << "Venta cancelada." << RESET <<std::endl;
            std::cout << "Presione Enter para continuar...";
            std::cin.ignore(1000, '\n');
            std::cin.get();
            std::cout << CLEAR;
            return;
        }
        else {
            std::cout << RED << "Opción no válida. Venta no confirmada." << RESET <<std::endl;
            std::cout << "Presione Enter para continuar...";
            std::cin.ignore(1000, '\n');
            std::cin.get();
            std::cout << CLEAR;
            return;
        }
    }while (confirmSale != 1 && confirmSale != 2);

    sales.push_back(newSale);

}