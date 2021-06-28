#ifndef H_BARCODE
#define H_BARCODE

#include <string>
#include "ui.h"

#define INSERTCODE 1
#define SEARCHCODE 2
#define LISTCODESDEST 3
#define LISTCODESDESTPROD 4
#define LISTSELLERS 5
#define CLOSE -1


BarCode GetInputCode();
bool VerifyValidCode(BarCode input);
bool IsInList(std::string triplet);
void AddCodeToDataBase(BarCode inputCode);
void AddProductToSeller(std::string code);
void AddNewSellerToDataBase(std::string code);
void ListAllSellers();
void ListCodesByDestinationAndProduct();
void ListCodesByDestination();
BarCode GetFilterCode();
void SearchCode(BarCode filterCode);


#endif