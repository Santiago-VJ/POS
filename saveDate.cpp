#include <iostream>
#include "saveDate.h"
#include "UI.h"

using namespace std;
void saveDate(vector<date> &clients ,vector<dateProduct> &products) {
    //clientes
    ofstream clientFile("clientsCSV.txt");
    if (!clientFile.is_open()) {
         cout<<RED<<"Error al abrir el archivo para guardar los datos."<<RESET<< endl;
        return;
    }
    for (const auto& client : clients) {
        clientFile << client.name << "," 
             << client.lastName << "," 
             << client.id << "," 
             << client.age << "," 
             << client.phoneNumber << "," 
             << client.email << "," 
             << client.address << endl;
    }
    clientFile.close();
    cout << GREEN << "Datos guardados exitosamente en clientsCVS.txt" << RESET << endl;
    //productos
    ofstream productFile("productsCSV.txt");
    if (!productFile.is_open()) {
            cout<<RED<<"Error al abrir el archivo para guardar los datos."<<RESET<< endl;
            return;
        }
    for (const auto& product : products) {
        productFile << product.name << "," 
             << product.description << "," 
             << product.id << "," 
             << product.price << "," 
             << product.stock << endl;
    }
    productFile.close();
    cout << GREEN << "Datos guardados exitosamente en productsCSV.txt" << RESET << endl;
}
