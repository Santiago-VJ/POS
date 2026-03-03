#include "loadDate.h"
#include "UI.h"
#include "createClient.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void loadDate(vector<date> &clients) {
    clients.clear();
    string line, pos;
    
    ifstream fileClients("clientsCSV.txt");
    if (!fileClients.is_open()) {
        cout << RED << "Error: No se pudo abrir clientsCSV.txt" << RESET << endl;
    } 
    else {
        while (getline(fileClients, line)) {
            if (line.empty()) continue;

            stringstream aux(line);
            date clientAux;

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
        cout << GREEN << " CLIENTES CARGADOS: " << clients.size() << RESET << endl;
    }

    cout << "\nPresiona Enter para continuar...";
    cin.ignore(1000, '\n');
    cin.get();
    cout << CLEAR;
}