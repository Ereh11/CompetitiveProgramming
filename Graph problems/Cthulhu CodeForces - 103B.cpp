#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 101;
int cntnode = 0, cntCycle = 0;
vector<int> edge[N], vis;
void BFS()
{
	 queue<int> qu; qu.push(1);
	 while (!qu.empty())
	 {
		 int ft = qu.front();
		 qu.pop(), vis[ft] = 2, cntnode++;
		 for (auto& child : edge[ft]) 
		 {
			 if (!vis[child]) qu.push(child), vis[child] = 1;
			 else if(vis[child] == 1) cntCycle++;
		 }
	 }
}
int main()
{
	FastIO;
	int n, m; cin >> n >> m; vis.resize(n + 1);
	for (int i = 0, u, v; i<m && cin >> u >> v; i++) edge[v].push_back(u), edge[u].push_back(v);
    BFS();
	cout << ((cntnode == n && cntCycle == 1) ? "FHTAGN!" : "NO");
}