#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include "barcode.h"

using namespace std;

vector<BarCode> dataBase;

void PrintOptions() {
    cout << "\nLeitor de codigo de barras\n Entre o comando desejado:\n  1 - Inserir novo codigo;\n  2 - Filtrar codigos;\n -1 - fechar programa.\n";
}

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
    dataBase.push_back(inputCode);
    return;
}

string GetRegion(string triplet) {
    if(triplet.compare("111") == 0) return("Centro-Oeste");
    if(triplet.compare("333") == 0) return("Nordeste");
    if(triplet.compare("555") == 0) return("Norte");
    if(triplet.compare("888") == 0) return("Sudeste");
    if(triplet.compare("000") == 0) return("Sul");
    return("ERROR");
}

string GetProductType(string triplet) {
    if(triplet.compare("111") == 0) return("Livros");
    if(triplet.compare("333") == 0) return("Eletronicos");
    if(triplet.compare("555") == 0) return("Bebidas");
    if(triplet.compare("888") == 0) return("Brinquedos");
    if(triplet.compare("000") == 0) return("Joias");
    return("ERROR");
}

void PrintCodeData(BarCode bar) {
    cout << "Codigo: ";
    for(int i = 0; i < 5; i++) cout << bar.code[i] << " ";
    cout << "\nRegiao de Origem: " << GetRegion(bar.code[0]) << endl;
    cout << "Regiao de Destino: " << GetRegion(bar.code[1]) << endl;
    cout << "Codigo Loggi: " << bar.code[2] << endl;
    cout << "Codigo do vendedor do produto: " << bar.code[3] << endl;
    cout << "Tipo do produto: " << GetProductType(bar.code[4]) << endl;
}

void TestPrint() {
    for (BarCode barcode : dataBase) {
        cout << barcode.code[0] << endl;
    }
}
