//Imprimir una diagonal en una matriz y luego con unos

#include <iostream>
using namespace std;

int main(){

    int matriz[3][3];
    for(int i = 0; i <= 3 ;i++){
        for(int j = 0; j <= 3 ; j++){
            if(i==j){
                cout << "1";
            }else{
                cout << "0";
            }
            } 
        cout << "\n" ;
    } 
    

    return 0;
}