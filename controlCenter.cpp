#include <iostream>
#include <vector>
#include "UI.h"
#include "controlCenter.h"
#include "createClient.h"
#include "createProduct.h"


void controlCenter(std::vector<data> &clients, std::vector<dataProduct> &products, std::vector<sale> &sales) {
    int opcion;
    do
    {
        std::cout<<CLEAR;
        std::cout <<"╔══════════════════════════════════════════╗"<<std::endl;
        std::cout <<"║ "<<BLUE"  BIENVENIDO AL CENTRO DE CONTROL "<<RESET"       ║"<<std::endl;
        std::cout <<"║     1.  Registrar nuevo cliente          ║"<<std::endl;
        std::cout <<"║     2.  Registrar nuevo producto         ║"<<std::endl;
        std::cout <<"║     3.  Guardar base de datos            ║"<<std::endl;
        std::cout <<"║     4.  Cargar base de datos             ║"<<std::endl;
        std::cout <<"║     0.  Regresar al menu principal       ║"<<std::endl;
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
                createClients(clients);
                break;  
            case 2:
                createProduct(products);
                break;
            case 3:
                saveData(clients, products, sales);
                break;
            case 4:
                loadData(clients, products, sales);
                break;
            case 0:
                std::cout << YELLOW << "Regresando al centro de control..." << RESET <<std::endl;
                std::cout << "Presione Enter para continuar...";
                std::cin.ignore(1000, '\n');
                std::cin.get();
                std::cout << CLEAR;
                break;
            default:
                std::cout <<BOLD<<RED<<"Opcion no reconocida. Intente de nuevo.\n"<<RESET;
                break;
         }
        }
        
    }while (opcion != 0);	
}