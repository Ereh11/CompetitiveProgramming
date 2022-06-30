#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    FastIO;
    int t, n; cin >> t;
	while (t-- && cin >> n)
	{
		int indx = 0;  vector<int> v(n), pfx(n);
		for (auto& it : v) cin >> it;
		pfx[0] = v[0];
		for (int i = 1; i < n; i++) 
		{
			pfx[i] = max(pfx[i - 1], v[i]);
			if (pfx[i] != pfx[i - 1]) indx++;
		}
		vector<stack<int>> res(indx + 1); indx = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			res[indx].push(v[i]);
			if (v[i] == pfx[i])  indx++;
		}
		for (auto& it : res) while (!it.empty()) cout << it.top() << " ", it.pop();
		cout << ((t) ? "\n" : "");
	}
}
