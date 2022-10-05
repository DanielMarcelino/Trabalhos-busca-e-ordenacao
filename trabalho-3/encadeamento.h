#include <iostream>
using namespace std;


class Nodo{
    public:
        Nodo* proximo;
        int valor;

    Nodo(){
        proximo = NULL;
    }

    ~Nodo(){
        if(proximo)
            delete proximo;
    }

};


class ListaEncadeada {

    public:
        Nodo* inicio;
       
        ListaEncadeada(){
            inicio = NULL;
        }

        ~ListaEncadeada(){
            if(inicio)
                delete inicio;
        }

        void adiciona_valor(int valor){
            Nodo* novo_valor = new Nodo();
            novo_valor->valor = valor;
            novo_valor->proximo = inicio;
            inicio = novo_valor;
        }

        int acessa_valor(int valor){
            Nodo* ptr = inicio;
            while(ptr){
                if(ptr->valor == valor)
                    return valor;
                ptr = ptr->proximo;
            }
            return -1;
        }

        void imprime_lista(){
            Nodo* ptr = inicio;
            while(ptr){
                cout <<  ptr->valor << ", ";
                ptr = ptr->proximo;
            }
            cout << endl;
        }
};


class TabelaHashEncadeamento{
    private:
        ListaEncadeada vetor_listas[MAX];

        int funcao_hash(int valor){
            return valor % MAX;
        }


    public:

        void imprime_tabela(){
            cout << "\tChave" << "\tValor" << endl;
            for(int i =0; i < MAX; i++)
                if(vetor_listas[i].inicio){
                    cout << "\t" << i << "\t";
                    vetor_listas[i].imprime_lista();
            }
            else
                cout << "\t" << i << "\t(Vazio)" << endl;
        }

        void insere_valor(int valor){
            int chave = funcao_hash(valor);
            cout << "Inserindo o valor " << valor << " para a chave " << chave << endl;
            if(vetor_listas[chave].acessa_valor(valor) != -1){
                cout << "    - O valor já está na tabela!" << endl;
                return;
            }
            if(vetor_listas[chave].inicio)
                cout << "    - Houve colisão. Valor encadeado à lista " << endl;
            vetor_listas[chave].adiciona_valor(valor);
            imprime_tabela();
             cout << endl;
        }

        void acessa_valor(int valor){
            int chave = funcao_hash(valor);
            cout << "Buscando o valor " << valor << " na chave " << chave << endl;
            cout << "    - Verificando se o valor está na lista encadeada contida na chave."<< endl;
            valor = vetor_listas[chave].acessa_valor(valor);
            if(valor != -1)
                cout << "    - O valor existe na tabela hash."<< endl;
            else
                cout << "    - O valor não existe na tabela hash."<< endl;
        }
};
