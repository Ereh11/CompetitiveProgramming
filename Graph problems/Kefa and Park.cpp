#include <bits/stdc++.h>
#define ll long long
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 1e5 + 2;
vector<int>  edge[N], cats;
vector<bool> vis;
int m, ans = 0, cnt = 0;
void DFS(int node, int parent)
{
    vis[node] = 1; bool flg = 0;
    if (cats[node]) cats[node] += cats[parent];
    if (cats[node] > m) return;

    for (auto& child : edge[node])
        if (!vis[child]) flg = 1, DFS(child, node);

    ans += (!flg);

}
int main()
{
    FastIO;
    int n; cin >> n >> m;
    cats.resize(n + 1), vis.resize(n + 1);

    for (int i = 1, x; i <= n; i++) cin >> x, cats[i] = x;
    for (int i = 1, u, v; i < n; i++)
        cin >> u >> v, edge[u].push_back(v), edge[v].push_back(u);

    DFS(1, 0);
    cout << ans;
}