#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
const int N= 1e5 + 1;
vector<int> edge[N];
int pathnode = 0, mx = 0, dis[N];
void BFS(int node)
{
	queue<int>qu; int  mxpath = 0; 
	qu.push(node);  dis[node] = 0;
	while (!qu.empty())
	{
		int ft = qu.front(); qu.pop();
		if (dis[ft] > mxpath) mxpath = dis[ft], pathnode = ft;
		for (auto& child : edge[ft])
			if (!~dis[child]) qu.push(child), dis[child] = dis[ft] + 1;
	}
	mx = max(mx, mxpath); 
}
int main()
{
	FastIO;
	int n, m; cin >> n >> m; 
	memset(dis, -1, sizeof dis);
	for (int i = 0, u, v; i<m && cin >> u >> v; i++) edge[u].push_back(v), edge[v].push_back(u);
	BFS(1);
	memset(dis, -1, sizeof dis);
	BFS(pathnode);
	cout << mx;
}