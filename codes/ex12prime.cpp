#include <bits/stdc++.h>

using namespace std;

#define int long long int

bool isPrime(int n) {
    // tratando excessoes
    if (n <= 1)
        return false;

    // checando divisores
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    // passou
    return true;
}

char has3divisors(int n) {
    // um numero tem exatamente 3 divisores quando ele eh 
    // um quadrado perfeito e sua raiz um numero primo

    // um dos divisores eh o 1, o outro ele mesmo
    // o terceiro eh a raiz

    int raiz = sqrt(n);

    if (raiz * raiz == n && isPrime(raiz))
        return '1';

    return '0';
}

int32_t main() {
    // lendo input
    int n; cin >> n; // n numeros

    // lendo numeros
    vector<char> ans; // resposta
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        ans.push_back(has3divisors(c));
    }

    for (int i = 0; i < n; i++)
        cout << ans[i];

    cout << "\n";

    return 0;

}