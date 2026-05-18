#ifndef CREATEPRODUCT_H
#define CREATEPRODUCT_H
#include <vector>
#include <string>
struct dataProduct
{
    std::string name;  
    std::string description;   
    long long int id;
    double price;
    int stock;

    void askName();
    void askDescription();
    void askID();
    void askPrice();
    void askStock();
    void sumaryProducto();
};
void createProduct(std::vector<dataProduct> &products);
#endif