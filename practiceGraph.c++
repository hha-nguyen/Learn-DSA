#include <bits/stdc++.h>
using namespace std;

#define N 100001
int V_num, E_num, cnt, flag = 0;
vector<int> a[N];
int Visited[N], Parent[N];

void visit(int u) {
    Visited[u] = ++cnt; 
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (v != Parent[u]) {
            if (!Visited[v]) {
                Parent[v] = u;
                visit(v);
            }
            else {
                    flag = 1;
                    return;
            }
        }
    }
}

int main() {
    cin >> V_num >> E_num;
    for (int i = 1; i <= E_num; i++) {
        int v, w;
        cin >> v >> w;
        a[v].push_back(w);
        a[w].push_back(v);
      }
    for (int i = 1; i <= V_num; i++) if (!Visited[i]) visit(i);
    if(flag) cout << "YES";
    else cout << "NO";
}