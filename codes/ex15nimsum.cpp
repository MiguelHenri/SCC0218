#include <bits/stdc++.h>

using namespace std;

#define int long long int

int solve(vector<int> pilhas) {

    // obtendo a nim_sum das pilhas
    int nim_sum = 0;
    for (int i=0; i<pilhas.size(); i++) {
        // isso eh feito usando o XOR
        nim_sum ^= pilhas[i];
    }

    // existe estrategia vencedora se nim_sum eh != 0
    // welligton devera fazer a jogada que termine com nim-sum = 0
    // assim, se mantem com estrategia vencedora
    if (nim_sum != 0) return 0;

    // senao, queremos que nim_sum seja != 0
    // para isso, precisamos alterar uma pilha
    // a alteracao tem custo 1
    return 1;

}

int32_t main() {
    // lendo input
    int t; cin >> t; // testes

    while (t--) {
        int n; cin >> n;

        vector<int> pilhas;
        for (int i=0; i<n; i++) {
            int aux; cin >> aux;
            pilhas.push_back(aux);
        }

        // soluciona teste
        cout << solve(pilhas) << "\n";
    }

    return 0;

}