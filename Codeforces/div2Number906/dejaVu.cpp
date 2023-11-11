#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;  // Número de casos de prueba

    while (t--) {
        int n, q;
        cin >> n >> q;  // Longitud del array y número de consultas

        vector<int> a(n);
        vector<int> x(q);

        // Leer los elementos del array a
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Leer las consultas de modificación
        for (int i = 0; i < q; i++) {
            cin >> x[i];
        }

        // Realizar las consultas de modificación y calcular la cantidad a agregar a cada elemento
        for (int i = 0; i < q; i++) {
            for (int j = 0; j < n; j++) {
                if (a[j] % (1 << x[i]) == 0) {
                    a[j] += (1 << (x[i] - 1));
                }
            }
        }

        // Mostrar el array final
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
