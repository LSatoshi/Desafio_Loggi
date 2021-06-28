#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <bits/stdc++.h>
#include "barcode.h"

using namespace std;

vector<BarCode> codeDataBase;
vector<Seller> sellersDataBase;


BarCode GetInputCode() {
    string input;
    BarCode barCode;

    cout << "Insira o codigo de barras:\n";
    cin >> input;

    for(int i = 0; i < 5; i++) {
        barCode.code[i] = input.substr(i*3, 3);
    }

    return barCode;
}


bool VerifyValidCode(BarCode input) {
    if(IsInList(input.code[0]) && IsInList(input.code[1]) && IsInList(input.code[4])) {
        //hardcoded barcode restrictions
        if(input.code[0].compare("111") == 0 && input.code[4].compare("000") == 0) return false;
        if(input.code[3].compare("584") == 0) return false;
        return true;
    }
    return false;
}


bool IsInList(string triplet) {
    string list[5] = {"000", "111", "333", "555", "888"};
    for(int i = 0; i < 5; i++) {
        if(triplet.compare(list[i]) == 0) return true;
    }
    return false;
}


void AddCodeToDataBase(BarCode inputCode) {
    codeDataBase.push_back(inputCode);
    AddProductToSeller(inputCode.code[3]);
    return;
}

void AddProductToSeller(string code) {
    for(int i = 0; i < sellersDataBase.size(); i++) {
        if(sellersDataBase[i].code.compare(code) == 0) {
            sellersDataBase[i].sentPackages++;
            return;
        }
    }
    AddNewSellerToDataBase(code);
}

void AddNewSellerToDataBase(string code) {
    Seller seller;
    seller.code = code;
    seller.sentPackages = 1;
    sellersDataBase.push_back(seller);
}


void ListAllSellers() {
    for(Seller s : sellersDataBase) {
        PrintSeller(s);
    }
}

//Funcoes utilizadas para ordenacao do Vector
bool CompareOrigin(BarCode code1, BarCode code2) {
    return (code1.code[0].compare(code2.code[0]) < 0);
}
bool CompareDestination(BarCode code1, BarCode code2) {
    return (code1.code[1].compare(code2.code[1]) < 0);
}
bool CompareProductType(BarCode code1, BarCode code2) {
    return (code1.code[4].compare(code2.code[4]) < 0);
}


void ListCodesByDestination() {
    sort(codeDataBase.begin(), codeDataBase.end(), CompareDestination);

    string currDest;

    currDest = codeDataBase[0].code[1];
    cout << GetRegion(currDest) << "\n";

    for(BarCode code : codeDataBase) {
        if(currDest.compare(code.code[1]) != 0) {
            currDest = code.code[1];
            cout << GetRegion(currDest) << "\n";
        }
        PrintCodeData(code);
    }
}

void ListCodesByDestinationAndProduct() {
    sort(codeDataBase.begin(), codeDataBase.end(), CompareDestination);
    sort(codeDataBase.begin(), codeDataBase.end(), CompareProductType);

    string currDest, currProd;

    currDest = codeDataBase[0].code[1];
    currProd = codeDataBase[0].code[4];

    cout << "\n" << GetRegion(currDest) << "\n";
    cout << GetProductType(currProd) << "\n";

    for(BarCode code : codeDataBase) {
        if(currDest.compare(code.code[1]) != 0) {
            currDest = code.code[1];
            cout << "\n" << GetRegion(currDest) << "\n";
            cout << GetProductType(currProd) << "\n";
        }
        if(currProd.compare(code.code[4]) != 0) {
            currProd = code.code[4];
            cout << "\n" << GetRegion(currDest) << "\n";
            cout << GetProductType(currProd) << "\n";
        }

        PrintCodeData(code);
    }
}


BarCode GetFilterCode() {
    BarCode filterCode;
    int option = 0;
    for(int i = 0; i < 5; i++) filterCode.code[i] = "null";

    while(option != -1) {
        PrintfFilterOptions();
        cin >> option;
        if(option > -1 && option < 5) {
            cout << "Insira o codigo:\n";
            cin >> filterCode.code[option];
        };
    }
    return filterCode;
}

void SearchCode(BarCode filterCode) {
    int i;
    for(BarCode code : codeDataBase) {
        for(i = 0; i < 5; i++) {
            //verifica se tem um filtro para comparar e se o codigo nao e igual
            if(filterCode.code[i].compare("null") != 0 && filterCode.code[i].compare(code.code[i]) != 0) break;
        }
        //Caso termine o for completo, o codigo foi encontrado
        if(i == 5) {
            cout << "Codigo encontrado:\n";
            PrintCodeData(code);
            return;
        }
    }
    cout << "Codigo nao encontrado:\n";
}