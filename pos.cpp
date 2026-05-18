#include <iostream>
#include "UI.h"
#include "pos.h"
#include "sale.h"

void pos(std::vector<data> &clients, std::vector<dataProduct> &products ,std::vector<sale> &sales) {
    std::cout <<CLEAR;
    std::cout <<"╔══════════════════════════════════════════╗"<<std::endl;
    std::cout <<"║ "<<BLUE"  BIENVENIDO AL PUNTO DE VENTA "<<RESET"          ║"<<std::endl;
    std::cout <<"║     Aqui podras realizar ventas          ║"<<std::endl;
    std::cout <<"║     y consultar productos                ║"<<std::endl;
    std::cout <<"╚══════════════════════════════════════════╝"<<std::endl<<std::endl;
    std::cin.ignore(1000, '\n');
    std::cin.get();
    std::cout<<CLEAR;
    saleProcess(products, clients, sales);
}