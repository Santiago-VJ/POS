#include <iostream>
#include "saveDate.h"
#include "UI.h"

using namespace std;
void saveDate(vector<date> &clients) {
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
}