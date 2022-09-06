#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    FastIO;
   
	int n, q, val; cin >> n >> q;

	vector<int> v(n), ans(n + 1);
	
	vector<bool> frq(1e5 + 1);

	for (auto& it : v) cin >> it;

	for (int i = n - 1; i >= 0; i--) {
		if (!frq[v[i]]) frq[v[i]] = 1, ans[i]++;
		ans[i] += ans[i + 1];
	}

	while (q-- && cin >> val) cout << ans[val - 1] << ((q) ? "\n" : "");
}