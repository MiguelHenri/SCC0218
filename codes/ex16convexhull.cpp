#include <bits/stdc++.h>

using namespace std;

#define int long long int

pair<int, int> ponto0;

double dist(pair<int, int> p, pair<int, int> q) {
    return sqrt(pow(p.first - q.first, 2) + pow(p.second - q.second, 2));
}

void print(stack<pair<int, int>> hull) {

    while (!hull.empty()) {
        pair<int, int> current = hull.top();
        hull.pop();

        cout << current.first << " " << current.second << "\n";
    }
}

int orientacao(pair<int, int> p, pair<int, int> q, pair<int, int> r) {
    // orientacao entre tres pontos p q r
    int val = (q.second - p.second) * (r.first - q.first) - (q.first - p.first) * (r.second - q.second);
    if (val == 0) return 0;  // pontos colineares
    return (val > 0) ? 1 : 2;  // horario / anti horario
}

int32_t compara(const void *vp, const void *vq) {

    const pair<int, int>* p = static_cast<const pair<int, int>*>(vp);
    const pair<int, int>* q = static_cast<const pair<int, int>*>(vq);

    // compara pontos p e q
    int o = orientacao(ponto0, *p, *q);

    if (o == 0) {
        return (dist(ponto0, *q) >= dist(ponto0, *p)) ? -1 : 1;
    }

    return (o == 2) ? -1 : 1;
}


pair<int, int> segundo(stack<pair<int, int>>& st) {
    // obtem o segundo elemento do topo da pilha
    pair<int, int> p = st.top();
    st.pop();
    pair<int, int> s = st.top();
    st.push(p);
    // retira o primeiro, obtem segundo e devolve primeiro
    return s;
}

stack<pair<int, int>> graham(vector<pair<int, int>> ovelhas) {
    // calcula o perimetro do menor poligono capaz de cercar as ovelhas
    // graham scan

    // encontrando a ovelha mais baixa e mais a esquerda
    int y_baixo = LLONG_MAX;
    int baixo = 0;
    for (int i = 0; i < ovelhas.size(); i++) {
        if (ovelhas[i].second < y_baixo) {
            y_baixo = ovelhas[i].second;
            baixo = i;
        }
    }

    // colocando o ponto mais baixo no inicio
    swap(ovelhas[0], ovelhas[baixo]);

    // ordenando
    ponto0 = ovelhas[0];
    // cout << "baixo: " << ponto0.first << " " << ponto0.second << "\n";
    qsort(&ovelhas[1], ovelhas.size()-1, sizeof(pair<int, int>), compara);

    int m = 1; // criaremos um array modificado
    for (int i = 1; i < ovelhas.size(); i++)
    {
        // remove se o angulo de i e i+1 eh igual em relacao ao ponto mais baixo
        while (i < ovelhas.size()-1 && orientacao(ponto0, ovelhas[i], ovelhas[i+1]) == 0) {
            i++;
        }
        ovelhas[m] = ovelhas[i];
        m++;
    }
    
    // cria pilha e coloca tres primeiras ovelhas
    stack<pair<int, int>> st;
    st.push(ovelhas[0]);
    st.push(ovelhas[1]);
    st.push(ovelhas[2]);
    
    // verifica ovelhas restantes
    for (int i = 3; i < m; i++){
        // remove enquanto faz curva a direita
        while (st.size()>1 && orientacao(segundo(st), st.top(), ovelhas[i]) != 2) {
            st.pop();
        }
        st.push(ovelhas[i]);
    }

    return st;

}

double solve(vector<pair<int, int>> ovelhas) {

    stack<pair<int, int>> hull = graham(ovelhas);

    // print(hull);

    // calculando perimetro
    double ans = 0;
    pair<int, int> first = hull.top();
    pair<int, int> last = hull.top();
    hull.pop();

    while (!hull.empty()) {
        pair<int, int> current = hull.top();
        hull.pop();

        ans += dist(current, last);
        last = current;
    }

    // Adiciona a distância entre o último e o primeiro ponto para fechar o perímetro
    ans += dist(first, last);

    return ans;
}

int32_t main() {
    // lendo input
    int n; cin >> n;

    // vetor com posicao de ovelhas
    vector<pair<int, int>> ovelhas;
    int x, y;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        ovelhas.push_back(make_pair(x, y));
    }

    double ans = solve(ovelhas);

    cout << fixed << setprecision(6) << ans;

    return 0;

}