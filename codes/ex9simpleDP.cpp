#include <bits/stdc++.h>

using namespace std;

#define lli long long int

void print(vector<lli> v) {
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
}

lli solve(vector<lli> v, lli n) {

    lli ans = 0;
    
    vector<lli> dp(n, LLONG_MAX);

    dp[0] = 0;

    // dp iterativa
    for (lli i = 0; i < n; i++) {
        for (lli j = i + 1; j < min(n, i + 3); j++) {
            dp[j] = min(dp[j], dp[i] + abs(v[i] - v[j]));
        }
    }

    // print(dp);

    ans = dp[n-1];

    return ans;
}

int main() {
    // lendo input
    lli n; cin >> n; // tamanho

    // vetor de dificuldades
    vector<lli> v;

    for (lli i=0; i<n; i++) {
        lli d; cin >> d;
        v.push_back(d);
    }

    // obtendo resposta
    lli ans = solve(v, n);

    cout << ans << "\n";

    return 0;

}