#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    FastIO;
    int t, n; cin >> t;
	while (t-- && cin >> n)
	{
		vector<int> v(n), sfx[10];
		int indx1 = -1, indx2 = -1;
		for (auto& it : v) cin >> it;
		sfx[v[n - 1]].push_back(n - 1);
		for (int i = n - 2; i >= 0; i--)
		{
			for (int j = v[i] + 1; j <= 9; j++)
				if (!sfx[j].empty()) {
					indx1 = i, indx2 = j;
					break;
				}
			if (~indx1) break;
			sfx[v[i]].push_back(i);
		}
		if (~indx1)
		{
			swap(v[indx1], v[sfx[indx2].front()]);
			sort(v.begin() + indx1 + 1, v.end());
			for (auto& it : v) cout << it;
		}
		else cout << -1;
		cout << ((t) ? "\n" : "");
	}
}
