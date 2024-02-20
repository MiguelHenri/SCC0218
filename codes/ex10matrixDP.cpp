#include <bits/stdc++.h>

using namespace std;

#define lli long long int

void print(vector<vector<lli>> m) {
    lli l = m.size();
    lli c = m[0].size();

    for (lli i=0; i<l; i++) {
        for (lli j=0; j<c; j++) {
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }
}

lli solve(vector<vector<lli>> m, lli n, lli k) {

    // inicializando matriz de dp
    vector<vector<lli>> dp(n, vector<lli>(k, 0));;

    // copiando primeira linha
    for (lli j=0; j<k; j++) dp[0][j] = m[0][j];

    for (lli i=1; i<n; i++) {
        for (lli j=0; j<k; j++) {
            dp[i][j] = m[i][j];

            lli mx = 0;
            for (lli ant = 0; ant<k; ant++) {
                if (ant != j) {
                    mx = max(mx, dp[i-1][ant]);
                }
            }
            dp[i][j] += mx;
        }
    }

    // print(dp);

    // obtendo maior valor da ultima linha
    lli ans = 0;
    for (lli j=0; j<k; j++) ans = max(ans, dp[n-1][j]);

    return ans;
}

int main() {
    // lendo input
    lli n; cin >> n; // dias
    lli k; cin >> k; // produtos

    // matriz de custos
    vector<vector<lli>> m;

    for (lli i=0; i<n; i++) {
        vector<lli> t;
        for (lli j=0; j<k; j++) {
            lli temp; cin >> temp;
            t.push_back(temp);
        }
        m.push_back(t);
    }

    // obtendo resposta
    lli ans = solve(m, n, k);

    cout << ans << "\n";

    return 0;

}