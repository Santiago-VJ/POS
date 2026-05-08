#include <iostream>
#include "UI.h"
#include "createClient.h"
#include "createProduct.h"
#include "saveDate.h"
#include "loadDate.h"
using namespace std;
int main()
{
    vector<date> clients;
    vector<dateProduct> products;

    activateUI(); 
    cout <<"╔══════════════════════════════════════════╗"<<endl;
    cout <<"║        "<<BLUE<<" BIENVENIDOS AL SITEMA POS        "<<RESET<<"║"<<endl;
    cout <<"║      DE:SANTIAGO VELASQUEZ JIMENEZ       ║"<<endl;
    cout <<"╚══════════════════════════════════════════╝"<<endl<<endl;
    cin.get();
    cout<<CLEAR;

    int opcion;
    while(true)
    {
    cout <<"╔══════════════════════════════════════════╗"<<endl;
    cout <<"║ "<<BLUE"  INGRESE LA OPCION QUE DESEA REALIZAR "<<RESET"  ║"<<endl;
    cout <<"║     1.  Registrar nuevo cliente          ║"<<endl;
    cout <<"║     2.  Registrar nuevo producto         ║"<<endl;
    cout <<"║     3.  Guardar base de datos            ║"<<endl;
    cout <<"║     4.  Cargar base de datos             ║"<<endl;
    cout <<"╚══════════════════════════════════════════╝"<<endl;
        if (!(cin >> opcion)) {
            cout<<CLEAR;
            cout <<BOLD<<RED<<"ERROR: Opcion no valida.\n"<<RESET;
            cin.clear();
            cin.ignore(1000 , '\n');
            continue; 
        }
        else
        {
            switch (opcion)
         {
            case 1:
                createClients(clients);
                break;  
            case 2:
                createProduct(products);
                break;
            case 3:
                saveDate(clients, products);
                break;
            case 4:
                loadDate(clients, products);
                break;
            default:
                cout <<BOLD<<RED<<"Opcion no reconocida. Intente de nuevo.\n"<<RESET;
                break;
         }
        }
        
    }	
return 0;
}