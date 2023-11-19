#include <bits/stdc++.h>
using namespace std;

int main(){

    int casos;
    cin >> casos;

    while(casos--){
        
        int tam;
        cin >> tam;

        vector<int> arr(tam);
        vector<long long int> arr2(tam+1);
        arr2[0] = 0;

        for(int i = 0; i < tam; i++){
            
            cin >> arr[i];
            

            if(i > 0) arr2[i] = arr2[i-1] + arr[i-1]; 
        }
        arr2[tam] = arr2[tam-1] + arr[tam-1];
        
        
        auto dato = minmax_element(arr.begin(), arr.end());

        long long int maxi = (*dato.second) - (*dato.first);

        long long int up = 0, dowm, puntero, cont = 0;

        for(int k = 2; k < tam; k++){

            if((tam % k) == 0){
                puntero = 0;
                cont = 0;
                up = 0;
                
                long long int abajo = 0, arriba = k;

                while (cont < tam){

                    long long int sum = arr2[arriba] - arr2[abajo];

                    abajo += k;
                    arriba += k;

                    if(puntero == 0){
                        dowm = sum;
                        puntero = 1;
                    }

                    if(sum > up) up = sum;
                    if(sum < dowm) dowm = sum;

                    cont += k;

                }

            long long int tempo = up - dowm;
            if(tempo > maxi) maxi = tempo;
            }
        }

        cout << maxi << endl;

    }

    return 0;
}