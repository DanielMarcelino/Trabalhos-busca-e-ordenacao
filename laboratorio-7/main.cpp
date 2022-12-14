#include <iostream>

using namespace std;


class Nodo{
    public:
        int valor, altura, fator_balanceamento;
        Nodo *filho_esq, *filho_dir;

        Nodo(int _valor){
            filho_esq = filho_dir = NULL;
            valor = _valor;
        }
};


class Avl{
    private:
        Nodo *raiz;

        void insere_raiz(int valor){
            raiz = new Nodo(valor);
        }

        void insere_galhos(int valor){
            Nodo* nodo_pai = raiz;
            while(nodo_pai){
                if(valor < nodo_pai->valor){
                    if(!nodo_pai->filho_esq){
                        nodo_pai->filho_esq = new Nodo(valor);
                        return;
                    }
                    nodo_pai = nodo_pai->filho_esq;
                    continue;
                }
                if(!nodo_pai->filho_dir){
                    nodo_pai->filho_dir = new Nodo(valor);
                    return;
                }
                nodo_pai = nodo_pai->filho_dir;
            }
        }

        void mostra_arvore_recursivamente(Nodo *nodo_pai){
            if(nodo_pai){
                cout << nodo_pai->valor << ", " << nodo_pai->altura << endl;
                mostra_arvore_recursivamente(nodo_pai->filho_esq);
                mostra_arvore_recursivamente(nodo_pai->filho_dir);
            }
        }

        int define_altura(Nodo* nodo_pai){
            int altura_esquerda = 0, altura_direita = 0;
            cout << nodo_pai->valor;
            if(nodo_pai->filho_esq){
                altura_esquerda = define_altura(nodo_pai->filho_esq);
            }
            if(nodo_pai->filho_dir){
                altura_direita = define_altura(nodo_pai->filho_dir);
            }
            nodo_pai->altura = altura_esquerda > altura_direita? altura_esquerda : altura_direita;
            return nodo_pai->altura + 1;

        }

    public:
        Avl(){
            raiz = NULL;
        }

        void insere(int valor){
            if(!raiz){
                insere_raiz(valor);
                return;
            }
            insere_galhos(valor);
        }

        void mostra_arvore(){
            define_altura(raiz);
            // cout << "teste";

            mostra_arvore_recursivamente(raiz);
        }

};



int main(){
    Avl arvore_balanceada;
    int lista[15] = {20, 21, 22, 23, 24, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10};

    // Insere os valores na arvore.
    for(int i=0; i < 15; i++)
        arvore_balanceada.insere(lista[i]);

    arvore_balanceada.mostra_arvore();
    return 0;
}
