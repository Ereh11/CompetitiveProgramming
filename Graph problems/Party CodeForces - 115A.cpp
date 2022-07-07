#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 2001;
vector<int> edge[N];
vector<bool> vis;
int mxpath = 0;
void DFS(int node, int legnth)
{
	vis[node] = 1;
	for (auto& child : edge[node])
		if (!vis[child]) DFS(child, 1 + legnth);
	mxpath = max(mxpath, legnth);
}

int main()
{
	FastIO;
	int n; cin >> n; vis.resize(n + 1);
	for (int i = 1, x; i <= n && cin >> x; i++) edge[max(x, 0)].push_back(i);
	for (int i = 0; i <= n; i++) if (!vis[i]) DFS(i, 0);
	cout << mxpath;
}