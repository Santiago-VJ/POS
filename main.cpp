#include <iostream>
#include <vector>
#include "UI.h"
#include "createClient.h"
using namespace std;
int main()
{
    activateUI(); 
    int opcion;
    vector<date> personas;
    //cover of proyect
    cout <<"╔══════════════════════════════════════════╗"<<endl;
    cout <<"║        "<<BLUE<<" BIENVENIDOS AL SITEMA POS        "<<RESET<<"║"<<endl;
    cout <<"║      DE:SANTIAGO VELASQUEZ JIMENEZ  Y    ║"<<endl;
    cout <<"║      NICOLAS TOVAR GAVIRIA               ║"<<endl;
    cout <<"╚══════════════════════════════════════════╝"<<endl<<endl;
    cin.get();
    cout<<CLEAR;
    while(true)
    {
    cout <<"╔══════════════════════════════════════════╗"<<endl;
    cout <<"║ "<<BLUE"  INGRESE LA OPCION QUE DESEA REALIZAR "<<RESET"  ║"<<endl;
    cout <<"║     1.    Crear cliente                  ║"<<endl;
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
                createClients(personas);
                break;  
            default:
                cout <<BOLD<<RED<<"Opcion no reconocida. Intente de nuevo.\n"<<RESET;
                break;
         }
        }
        
    }	
return 0;
}