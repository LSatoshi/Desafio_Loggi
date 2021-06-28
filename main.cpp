#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "barcode.h"


using namespace std;


int main() {
    int option = 0;
    BarCode inputCode, filterCode;

    while(option != -1) {
        PrintOptions();
        cin >> option;

        switch(option) {
            case INSERTCODE:
                inputCode = GetInputCode();
                if(VerifyValidCode(inputCode)) {
                    AddCodeToDataBase(inputCode);
                    PrintCodeData(inputCode);
                    cout << "Codigo validado e armazenado com sucesso!\n";
                }else {
                    cout << "Codigo invalido!\n";
                }
                break;

            case SEARCHCODE:
                filterCode = GetFilterCode();
                SearchCode(filterCode);
                break;

            case LISTCODESDEST:
                ListCodesByDestination();
                break;

            case LISTCODESDESTPROD:
                ListCodesByDestinationAndProduct();
                break;

            case LISTSELLERS:
                cout << "Lista de vendedores e produtos enviados: \n";
                ListAllSellers();
                break;

            case CLOSE:
                cout << "Finalizando programa\n";
                break;

            default:
                cout << "Opcao invalida\n";
                break;
        }
    }
    return 0;
}
