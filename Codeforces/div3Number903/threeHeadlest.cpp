/*
#include <bits/stdc++.h>
using namespace std;

int casos;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;

    cin >> casos;

    

    while (casos--){
        
        cin >> a >> b >> c;

        if(a == b & b == c) cout << "YES" << endl;

        else{
            
            vector <int> numeros{a,b,c};
            sort(numeros.begin(), numeros.end());

            int count = 0;
            int trat=0;

            for(int i = 1; i < numeros.size(); i++){

                if(count >= 3){

                    for(int m = i; m < numeros.size(); m++){
                        if(numeros[m] != numeros[0]){
                            cout << "NO" << endl;
                            trat = 1;
                            break;
                        }
                    }
                    break;
                } 
                
                else{

                    if(numeros[i] > numeros[0]){
                        if(numeros[i]%2 == 0){
                            int first = numeros[i]/2;
                            numeros.push_back(first);
                            numeros.push_back(first);
                            numeros.erase(numeros.begin() + i);
                            i--;
                            count ++;
                        }
                        else{
                            int first = numeros[i]/2;
                            numeros.push_back(first);
                            first +=1;
                            numeros.push_back(first);
                            numeros.erase(numeros.begin() + i);
                            i--;
                            count ++;
                        }
                    }

                    if(numeros[i] < numeros[0]){
                        cout << "NO" << endl;
                        trat = 1;
                        break;
                    }

                }
            }

            if(trat != 1) cout << "YES" << endl;

        }

        

    }
    


    
    return 0;
}

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long a, b, c;
        cin >> a >> b >> c;

        if (a == b && b == c) {
            cout << "YES" << endl;
        } else {
            // Contar la cantidad de hebritas con longitudes a, b y c
            int count_a = (a == b) + (a == c);
            int count_b = (b == c);

            // Verificar si es posible igualar todas las longitudes
            if ((count_a % 2 == 0 && count_b == 0) || (count_a == 1 && count_b == 0)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}
