#include <iostream>
#include "UI.h"
#include "createClient.h"
#include "createProduct.h"
#include "saveData.h"
#include "loadData.h"
#include "controlCenter.h"
#include "POS.h"
int main()
{
    std::vector<data> clients;
    std::vector<dataProduct> products;
    std::vector<sale> sales;
    activateUI(); 
    loadData(clients, products, sales);
    std::cout <<"╔══════════════════════════════════════════╗"<<std::endl;
    std::cout <<"║        "<<BLUE<<" BIENVENIDOS AL SITEMA POS        "<<RESET<<"║"<<std::endl;
    std::cout <<"║      DE:SANTIAGO VELASQUEZ JIMENEZ       ║"<<std::endl;
    std::cout <<"╚══════════════════════════════════════════╝"<<std::endl<<std::endl;
    std::cin.get();
    std::cout<<CLEAR;

    int opcion;
    do
    {
    std::cout <<"╔══════════════════════════════════════════╗"<<std::endl;
    std::cout <<"║ "<<BLUE"  INGRESE LA OPCION QUE DESEA REALIZAR "<<RESET"  ║"<<std::endl;
    std::cout <<"║     1.  Centro de control                ║"<<std::endl;
    std::cout <<"║     2.  POS                              ║"<<std::endl;
    std::cout <<"║     0.  salir                            ║"<<std::endl;
    std::cout <<"╚══════════════════════════════════════════╝"<<std::endl;
        if (!(std::cin >> opcion)) {
            std::cout<<CLEAR;
            std::cout <<BOLD<<RED<<"ERROR: Opcion no valida.\n"<<RESET;
            std::cin.clear();
            std::cin.ignore(1000 , '\n');
            continue; 
        }
        else
        {
            switch (opcion)
         {
            case 1:
                controlCenter(clients, products, sales);
                break;  
            case 2:  
                pos(clients, products, sales);
                break;
            default:
                std::cout <<BOLD<<RED<<"Opcion no reconocida. Intente de nuevo.\n"<<RESET;
                break;
         }
        }
        
    }while (opcion != 0);
    saveData(clients, products, sales);	
return 0;
}