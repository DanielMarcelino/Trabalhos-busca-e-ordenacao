#include <iostream>
#include <string>
using namespace std;




int main(){
    int vetor[15] = {111, 41, 142, 76, 10, 201, 250, 108, 187, 7, 98, 188, 21, 99, 63};

    for(int i = 0; i < 15; i++){
        cout << vetor[i] << "\t - \t" << vetor[i] % 16 << endl;
    }
    return 1;

}