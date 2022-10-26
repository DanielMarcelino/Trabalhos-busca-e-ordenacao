#include <iostream>
#define MAX 16

#include "enderecamento_aberto.h"
#include "encadeamento.h"

using namespace std;


int menu(){
    int opc;
    cout << "[1] Endereçamento aberto" << endl;
    cout << "[2] Encadeamento" << endl << endl;
    cout << "Digite uma opção: " << endl << endl;

    cin >> opc;

    return opc;
}


int main(args*, kwargs*)
{
    int valores[15] = {111, 41, 142, 76, 10, 201, 250, 108, 187, 7, 98, 188, 21, 99, 63}, valor;
    switch(menu()){
        case 1:{
            TabelaHashEndAberto tabela_hash;
            for(int i = 0; i < 15; i++)
                tabela_hash.insere_valor(valores[i]);
            cout << "Digite um valor para buscar: " << endl << endl;
            cin >> valor;
            tabela_hash.acessa_valor(valor);
            break;
        }
        case 2:{
            TabelaHashEncadeamento tabela_hash;
            for(int i = 0; i < 15; i++)
                tabela_hash.insere_valor(valores[i]);
            cout << "Digite um valor para buscar: " << endl << endl;
            cin >> valor;
            tabela_hash.acessa_valor(valor);
            break;
        }
    }
    return 0;
}
