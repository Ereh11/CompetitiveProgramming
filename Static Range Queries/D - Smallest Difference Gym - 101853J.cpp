#include <bits/stdc++.h>
#define FastIO {ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);}
using namespace std;
const int N=1e4+1;
int main()
{
	FastIO;
	int t; cin >> t;
	while (t--)
	{
		int n, mx = 0; cin >> n; vector<int> v(n), frq(N);
		for (int i = 0; i < n; i++) cin >> v[i], frq[v[i]]++;
		for (int i = 0; i < n; i++)
			mx = max(mx, (frq[v[i]] + frq[v[i] + 1]));
		cout << mx << ((t) ? "\n" : "");
	}
}
