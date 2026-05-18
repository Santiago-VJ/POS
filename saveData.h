#ifndef SAVEDATA_H
#define SAVEDATA_H

#include <fstream>
#include "createClient.h"
#include "createProduct.h"
#include "sale.h"
void saveData(std::vector<data> &personas, std::vector<dataProduct> &products, std::vector<sale> &sales);

#endif


