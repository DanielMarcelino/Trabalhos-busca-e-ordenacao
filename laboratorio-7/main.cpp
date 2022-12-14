#include <iostream>

using namespace std;


class Nodo{
    public:
        int valor, altura;
        Nodo *filho_esq, *filho_dir;

        Nodo(int _valor){
            filho_esq = filho_dir = NULL;
            valor = _valor;
            altura = 0;
        }
};


class Avl{
    private:
        Nodo *raiz;

        void insere_raiz(int valor){
            raiz = new Nodo(valor);
        }


        int insere_recursivamente(Nodo* nodo_pai, int valor){
            int nova_altura = 1;
            if(valor < nodo_pai->valor){
                if(!nodo_pai->filho_esq){
                    nodo_pai->filho_esq = new Nodo(valor);
                }else{
                    nova_altura = insere_recursivamente(nodo_pai->filho_esq, valor);
                }
            }else{
                if(!nodo_pai->filho_dir){
                    nodo_pai->filho_dir = new Nodo(valor);
                }else{
                    nova_altura = insere_recursivamente(nodo_pai->filho_dir, valor);
                }
            }
            nodo_pai->altura = nova_altura > nodo_pai->altura? nova_altura : nodo_pai->altura;
            return nova_altura + 1;
        };
        void insere_galhos(int valor){
            Nodo* nodo_pai = raiz;
            insere_recursivamente(nodo_pai, valor);
            // while(nodo_pai){
            //     nodo_pai->altura += 1;
            //     if(valor < nodo_pai->valor){
            //         if(!nodo_pai->filho_esq){
            //             nodo_pai->filho_esq = new Nodo(valor);
            //             break;
            //         }
            //         nodo_pai = nodo_pai->filho_esq;
            //         continue;
            //     }
            //     if(!nodo_pai->filho_dir){
            //         nodo_pai->filho_dir = new Nodo(valor);
            //         break;
            //     }
            //     nodo_pai = nodo_pai->filho_dir;
            // }

        }

        int obtem_fb(Nodo* nodo){
            int altura_fe = nodo->filho_esq? nodo->filho_esq->altura : 0;
            int altura_fd = nodo->filho_dir? nodo->filho_dir->altura : 0;
            return altura_fe - altura_fd;
        }

        void mostra_arvore_recursivamente(Nodo *nodo_pai){
            if(nodo_pai){
                cout << nodo_pai->valor << ", " << nodo_pai->altura << ", " <<  obtem_fb(nodo_pai) << endl;
                mostra_arvore_recursivamente(nodo_pai->filho_esq);
                mostra_arvore_recursivamente(nodo_pai->filho_dir);
            }
        }

        // int define_altura(Nodo* nodo_pai){
        //     int altura_esquerda = 0, altura_direita = 0;
        //     if(nodo_pai->filho_esq){
        //         altura_esquerda = define_altura(nodo_pai->filho_esq);
        //     }
        //     if(nodo_pai->filho_dir){
        //         altura_direita = define_altura(nodo_pai->filho_dir);
        //     }
        //     nodo_pai->altura = altura_esquerda > altura_direita? altura_esquerda : altura_direita;
        //     return nodo_pai->altura + 1;
        // }

        // void define_fator_balanceamaneto(Nodo* nodo_pai){
        //     int altura_esq = 0, altura_dir = 0;
        //     if(nodo_pai->filho_esq){
        //         altura_esq = nodo_pai->filho_esq->altura;
        //         define_fator_balanceamaneto(nodo_pai->filho_esq);
        //     }
        //     if(nodo_pai->filho_dir){
        //         altura_dir = nodo_pai->filho_dir->altura;
        //         define_fator_balanceamaneto(nodo_pai->filho_dir);

        //     }
        //     nodo_pai->fator_balanceamento = altura_esq - altura_dir;
        // }

    public:
        Avl(){
            raiz = NULL;
        }

        void insere(int valor){
            if(!raiz){
                insere_raiz(valor);
                raiz->altura = 0;
                return;
            }
            insere_galhos(valor);
        }

        void mostra_arvore(){
            // define_altura(raiz);
            // define_fator_balanceamaneto(raiz);
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
