#ifndef CONTROLCENTER_H
#define CONTROLCENTER_H
#include "createClient.h"
#include "createProduct.h"
#include "saveData.h"
#include "loadData.h"
#include <vector>

void controlCenter(std::vector<data> &clients, std::vector<dataProduct> &products, std::vector<sale> &sales);
#endif
