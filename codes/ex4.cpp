#include <bits/stdc++.h>

using namespace std;

#define long long int lli

void getSubconjunto(vector<int> polen, int pos, int n, vector<int>& values, int val) {

    if (pos >= n) return;

    for (int i = pos; i < n; i++) {
        int atual = polen[i];

        val += atual;

        values.push_back(val);

        getSubconjunto(polen, i + 1, n, values, val);

        val -= atual;
    }
}

int main() {
    
    // lendo input
    int n; cin >> n; // abelhas

    vector<int> polen;
    for (int i=0; i<n; i++) {
        int x; cin >> x;
        polen.push_back(x);
    }

    // obtendo valores de subconjuntos com backtracking
    vector<int> values;
    getSubconjunto(polen, 0, n, values, 0);

    // obtendo e imprimindo resposta
    unordered_set<int> ans;
    for (auto i = values.begin(); i != values.end(); ++i) {
        ans.insert(*i);
    }

    cout << ans.size() << "\n";

    return 0;

}