#include <bits/stdc++.h>
#define FastIO {ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);}
using namespace std;
const int N=5e4+1;
vector<bool> vis, v[N]; 
int cnt = 0, mx = 0, n, m;
void DFS(int node)
{
	vis[node] = 1, cnt++;
	for (auto child : v[node])
		if (!vis[child]) DFS(child);
}
void CL() { for (int i = 0; i < n; i++) v[i].clear(); vis.clear(); }
int main()
{
    FastIO;
	while (cin >> n >> m, n || m)
	{
		string a, b; CL(); vis.resize(n + 1);
		map<string, int> mp;
		for (int i = 0; i < n; i++) cin >> a, mp[a] = i;
		while (m--)
		{
			cin >> a >> b;
			v[mp[a]].push_back(mp[b]), v[mp[b]].push_back(mp[a]);
		}
		for (int i = 0; i < n; i++)
			if (!vis[i]) DFS(i), mx = max(cnt, mx), cnt = 0;
		cout << mx << "\n", mx = 0;
	}
}
