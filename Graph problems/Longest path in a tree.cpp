#include <bits/stdc++.h>
#define ll long long
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 1e4 + 2;
vector<int>  edge[N];
vector<bool> vis;
int FarNode = 0, LongestDis = 0;
void DFS(int node, int dis)
{
    vis[node] = 1;
    for (auto& child : edge[node])
        if (!vis[child]) DFS(child, dis + 1);

    if (dis > LongestDis) LongestDis = dis, FarNode = node;
}
int main()
{
    FastIO;
    int n; cin >> n;

    vis.resize(n + 1);
    for (int i = 1, u, v; i < n; i++)
        cin >> u >> v, edge[u].push_back(v), edge[v].push_back(u);

    DFS(1, 0), LongestDis = 0, vis = vector<bool>(n + 1);
    DFS(FarNode, 0);

    cout << LongestDis;
}