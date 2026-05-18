#ifndef SALE_H
#define SALE_H
#include <string>
#include <vector>
#include "createClient.h"
#include "createProduct.h"
struct saleItem{
    dataProduct product;
    int quantity;
    double subTotalPrice;
    void askProducts(const std::vector<dataProduct> &products);
    void askQuantity();
    void calculateSubTotalPrice();

};
struct sale {
    data client;
    std::vector<saleItem> items;
    double totalPrice;

    void askClient(const std::vector<data> &clients);
    void calculateTotalPrice();
    void summarySale();
};
void saleProcess(std::vector<dataProduct> &products , const std::vector<data> &clients, std::vector<sale> &sales);
#endif