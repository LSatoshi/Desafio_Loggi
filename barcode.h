#ifndef H_ESCREVERNATELA_
#define H_ESCREVERNATELA_

#include <string>

#define INSERTCODE 1
#define FILTERCODES 2
#define CLOSE -1

struct _BarCode{
    std::string code[5];
};

typedef struct _BarCode BarCode;

BarCode GetInputCode();
void PrintOptions();
bool VerifyValidCode(BarCode input);
bool IsInList(std::string triplet);
void AddCodeToDataBase(BarCode inputCode);
void PrintCodeData(BarCode inputCode);
void TestPrint();

#endif