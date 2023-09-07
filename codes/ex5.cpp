#include <bits/stdc++.h>

using namespace std;

#define int long long int

int merge(vector<int>& v, vector<int>& aux, int left, int right) {
    // une os vetores e conta inversoes
    int mid = ((left + right)/2) + 1;
    int count = 0;

    int l = left; int r = left;
    int m = mid;

    while ((l <= mid - 1) && (m <= right)) {
        if (v[l] <= v[m]) {
            aux[r++] = v[l++];
        }
        else {
            aux[r++] = v[m++];
 
            count += mid - l;
        }
    }

    while (l <= mid - 1) {
        aux[r++] = v[l++];
    }
 
    while (m <= right) {
        aux[r++] = v[m++];
    }
 
    for (int i = left; i <= right; i++) {
        v[i] = aux[i];
    }
 
    return count;
}

int mergeAux(vector<int>& v, vector<int>& aux, int l, int r) {
    // conta numero de inversoes
    int count = 0;

    if (r > l) {
        int mid = (l + r)/2;

        count += mergeAux(v, aux, l, mid);
        count += mergeAux(v, aux, mid+1, r);

        count += merge(v, aux, l, r);
    }

    return count;
}

int mergeSort(vector<int>& v, int n) {
    // chama mergeAux
    vector<int> aux(n+1);
    return mergeAux(v, aux, 0, n-1);
}

int32_t main() {
    // lendo input
    int n; cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        int aux; cin >> aux;
        v.push_back(aux);
    }

    // obtendo resposta
    int ans = mergeSort(v, n);

    cout << ans << "\n";

    return 0;

}