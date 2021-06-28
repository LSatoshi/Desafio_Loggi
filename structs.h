#ifndef H_STRUCTS
#define H_STRUCTS

#include <string>

struct _BarCode{
    std::string code[5];
};

struct _Seller{
    std::string code;
    int sentPackages;
};

typedef struct _BarCode BarCode;
typedef struct _Seller Seller;


#endif