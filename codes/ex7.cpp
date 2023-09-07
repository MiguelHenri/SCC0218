#include <bits/stdc++.h>

using namespace std;

#define lli long long int

struct edge {
    int source;
    int dest;
    int weight;
};

typedef struct edge Edge;

bool compareEdge(Edge a, Edge b) {
    return (a.weight < b.weight);
}

int find(vector<int>& p, int u) {
    if (p[u] == -1) return u;
    return p[u] = find(p, p[u]);
}

void onion(vector<int>& p, vector<int>& r, int u, int v) {
    if (u != v) {
        if (r[u] == r[v]) {
            p[v] = u;
            r[u] += 1;
        }
        else if (r[u] > r[v]) {
            p[v] = u;
        }
        else { // r[u] < r[v]
            p[u] = v;
        }
    }
}

lli solve(int n, int m, vector<Edge> v) {
    // arvore geradora minima de Kruskal
    lli ans = 0;
    // ordanando arestas por peso
    sort(v.begin(), v.end(), compareEdge);

    // percorrendo arestas
    vector<int> p(n + 1, -1);
    vector<int> r(n + 1, 0);
    for (auto e : v) {
        // checa se ha ciclo
        // usando union (onion) find
        int a = find(p, e.source);
        int b = find(p, e.dest);
        if (a != b) {
            onion(p, r, a, b);
            ans += e.weight;
        }
    }
    return ans;
}

int main() {
    // lendo input
    int n; cin >> n; // vertices
    int m; cin >> m; // arestas

    // vetor com as arestas
    vector<Edge> v;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a;
        cin >> b;
        cin >> c;
        v.push_back(Edge{a, b, c});
    }

    // obtendo resposta
    lli ans = solve(n, m, v);

    cout << ans << "\n";

    return 0;

}