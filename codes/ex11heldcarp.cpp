#include <bits/stdc++.h>

using namespace std;

#define int long long int

int solve(vector<vector<pair<int, int>>> g, int n) {
    // algoritimo de held-carp para solucionar o problema:

    // matriz de dp
    vector<vector<int>> dp(1 << n, vector<int>(n+1, INT_MAX));
    dp[1][1] = 0; // caso base

    // loop nos subconjuntos de trilhas usando bitmask
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 1; i <= n; i++) {
            if ((mask & (1 << (i-1))) != 0) {
                for (const auto& edge : g[i]) {
                    int j = edge.first;
                    int dist = edge.second;
                    if ((mask & (1 << (j-1))) != 0) {
                        dp[mask][i] = min(dp[mask][i], dp[mask ^ (1 << (i-1))][j] + dist);
                    }
                }
            }
        }
    }

    // obtendo resposta
    int ans = INT_MAX;
    for (int i = 2; i <= n; ++i) {
        ans = min(ans, dp[(1 << n) - 1][i]);
    }

    return (ans == INT_MAX) ? -1 : ans;
}

int32_t main() {
    // lendo input
    int n; cin >> n; // vertices
    int m; cin >> m; // arestas

    // grafo, lista de adj
    vector<vector<pair<int, int>>> g(n+1);

    for (int i = 0; i < m; i++) {
        // lendo arestas
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back(make_pair(b, w));
        g[b].push_back(make_pair(a, w));
    }

    // resolve e printa valor
    int ans = solve(g, n);

    cout << ans << "\n";

    return 0;

}