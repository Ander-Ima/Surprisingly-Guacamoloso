#include <bits/stdc++.h>
using namespace std;

int main(){

    int casos;
    cin >> casos;

    while(casos--){

        int cofre, llave, cansancio;
        cin >> cofre >> llave >> cansancio;

        if(cofre >= llave){
            cout << cofre << '\n';
        }

        

        else if(cofre < llave){
            int tiempo;

            if((cofre+cansancio) >= llave){
                tiempo = llave;
            }

            else{
                tiempo = cofre+cansancio;

                int date = llave - tiempo;

                tiempo += date + date;
            }
            cout << tiempo << '\n';
        }

        

    }


    return 0;
}