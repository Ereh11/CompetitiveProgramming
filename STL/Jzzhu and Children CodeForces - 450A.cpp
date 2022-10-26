#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    FastIO;
   int n, m; cin >> n >> m;
   queue<pair<int, int>> qu;
   for (int i = 1, x; i <= n && cin >> x; i++) qu.push({ x, i });
   while (qu.sz > 1)
        {
	    if (qu.front().first <= m) qu.pop();
	    else qu.push({qu.front().first - m, qu.front().second}), qu.pop();
	}
   cout << qu.front().second;
}
