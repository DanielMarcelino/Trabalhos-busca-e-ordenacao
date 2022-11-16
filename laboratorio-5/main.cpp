#include <iostream>
#include <fstream>

using namespace std;
int mostra_estado_lista = 1;
int iteracoes_relevantes = 0;


void mostra_lista(int lista[], int n, int marca_num = -1){
    for(int i=0; i < n; i++){
        if(marca_num != i)
            cout << ' ' << lista[i] << "\t";
        else
            cout << '[' << lista[i] << "]\t";
    }
    cout << endl;
}

void swap(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

void heapfy(int lista[], int n,  int i){
    int m = i;
    int e = (i*2) + 1;
    int d = (i*2) + 2;
    if((e < n) && (lista[e] > lista[m]))
        m = e;
    if((d < n) && (lista[d] > lista[m]))
        m = d;
    if(m != i){
        swap(&lista[i], &lista[m]);
        heapfy(lista, n, m);
    }
    iteracoes_relevantes += 3;
}

void create_heap(int lista[], int n){
    for(int i = n/2 - 1; i >= 0; i--){
        heapfy(lista, n, i);
        if(mostra_estado_lista)
            mostra_lista(lista, n, i);
    }
}

void heap_sort(int lista[], int n){
    if(mostra_estado_lista){
        for(int i = 1; i <= n; i++)
            cout << i << "\t";
        cout << endl;
        cout << "Estado inicial:" << endl;
        mostra_lista(lista, n, -1);
        cout << "Durante create_heap:" << endl;
    }
    create_heap(lista, n);
    if(mostra_estado_lista)
        cout << "Durante ordenação final:" << endl;
    for(int i = n - 1; i > 0; i--){
        swap(&lista[0], &lista[i]);
        if(mostra_estado_lista)
            mostra_lista(lista, n, i);
        heapfy(lista, i, 0);
        if(mostra_estado_lista){
            mostra_lista(lista, n, 0);
            cout << endl;
        }
    }

}

int menu(){
    int opc;
    cout << "[1] Execução com lista de conteúdo fixo e exibindo estado dalista a cada recursão" << endl;
    cout << "[2] Execução sobre listas aleatórias com geração de CSV" << endl << endl;
    cout << "Digite uma opção: " << endl << endl;
    cin >> opc;
    return opc;
}

int main(){

    switch(menu()){
        case 1:{
            int n = 20;
            int lista[n] = {70, 1, 12, 8, 99, 72, 5, 15, 20, 91, 14, 61, 66, 41, 81, 88, 16, 21, 34, 90};
            heap_sort(lista, 20);
            break;
        }
        case 2:{
            mostra_estado_lista = 0;
            cout << "n\t" << "\tIterações relevantes" << endl;
            ofstream fout("dados.csv"); // Abre arquivo para gravação
            fout << "n,iteracoes_relevantes" << endl;
            for(int n = 1; n <= 100; n++){
                int lista[n];
                for(int i = 0; i < n; i++)
                    lista[i] = (rand() % 1000) + 1;
                iteracoes_relevantes = 0;
                heap_sort(lista, n);
                // mostra_lista(lista, n);
                fout << n << "," << iteracoes_relevantes << endl;
                cout << n << "\t" << "\t" << iteracoes_relevantes << endl;
            }
            break;
        }
    }

    return 0;
}
