#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define MOD 1000000007 // 10e9 + 7

int solve(int a, int b) {
    // exponenciacao
    int ans = 1;

    // otimizando
    a = a % MOD;

    // operando multiplicacoes
    while (b > 0) {
        // se impar, multiplica uma vez
        if (b % 2 == 1)
            ans = (ans * a) % MOD;

        // agora podemos considerar o expoente como par
        // pularemos etapar de multiplicacao com base que:
        // a ^ 2b = (a * a) ^ b
        
        // nova base (a * a)
        a = (a * a) % MOD;

        // novo expoente (antes 2b, agora b)
        b = b/2;
    }

    return ans;
}

int32_t main() {
    // lendo input
    int t; cin >> t; // testes

    while (t--) {
        int a, b;

        cin >> a >> b;

        // soluciona teste
        cout << solve(a, b) << "\n";
    }

    return 0;

}