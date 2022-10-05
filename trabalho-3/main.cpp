#include <iostream>
#define MAX 24

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

int main()
{
    int valores[18] = {67, 76, 15, 20, 91, 14, 61, 88, 11, 90, 81, 60, 8, 55, 88, 99, 62, 71}, valor;

    switch(menu()){
        case 1:{
            TabelaHashEndAberto tabela_hash;
            for(int i = 0; i < 18; i++)
                tabela_hash.insere_valor(valores[i]);
            cout << "Digite um valor para buscar: " << endl << endl;
            cin >> valor;
            tabela_hash.acessa_valor(valor);
            break;
        }
        case 2:{
            TabelaHashEncadeamento tabela_hash;
            for(int i = 0; i < 18; i++)
                tabela_hash.insere_valor(valores[i]);
            cout << "Digite um valor para buscar: " << endl << endl;
            cin >> valor;
            tabela_hash.acessa_valor(valor);
            break;
        }
    }
    return 0;
}
