#include <bits/stdc++.h>
using namespace std;

int main(){

    int casos;
    cin >> casos;

    while (casos--){
        int numero;
        cin >> numero;

        if(numero%3 == 0) cout << "Second" << endl;
        else cout << "First" << endl;
    }
    

    return 0;
}