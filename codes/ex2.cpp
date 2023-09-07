#include <bits/stdc++.h>

using namespace std;

#define long long int lli

int main() {
    
    int n; cin >> n;

    // lendo palestras
    vector<pair<int, int>> p;
    for (int i=0; i<n; i++) {
        int l, r;
        cin >> l >> r;
        p.push_back(make_pair(r, l));
    }

    // ordenando com base nos horarios de fim
    sort(p.begin(), p.end());

    // percorrendo e contando resposta
    int tempo = 0;
    int contador = 0;
    for (int i=0; i<n; i++) {
        // horario que a palestra atual acaba
        int fim = p[i].first;
        // horario que a palestra atual comeca
        int comeco = p[i].second;

        if (comeco >= tempo) {
            tempo = fim;
            contador++;
        }
    }
    
    cout << contador << "\n";

    return 0;

}