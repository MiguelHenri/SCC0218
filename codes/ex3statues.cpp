#include <bits/stdc++.h>

using namespace std;

#define long long int lli

int main() {
    
    // estatuas
    int n; cin >> n;

    // distancia assegurada
    int k; cin >> k;

    // lendo posicoes e obtendo resposta
    int pos = 0;
    int contador = 0;
    for (int i=0; i<n; i++) {
        int x; cin >> x;
        
        if (x > pos) {
            pos = x + 2*k;
            contador++;
        }
    }

    cout << contador << "\n";

    return 0;

}
