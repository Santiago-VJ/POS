#include <iostream>
#include "saveData.h"
#include "UI.h"

void saveData(std::vector<data> &clients ,std::vector<dataProduct> &products, std::vector<sale> &sales) {
    //clientes
    std::ofstream clientFile("clientsCSV.txt");
    if (!clientFile.is_open()) {
         std::cout<<RED<<"Error al abrir el archivo para guardar los datos."<<RESET<< std::endl;
        return;
    }
    for (const auto& client : clients) {
        clientFile << client.name << "," 
             << client.lastName << "," 
             << client.id << "," 
             << client.age << "," 
             << client.phoneNumber << "," 
             << client.email << "," 
             << client.address << std::endl;
    }
    clientFile.close();
    std::cout << GREEN << "Datos guardados exitosamente en clientsCVS.txt" << RESET << std::endl;
    //productos
    std::ofstream productFile("productsCSV.txt");
    if (!productFile.is_open()) {
            std::cout<<RED<<"Error al abrir el archivo para guardar los datos."<<RESET<< std::endl;
            return;
        }
    for (const auto& product : products) {
        productFile << product.name << "," 
             << product.description << "," 
             << product.id << "," 
             << product.price << "," 
             << product.stock << std::endl;
    }
    productFile.close();
    std::cout << GREEN << "Datos guardados exitosamente en productsCSV.txt" << RESET << std::endl;
    //ventas
    std::ofstream salesFile("salesCSV.txt");
    if (!salesFile.is_open()) {
            std::cout<<RED<<"Error al abrir el archivo para guardar los datos."<<RESET<< std::endl;
            return;
        }
    for (const auto& sale : sales) {
        salesFile << sale.client.name << "," 
             << sale.client.lastName << "," 
             << sale.client.id << "," 
             << sale.client.age << "," 
             << sale.client.phoneNumber << "," 
             << sale.client.email << "," 
             << sale.client.address << ",";
        for (const auto& item : sale.items) {
            salesFile << item.product.name << "|" 
                 << item.product.description << "|" 
                 << item.product.id << "|" 
                 << item.product.price << "|" 
                 << item.product.stock << "|" 
                 << item.quantity << "|"
                 << item.subTotalPrice << ";";
        }
        salesFile << sale.totalPrice;
        salesFile << std::endl;
    }
    salesFile.close();
    std::cout << GREEN << "Datos guardados exitosamente en salesCSV.txt" << RESET << std::endl;
}
