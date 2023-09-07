#include <bits/stdc++.h>

using namespace std;

int main() {
    // mapeando alunos por valor do curso
    map<int, int> m;

    // lendo entrada e tratando dados
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        // alunos que fizeram cadastro num curso i
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int t; cin >> t;

            // checando se o aluno t ja fez cadastro em outro curso
            if (m[t] == 0) // nao fez cadastro
                m[t] = i;

            else if (m[t] != i) // se cadastrou em outro curso
                m[t] = -1;

        }
    }

    // obtendo resposta
    vector<int> resp(n+1, 0);
    for (auto it = m.begin(); it != m.end(); ++it) {
        int temp = it->second;
        if (temp != -1) resp[temp] += 1;
    }

    for (int i = 1; i < n; i++) {
        cout << resp[i] << " ";
    }
    cout << resp[n] << "\n";

    return 0;

}