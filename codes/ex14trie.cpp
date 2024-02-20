#include <bits/stdc++.h>

using namespace std;

#define int long long int

// solução usando estrutura Trie

class No {
public:
    unordered_map<char, No*> filhos;
    
    // numero de palavras q tem esse no como prefixo
    int cont;

    No() {
        cont = 0;
    }
};

class Trie {
public:
    No* raiz;

    Trie() {
        raiz = new No();
    }

    void adc(string pal) {
        No* no = raiz;

        for (char c : pal) {
            if (no->filhos.find(c) == no->filhos.end()) {
                // nao encontrou, cria
                no->filhos[c] = new No();
            }

            no = no->filhos[c];
        }

        no->cont++;
    }

    void rem(string pal) {
        No* no = raiz;

        // buscando palavra
        for (char c : pal) {
            auto it = no->filhos.find(c);

            if (it == no->filhos.end()) {
                // nao encontrou
                return;
            }

            no = it->second;
        }

        // palavra presente, remove
        if (no->cont > 0) {
            no->cont--;
        }
    }

    int ans(string prefixo) {
        No* no = raiz;

        int ans = 0;
        for (char c : prefixo) {
            auto it = no->filhos.find(c);
            if (it == no->filhos.end()) {
                // nao achou
                return 0;
            }
            no = it->second;
        }
        ans = no->cont;

        return ans;
    }

};

int32_t main() {
    // lendo input
    int t; cin >> t; // operacoes

    Trie trie;

    // lendo operacoes
    for (int i = 0; i < t; i++) {
        int op;
        string pal;

        cin >> op >> pal;

        // realizando operacao
        if (op == 1) {
            trie.adc(pal);
        }
        else if (op == 2) {
            trie.rem(pal);
        }
        else if (op == 3) {
            cout << trie.ans(pal) << "\n";
        }
    }

    return 0;

}