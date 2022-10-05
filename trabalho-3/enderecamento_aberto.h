#include <iostream>
using namespace std;


class TabelaHashEndAberto{
    private:
        int quantidade_valores;
        int vetor_valores[MAX];

    void inicializa_vetor(){
        for(int i = 0; i < MAX; i++)
            vetor_valores[i] = -1;
    }

    int funcao_hash(int valor){
        return valor % MAX;
    }

    int obtem_chave_posicao(int valor){
        int chave = funcao_hash(valor);
        while(1){
            if(vetor_valores[chave] == -1)
                return chave;
            chave = (chave + 1) % MAX;
        }
        return -1;
    }

    bool valor_ja_existe(int valor, int chave_canonica){
        int chave = chave_canonica;
        while(1){
            if(vetor_valores[chave] == -1)
                return 0;
            if(vetor_valores[chave] == valor)
                return 1;
            chave = (chave + 1) % MAX;
        }
    }

     public:
        TabelaHashEndAberto(){
            inicializa_vetor();
            quantidade_valores = 0;
        }

        void insere_valor(int valor){
            int chave_canonica = valor % MAX;
            int chave_anti_colisao = obtem_chave_posicao(valor);
            cout << "Inserindo o valor " << valor << " para a chave " << chave_canonica << endl;
            
            if(quantidade_valores == MAX - 1){
                cout << "    - Tabela cheia!" << endl << endl;
                return;
            }

            if(valor_ja_existe(valor, chave_canonica)){
                cout << "    - O valor já está na tabela!" << endl << endl;
                return;
            }


            if(chave_canonica != chave_anti_colisao)
                cout << "    - Houve colisão. Valor inserido na chave " << chave_anti_colisao << endl;
            cout << "Tabela Atual: " << endl;
            quantidade_valores ++;
            vetor_valores[chave_anti_colisao] = valor;
            imprime_tabela();
            cout << endl;
        }

        void imprime_tabela(){
            cout << "\tChave" << "\tValor" << endl;
            for(int i =0; i < MAX; i++)
                if(vetor_valores[i] != -1)
                    cout << "\t" << i << "\t" << vetor_valores[i] << endl;
            else
                cout << "\t" << i << "\t(Vazio)" << endl;
        }

        void acessa_valor(int valor){
            int chave = funcao_hash(valor);
            cout << "Buscando pelo valor " << valor << " na chave " << chave << endl;
            while(1){
                if(vetor_valores[chave] == -1){
                    cout << "    - Valor não encontrado!" << endl;
                    break;
                }
                if(vetor_valores[chave] == valor){
                    cout << "    - Valor encontrado na chave " << chave << endl;
                    break;
                }
                chave = (chave + 1) % MAX;
            }
        }

};
