#include "loadData.h"
#include "UI.h"
#include "createClient.h"
#include "createProduct.h"
#include "sale.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>


void loadData(std::vector<data> &clients, std::vector<dataProduct> &products, std::vector<sale> &sales) {
    clients.clear();
    products.clear();
    sales.clear();
    std::string line, pos;
    
    std::ifstream fileClients("clientsCSV.txt");
    if (!fileClients.is_open()) {
        std::cout << RED << "Error: No se pudo abrir clientsCSV.txt" << RESET << std::endl;
    } 
    else {
        while (getline(fileClients, line)) {
            if (line.empty()) continue;

            std::stringstream aux(line);
            data clientAux;

            getline(aux, clientAux.name, ',');
            getline(aux, clientAux.lastName, ',');
    
            getline(aux, pos, ',');
            clientAux.id = pos.empty() ? 0 : stoll(pos);

            getline(aux, pos, ',');
            clientAux.age = pos.empty() ? 0 : stoi(pos);

            getline(aux, pos, ',');
            clientAux.phoneNumber = pos.empty() ? 0 : stoll(pos);

            getline(aux, clientAux.email, ',');
            getline(aux, clientAux.address);

            clients.push_back(clientAux);
        }
        fileClients.close();
        std::cout << GREEN << " CLIENTES CARGADOS: " << clients.size() << RESET << std::endl;
    }
    std::ifstream fileProducts("productsCSV.txt");
    if (!fileProducts.is_open()) {
        std::cout << RED << "Error: No se pudo abrir productsCSV.txt" << RESET << std::endl;
    } 
    else {
        while (getline(fileProducts, line)) {
            if (line.empty()) continue;

            std::stringstream aux(line);
            dataProduct productAux;

            getline(aux, productAux.name, ',');
            getline(aux, productAux.description, ',');
    
            getline(aux, pos, ',');
            productAux.id = pos.empty() ? 0 : stoll(pos);

            getline(aux, pos, ',');
            productAux.price = pos.empty() ? 1 : stod(pos);

            getline(aux, pos);
            productAux.stock = pos.empty() ? 0 : stoi(pos);

            products.push_back(productAux);
        }
        fileProducts.close();
        std::cout << GREEN << " PRODUCTOS CARGADOS: " << products.size() << RESET << std::endl;
    }
    std::ifstream fileSales("salesCSV.txt");
    if (!fileSales.is_open()) {
        std::cout << RED << "Error: No se pudo abrir salesCSV.txt" << RESET << std::endl;
    } 
    else {
        while (getline(fileSales, line)) {
            if (line.empty()) continue;

            std::stringstream aux(line);
            sale saleAux;

            // Load client data
            getline(aux, saleAux.client.name, ',');
            getline(aux, saleAux.client.lastName, ',');
    
            getline(aux, pos, ',');
            saleAux.client.id = pos.empty() ? 0 : stoll(pos);

            getline(aux, pos, ',');
            saleAux.client.age = pos.empty() ? 0 : stoi(pos);

            getline(aux, pos, ',');
            saleAux.client.phoneNumber = pos.empty() ? 0 : stoll(pos);

            getline(aux, saleAux.client.email, ',');
            getline(aux, saleAux.client.address);

            // Load product items and quantities
            std::string itemLine;
            while (getline(aux, itemLine, ';')) {
                if (itemLine.empty()) continue;

                std::stringstream itemStream(itemLine);
                dataProduct product;
                int quantity;
                double subTotalPrice;

                getline(itemStream, product.name, '|');
                getline(itemStream, product.description, '|');
    
                getline(itemStream, pos, '|');
                product.id = pos.empty() ? 0 : stoll(pos);

                getline(itemStream, pos, '|');
                product.price = pos.empty() ? 1 : stod(pos);

                getline(itemStream, pos, '|');
                product.stock = pos.empty() ? 0 : stoi(pos);

                getline(itemStream, pos, '|');
                quantity = pos.empty() ? 0 : stoi(pos);

                getline(itemStream, pos);
                subTotalPrice = pos.empty() ? 0 : stod(pos);

                saleAux.items.push_back({product, quantity});
                saleAux.totalPrice += subTotalPrice;
            }

            sales.push_back(saleAux);
        }
        fileSales.close();
        std::cout << GREEN << " VENTAS CARGADAS: " << sales.size() << RESET << std::endl;
    }
    std::cout << "\nPresiona Enter para continuar...";
    std::cin.get();
    std::cout << CLEAR;
}