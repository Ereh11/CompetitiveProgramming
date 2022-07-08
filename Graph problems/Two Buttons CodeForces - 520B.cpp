#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 2 * 1e4 + 9;
vector<int> vis(N);
int BFS(int n, int m)
{
	queue<int> qu; 
	qu.push(n);
	while (!qu.empty()) {
		int ft = qu.front(); qu.pop();
		if (ft == m) break;
		if (ft - 1 >= 1 && !vis[ft - 1]) vis[ft - 1] = vis[ft] + 1, qu.push(ft - 1);
		if (ft * 2 <= m * 2 && !vis[ft * 2]) vis[ft * 2] = vis[ft] + 1, qu.push(ft * 2);
	}
	return vis[m];
}
int main()
{
	FastIO;
	int n, m; cin >> n >> m; 
	cout << BFS(n, m);
}