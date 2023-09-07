#include <bits/stdc++.h>

using namespace std;

#define long long int lli

bool test(int n, vector<int> v, int k, int raio) {
    // testando se um raio r é suficiente
    int pos = 0;
    int contador = 0;
    for (int i=0; i<n; i++) {

        int x = v[i];
        
        if (x > pos) {
            pos = x + 2*raio;
            contador++;
        }
    }

    if (contador <= k) return true;

    return false;
}

int solve(int n, vector<int> v, int k) {
    // testar valores com busca binaria
    // raio maximo = 1e5

    int ans = INT_MAX;

    int r = 1e9; int l = 0;
    
    while (r >= l) {

        int mid = (l + r)/2;

        bool t = test(n, v, k, mid);

        // testar com raios menores
        if (t == true) {
            if (mid < ans) ans = mid;
            r = mid - 1;
        }

        // testar com raios maiores
        else l = mid + 1;
    }

    return ans;
}

int main() {
    // lendo input
    int n; cin >> n; // quantidade de estatuas
    int k; cin >> k; // numero de explosivos

    vector<int> v;
    for (int i = 0; i < n; i++) {
        int aux; cin >> aux;
        v.push_back(aux);
    }

    // obtendo resposta
    int ans = solve(n, v, k);

    cout << ans << "\n";

    return 0;

}