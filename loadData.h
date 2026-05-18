#ifndef LOADDATA_H
#define LOADDATA_H

#include <fstream>
#include "createClient.h"
#include "createProduct.h"
#include "sale.h"

void loadData(std::vector<data> &clients , std::vector<dataProduct> &products, std::vector<sale> &sales);

#endif
