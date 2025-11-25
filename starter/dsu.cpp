#include <bits/stdc++.h>
using namespace std;

vector<int> parent, sz;

int findSet(int v) {
    int root=parent[v];
    if(parent[root]!=root){
        return parent[v]=findSet(root);
    }
    return root;
}

void unionSet(int a, int b) {
    int i=findSet(a);
    int j=findSet(b);
    if(i==j)return;
    int Sizei=sz[i];
    int Sizej=sz[j];
    if(Sizei<Sizej){
        parent[i]=j;
        sz[j]+=sz[i];
    }
    else{
        parent[j]=i;
        sz[i]+=sz[j];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    parent.resize(n + 1);
    sz.resize(n + 1, 1);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    while (q--) {
        char type;
        int a, b;
        cin >> type >> a >> b;

        if (type == '+') {
            unionSet(a, b);
        } else if (type == '?') {
            if (findSet(a) == findSet(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}
