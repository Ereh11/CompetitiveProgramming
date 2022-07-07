#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 1e4 + 1;
vector<int> edge[N];
vector<bool> vis;
void DFS(int node)
{
	vis[node] = 1;
	for (auto& child : edge[node])
		if (!vis[child]) DFS(child);
}
int main()
{
	FastIO;
	int n, cntComponent = 0; cin >> n; vis.resize(n + 1);
	for (int i = 1, x; i <= n && cin >> x; i++) 
	    edge[i].push_back(x), edge[x].push_back(i);
	for (int i = 1; i <= n; i++) 
	    if (!vis[i]) DFS(i), cntComponent++;
	cout << cntComponent;
}