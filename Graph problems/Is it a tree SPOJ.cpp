#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 1e4 + 1;
vector<int> edge[N];
vector<bool> vis;
queue<int> qu; int cntvis = 1;
void BFS()
{
	qu.push(1);
	while (!qu.empty())
	{
		int ft = qu.front(); 
		qu.pop(), vis[ft] = 1;
		for (auto& child : edge[ft])
			if (!vis[child]) qu.push(child), cntvis++;
	}
}
int main()
{
	FastIO;
	int n, m; cin >> n >> m; vis.resize(n + 1);
	for (int i = 0, x, y; i < m && cin >> x >> y; i++) edge[x].push_back(y), edge[y].push_back(x);
	BFS();
	cout << ((m == n - 1 && cntvis == n) ? "YES" : "NO");
}