#include <iostream>
#include "UI.h"
#include "createClient.h"
#include "saveDate.h"
#include "loadDate.h"
using namespace std;
int main()
{
    vector<date> clients;

    activateUI(); 
    cout <<"╔══════════════════════════════════════════╗"<<endl;
    cout <<"║        "<<BLUE<<" BIENVENIDOS AL SITEMA POS        "<<RESET<<"║"<<endl;
    cout <<"║      DE:SANTIAGO VELASQUEZ JIMENEZ  Y    ║"<<endl;
    cout <<"║      NICOLAS TOVAR GAVIRIA               ║"<<endl;
    cout <<"╚══════════════════════════════════════════╝"<<endl<<endl;
    cin.get();
    cout<<CLEAR;

    int opcion;
    while(true)
    {
    cout <<"╔══════════════════════════════════════════╗"<<endl;
    cout <<"║ "<<BLUE"  INGRESE LA OPCION QUE DESEA REALIZAR "<<RESET"  ║"<<endl;
    cout <<"║     1.  Registrar nuevo cliente          ║"<<endl;
    cout <<"║     2.  Guardar base de datos            ║"<<endl;
    cout <<"║     3.  Cargar base de datos             ║"<<endl;
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
                saveDate(clients);
                break;
            case 3:
                loadDate(clients);
                break;
            default:
                cout <<BOLD<<RED<<"Opcion no reconocida. Intente de nuevo.\n"<<RESET;
                break;
         }
        }
        
    }	
return 0;
}