#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int t; 
    cin >> t;

    while (t--) {
        int n; 
        cin >> n;
        vector<int> a(n); 
        map<int, int> counts;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            counts[a[i]]++;
        }

        vector<int> b(n, -1);  // Inicialmente, todos los elementos de b son -1

        int repeated_element = -1;
        int second_element = -1;
        int warning = 0;
        int ddd= 0;
        for (const auto& pair : counts) {
            if(pair.second >= 2 && repeated_element != -1){
                second_element = pair.first;
                warning = 0;
                ddd = 0;
                break;
            }
            if (pair.second >= 2) {
                repeated_element = pair.first;
                if(pair.second > 2){
                    warning = 1;
                } 
                if(pair.second == 2) ddd = 1;
            }
        }

        

        if (repeated_element != -1 && warning == 0 && ddd == 0) {

            int cont = 0;   
            int conb = 0;

            int bas = 0;
            int das = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] == repeated_element && cont < 1) {
                    b[i] = 1;
                    cont++;
                    
                }
                if(a[i] == repeated_element && cont >= 1 && conb < 1 && b[i] != 1){
                    b[i] = 2;
                    conb ++;
                    
                }

                if(a[i] == second_element &&  bas < 1){
                    b[i] = 1;
                    bas++;
                   
                }
                if(a[i] == second_element &&  bas >= 1 && das < 1 && b[i] != 1){
                    b[i] = 3;
                    das++;
                }
                
            }

            for (int i = 0; i < n; i++) {
                if (b[i] == -1) {
                    b[i] = 1;
                }
            }


            for (int i = 0; i < n; i++) {
                cout << b[i] << " ";
            }
            cout << endl;
        } else {

            cout << -1 << endl;
        }
    }

    return 0;
}
