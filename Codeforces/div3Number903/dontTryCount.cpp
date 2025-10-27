#include <bits/stdc++.h>
using namespace std;

int casos, longitudA, longitudB;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> casos;
    vector <char> primero, segundo;

    string first, second;


    char pos;


    int aprox;

    while (casos--){

        cin >> longitudA >> longitudB;

        aprox = 0;

        while(longitudA < longitudB){
            aprox++;
            longitudA*=2;
        }

        cin >> first >> second;

        int n = 2;

        for(int i = 1; i <= aprox; i++){
            first = first+first;
        }

        size_t found = first.find(second);

        if (found != string::npos) {
        cout << aprox << endl;
        } 
        else {
                
            first+=first;
            aprox++;
            size_t found = first.find(second);

            if (found != string::npos) {
                cout << aprox  << endl;
            } 
            else cout << -1 << endl;

        }



    }

    


    return 0;
}

