#include <iostream>
#include <fstream>

using namespace std;

unsigned int acessos = 0;

class ListaAleatoria{
    private:
        int comprimento;
        int *lista;

        int obtem_numero_aleatorio(){
            return (rand() % 1000)+ 1;
        }

        void compoem_lista(){
            lista = new int[comprimento];
            for(int i = 0; i < comprimento; i++)
                lista[i] = obtem_numero_aleatorio();
        }

    public:
        ListaAleatoria(int _comprimento){
            // srand(clock());
            comprimento = _comprimento;
            compoem_lista();
        }

        ~ListaAleatoria(){
            if(lista)
                delete lista;
        }

        int* obtem_lista(){
            return lista;
        }

        int obtem_comprimento(){
            return comprimento;
        }
};


void swap(int *i, int *j){
    int aux = *i;
    *i = *j;
    *j = aux;
}

int partition(int *l, int e, int d){
    int c = e;
    for(int i = e; i < d; i++){
        acessos++;
        if(l[i] < l[d]){
            swap(l[c], l[i]);
            c++;
            acessos++;
        }
    }
    swap(l[c], l[d]);
    acessos++;

    return c;
}

void mostra_lista(int lista[], int inicio, int fim){
    for(int i = inicio; i <= fim; i++){
        cout << lista[i] << ", ";
    }
    cout << endl;
}

void quick_sort(int *l, int e, int d, bool usa_mediana = 0, bool _mostra_lista = 0){
    if(_mostra_lista)
        mostra_lista(l, e, d);

    if(e < d){
        if(usa_mediana){
            int meio = ((d + 1) / 2) - 1, mediana = 0;
            if(l[e] < l[meio])
                if(l[meio] < l[d])
                    mediana = meio;
                else
                    if(l[e] < l[d])
                        mediana = d;
                    else
                        mediana = e;
            else
                if(l[d] < l[meio])
                    mediana = meio;
                else
                    if(l[d] < l[e])
                        mediana = d;
                    else
                        mediana = e;

            swap(l[mediana],l[d]);
            if(_mostra_lista){
                cout << "Pivo: " << l[d] << endl;
                mostra_lista(l, e, d);
            }
        }

        int c = partition(l, e, d);
        quick_sort(l, e, c - 1, usa_mediana, _mostra_lista);
        quick_sort(l, c + 1, d, usa_mediana, _mostra_lista);
    }
}



int menu(){
    int opc;
    cout << "[1] - Escolher o pivô como o o último elemento da lista." << endl;
    cout << "[2] - Escolher o pivô como o o item médio entre o primeiro, segundo e terceiro item." << endl;
    cout << "[3] - Executar algoritmo com listas aleatórias." << endl;
    cin >> opc;
    return opc;
}

int main(){
    int lista[20] = {70, 1, 12, 8, 99, 72, 5, 15, 20, 91, 14, 61, 66, 41, 81, 88, 16, 21, 34, 90};

    switch(menu()){
        case 1:
            quick_sort(lista, 0, 19, 0, 1);
            cout << endl << "Acessos: " << acessos << endl;
            break;
        case 2:
            quick_sort(lista, 0, 19, 1, 1);
            cout << endl << "Acessos: " << acessos << endl;
            break;
        case 3:
            ofstream fout("dados.csv"); // Abre arquivo para gravação
            fout << "n,ultimo elemento,mediana" << endl;
            for(int i = 1; i <= 100; i++){

                fout << i << ",";
                ListaAleatoria lista_aleatoria(i);
                ListaAleatoria lista_aleatoria2(i);
                acessos = 0;
                mostra_lista(lista_aleatoria.obtem_lista(), 0, lista_aleatoria.obtem_comprimento()-1);
                quick_sort(lista_aleatoria.obtem_lista(), 0, lista_aleatoria.obtem_comprimento()-1, 0, 0);
                cout << endl << "Acessos: " << acessos << endl;
                fout << acessos << ",";
                acessos = 0;
                mostra_lista(lista_aleatoria2.obtem_lista(), 0, lista_aleatoria2.obtem_comprimento()-1);
                quick_sort(lista_aleatoria2.obtem_lista(), 0, lista_aleatoria2.obtem_comprimento()-1, 1), 0;
                cout << endl << "Acessos: " << acessos << endl;
                fout << acessos << endl;

            }
    }
    
    
    return 0;
}