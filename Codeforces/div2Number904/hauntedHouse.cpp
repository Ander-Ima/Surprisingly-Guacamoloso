#include <bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);



    int casos;
    cin >> casos;

    while (casos--){

        int n;
        cin >> n;


        vector <char> binario (n);

        for(int i = 0; i < n; i++){
            cin >> binario[i];
        }

        int decimal = 0;
        int contador = 0;

        for(int i = n-1; i >= 0; i--){
            if(binario[i] == '1'){
                contador++;
                if(i == n-1) decimal = 1;
                else decimal += pow(2,n-1-i);
            }
        }

        int potencia;

        int maximo = 0;
        int minimo = 0;
        int p = n-1;

        for(int i = contador; i > 0; i--){
            maximo += pow(2,p);
            p--;
        }

        p = 0; 

        for(int i = 0; i < contador; i++){
            minimo += pow(2,i);
        }
        

        int key = 0;

        for(int i = 1; i <= n; i++){

            potencia = pow(2,i);

            if(key == 1){
                cout << -1 << ' ';
            }

            else if(potencia > minimo) {
                cout << -1 << ' ';
                key = 1;
            }

            if((decimal % potencia) == 0 && key == 0){
                cout << 0 << ' ';
            }

            else{
                
            }

        }

        cout << endl;


    }


    return 0;
}
