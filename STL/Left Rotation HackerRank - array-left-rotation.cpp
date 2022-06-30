#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    FastIO;
    int n, m; cin >> n >> m; queue<pair<int, int>> qu;
	for (int i = 1, x; i <= n; i++) cin >> x, qu.push({i, x});
	while (qu.size() > 1) 
	{
		if (qu.front().second > m) qu.push({qu.front().first, qu.front().second - m});
		qu.pop();
	}
	cout << qu.front().first;
}
