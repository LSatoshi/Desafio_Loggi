#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include "ui.h"

using namespace std;


void PrintOptions() {
    cout << "\nLeitor de codigo de barras Entre o comando desejado:" << "\n";
    cout << "  1 - Inserir novo codigo;\n  2 - Buscar codigo;\n  3 - Listar codigos por destino;\n  4 - Listar codigos por destino e produto;\n  5 - Listar vendedores;\n -1 - fechar programa." << "\n";
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
    cout << "\nRegiao de Origem: " << GetRegion(bar.code[0]) << "\n";
    cout << "Regiao de Destino: " << GetRegion(bar.code[1]) << "\n";
    cout << "Codigo Loggi: " << bar.code[2] << "\n";
    cout << "Codigo do vendedor do produto: " << bar.code[3] << "\n";
    cout << "Tipo do produto: " << GetProductType(bar.code[4]) << "\n";
}

void PrintSeller(Seller seller) {
    cout << "Codigo de venderdor: " << seller.code << "\n";
    cout << "Numero de pacotes enviados: " << seller.sentPackages << "\n\n";
}

void PrintfFilterOptions() {
    cout << "\nSelecione o campo que deseja adicionar um filtro:" << "\n";
    cout << "  0 - Regiao de Origem;\n  1 - Regiao de Destino;\n  2 - Codigo Loggi;\n  3 - Codigo do vendedor;\n  4 - Tipo do produto;\n -1 - Continuar;\n";
}



