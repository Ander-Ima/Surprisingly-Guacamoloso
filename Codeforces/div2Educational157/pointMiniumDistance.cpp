#include <bits/stdc++.h>
using namespace std;


int main(){
    // P

    int casos;
    cin >> casos;

    while(casos--){
        
        int tamano;
        cin >> tamano; 

        tamano *=2;
        vector <int> puntos(tamano);

        for(int i = 0; i < tamano; i++) cin >> puntos[i];

        if(tamano == 4){
            
            int tempo = 0;
            
            sort(puntos.begin(), puntos.end());

            tempo = abs(puntos[0] - puntos[1]) + abs(puntos[2] - puntos[3]);

            cout << tempo << '\n';

            cout << puntos [0] << ' ' << puntos[2] << '\n';
            cout << puntos [1] << ' ' << puntos[3] << '\n';
            

        }
        else{

            sort(puntos.begin(), puntos.end());
            
            int up = tamano - 1;
            int suma = 0;

            vector <int> cordenadas; 

            for(int i = 0; i < tamano/2; i++){

                cordenadas.push_back(puntos[i]);
                cordenadas.push_back(puntos[up]);
                
                up--;
            }
            up = 1;

            for (int i = 0; i < tamano - 2; i += 2) {

                suma += abs(cordenadas[i] - cordenadas[i + 2]) + abs(cordenadas[i + 1] - cordenadas[i + 3]);

            }



            cout << suma << '\n';

            up = 1;

            for(int i = 0; i < tamano; i ++){
                cout << cordenadas [i] << ' ' << cordenadas[up] << '\n';
                i++;
                up += 2;
            }

        }

    }


    return 0;
}