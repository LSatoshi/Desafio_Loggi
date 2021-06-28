#ifndef H_UI
#define H_UI

#include <string>
#include "structs.h"


void PrintOptions();
std::string GetRegion(std::string triplet);
std::string GetProductType(std::string triplet);
void PrintCodeData(BarCode inputCode);
void PrintSeller(Seller seller);
void PrintfFilterOptions();


#endif