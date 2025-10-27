#include <bits/stdc++.h>
using namespace std;

int main(){

    int casos;
    cin >> casos;

    while (casos--){
        int tam , k;
        cin >> tam >> k;

        vector <char> palabra(tam); 
        vector <int> arr(tam,0);

        int cont = 0;

 

        for(int i = 0; i < tam; i++){

            cin >> palabra[i];
        }

        if(palabra.back() == 'B'){
             arr[tam-1] = 1;
             cont++;
        }

        for(int i = tam - 2; i >= 0; i--){
            if(palabra[i] == 'B'){
                arr[i] = arr[i+1] + 1;
                cont ++;
            }
            else{
                arr[i] = arr[i+1];
            }
        }
        
        if(k ==  cont){
            cout << "0" << endl;
        }
        else if(k < cont){
            
            int trabajo = 0;
            int pos;

            arr.push_back(0);

            for(int i = tam; i >= 0; i--){
                if(arr[i] == k){
                    pos = i;

                    cout << 1 << endl;
                    cout << pos << " A" << endl;
                    break;
                }
            }
        }

        else if(k > cont){


            for(int i = 0; i < tam; i++){
                if(palabra[i] == 'A'){
                    cont++;
                }
                if(cont == k){
                    cout << 1 << endl;
                    cout << i+1 << " B" << endl;
                    break;
                }
            }

            

        }

    }
    

    return 0;
}