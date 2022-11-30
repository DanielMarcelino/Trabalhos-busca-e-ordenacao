#include <iostream>
using namespace std;

 class Nodo{
    public:
        Nodo *filho_esquerdo, *filho_direito;
        int valor;
        Nodo(){
            filho_direito = filho_esquerdo = NULL;
        }
        Nodo(int _valor){
            filho_direito = filho_esquerdo = NULL;
            valor = _valor;
        }
};

class Arvore{
private:
    void mostra_arvore_recursao(Nodo* nodo){
        if(nodo){
            cout << nodo->valor << ", ";
            if(nodo->filho_esquerdo)
                mostra_arvore_recursao(nodo->filho_esquerdo);
            if(nodo->filho_direito)
                mostra_arvore_recursao(nodo->filho_direito);
        }
    }

    Nodo* obtem_nodo(int valor){
        Nodo *nodo_pai = raiz;
        while(nodo_pai){
            if(valor == nodo_pai->valor)
                return nodo_pai;
            if(valor < nodo_pai->valor){
                if(!nodo_pai->filho_esquerdo){
                    break;
                }
                nodo_pai = nodo_pai->filho_esquerdo;
                continue;
            }
            if(!nodo_pai->filho_direito){
                break;
            }
            nodo_pai = nodo_pai->filho_direito;
        }
        return NULL;
    }

    void insere_nodo(Nodo* nodo){
        Nodo* nodo_pai = raiz;
        if(!raiz){
            raiz = nodo;
            return;
        }
        while(nodo_pai){
            if(nodo->valor < nodo_pai->valor){
                if(!nodo_pai->filho_esquerdo){
                    nodo_pai->filho_esquerdo = nodo;
                    break;
                }
                nodo_pai = nodo_pai->filho_esquerdo;
                continue;
            }
            if(!nodo_pai->filho_direito){
                nodo_pai->filho_direito = nodo;
                break;
            }
            nodo_pai = nodo_pai->filho_direito;
        }
    }

    void reinsere_nodos_recursivamente(Nodo* nodo_pai){
        Nodo* filho_esquerdo = nodo_pai->filho_esquerdo;
        Nodo* filho_direito = nodo_pai->filho_direito;

        nodo_pai->filho_esquerdo = NULL;
        nodo_pai->filho_direito = NULL;

        insere_nodo(nodo_pai);

        if(filho_esquerdo)
            reinsere_nodos_recursivamente(filho_esquerdo);

        if(filho_direito)
            reinsere_nodos_recursivamente(filho_direito);

    }

    void retira_nodo_e_reinsere_sub_arvores_filhas(Nodo* nodo_pai){

        Nodo* filho_esquerdo = nodo_pai->filho_esquerdo;
        Nodo* filho_direito = nodo_pai->filho_direito;

        delete nodo_pai;

        if(filho_esquerdo)
            reinsere_nodos_recursivamente(filho_esquerdo);

        if(filho_direito)
            reinsere_nodos_recursivamente(filho_direito);
    }

    void desaloca_nodos(Nodo* nodo_pai){
        if(nodo_pai){
            if(nodo_pai->filho_esquerdo)
                desaloca_nodos(nodo_pai->filho_esquerdo);
            if(nodo_pai->filho_direito)
                desaloca_nodos(nodo_pai->filho_direito);
            cout << "Desalocando nodo valor: " << nodo_pai->valor << endl;
            delete nodo_pai;
        }
    }
public:
    Nodo *raiz;
    Arvore(){
        raiz = NULL;
    }

    ~Arvore(){
        desaloca_nodos(raiz);
    }

    void insere(int valor){
        if(!raiz){
            raiz = new Nodo(valor);
            return;
        }
        Nodo *nodo_pai = raiz;
        while(nodo_pai){
            if(valor < nodo_pai->valor){
                if(!nodo_pai->filho_esquerdo){
                    nodo_pai->filho_esquerdo = new Nodo(valor);
                    break;
                }
                nodo_pai = nodo_pai->filho_esquerdo;
                continue;
            }
            if(!nodo_pai->filho_direito){
                nodo_pai->filho_direito = new Nodo(valor);
                break;
            }
            nodo_pai = nodo_pai->filho_direito;
        }
    }

    void mostra_arvore(){
        mostra_arvore_recursao(raiz);
        cout << endl;
    }

    void busca_valor(int valor){
        
        Nodo *nodo_pai = raiz;
        while(nodo_pai){
            cout << nodo_pai->valor << endl;
            if(valor == nodo_pai->valor){
                cout << "Valor encontrado!" << endl;
                break;
            }
            if(valor < nodo_pai->valor){
                if(!nodo_pai->filho_esquerdo){
                    cout << "Valor não existe na arvore!" << endl;
                    break;
                }
                nodo_pai = nodo_pai->filho_esquerdo;
                continue;
            }
            if(!nodo_pai->filho_direito){
                cout << "Valor não existe na arvore!" << endl;
                break;
            }
            nodo_pai = nodo_pai->filho_direito;
        }
    }

    void retira_valor(int valor){
        Nodo *nodo_pai = raiz;
        Nodo *nodo_a_remover;
        if(valor == raiz->valor){
            nodo_a_remover = raiz;
            raiz = NULL;
            retira_nodo_e_reinsere_sub_arvores_filhas(nodo_a_remover);
            return;
        }
            

        while(nodo_pai){
            if(valor < nodo_pai->valor){
                if(!nodo_pai->filho_esquerdo){
                    break;
                }
                if(valor == nodo_pai->filho_esquerdo->valor){
                    nodo_a_remover = nodo_pai->filho_esquerdo;
                    nodo_pai->filho_esquerdo = nodo_pai->filho_direito = NULL;
                    retira_nodo_e_reinsere_sub_arvores_filhas(nodo_a_remover);
                    break;
                }
                nodo_pai = nodo_pai->filho_esquerdo;
                continue;
            }
            if(!nodo_pai->filho_direito){
                break;
            }
            if(valor == nodo_pai->filho_direito->valor){
                nodo_a_remover = nodo_pai->filho_direito;
                nodo_pai->filho_esquerdo = nodo_pai->filho_direito = NULL;
                retira_nodo_e_reinsere_sub_arvores_filhas(nodo_a_remover);
                break;
            }
            nodo_pai = nodo_pai->filho_direito;
        }
    }

    void apaga_arvore(){

        desaloca_nodos(raiz);
        raiz = NULL;
    }
};

 int main(){
    int n = 16, lista[n] = {31, 6, 90, 91, 40, 10, 7, 21, 78, 14, 22, 17, 20, 55, 68, 39};
    Arvore apb;
    cout << "lista de valores: " << endl;
    for(int i = 0; i < n; i++){
        cout << lista[i] << ", ";
        apb.insere(lista[i]);
    }
    cout << endl;


    cout << "Estado Inicial da Arvore: " << endl;
    apb.mostra_arvore();
    cout << endl;


    int valores_buscar[4] = {31, 58, 20, 18};
    for(int i = 0; i < 4; i++){
        cout << ">> Buscando pelo valor: " << valores_buscar[i] << endl;
        apb.busca_valor(valores_buscar[i]);
        cout << endl;
    }

    int valores_remover[2] = {31, 78};
    for(int i = 0; i < 2; i++){
        cout << ">> Removendo o valor: " << valores_remover[i] << endl;
        apb.retira_valor(valores_remover[i]);
    }

    int valores_buscar_1[5] = {31, 20, 22, 68, 78};
    for(int i = 0; i < 5; i++){
    cout << ">> Buscando pelo valor: " << valores_buscar_1[i] << endl;
    apb.busca_valor(valores_buscar_1[i]);
    cout << endl;
    }


    cout << "Estado atual da Arvore: " << endl;
    apb.mostra_arvore();
    cout << endl;

    cout << ">> Apagando arvore..." << endl;
    apb.apaga_arvore();
    cout << "Todos os nodos foram desalocados." << endl;
    return 0;
 }
