#include <bits/stdc++.h>

using namespace std;

#define int long long int

int solve(int n, int k) {
    // resposta
    int lances = 0;

    // realizando operacoes
    while (n > 0) {
        // se n < k, subtrai, uma vez que impossivel dividir
        if (n < k) {
            lances += n;
            n = 0;
        }
        // caso contrario, 'subtrai' ate ser divisivel
        else {
            int div = n / k;
            int resto = n % k;
            lances += resto + 1; // subtracoes + divisao
            n = div;
        }
    }

    return lances;
}

int32_t main() {
    // lendo input
    int t; cin >> t; // n testes

    // lendo numeros
    vector<int> ans; // resposta
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n;
        cin >> k;
        ans.push_back(solve(n, k));
    }

    for (int i = 0; i < t; i++)
        cout << ans[i] << "\n";

    return 0;

}