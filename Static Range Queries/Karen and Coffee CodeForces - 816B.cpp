#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    FastIO;
    int n, k, q, l, r; cin >> n >> k >> q;
	vector<int> v(200001), ans(200001);

	for (int i = 0; i < n && cin >> l >> r; i++) v[l]++, v[r + 1]--;
	for (int i = 1; i < v.size(); i++) 
		v[i] += v[i - 1], ans[i] = ans[i - 1] + (v[i] >=k);

	while (q-- && cin >> l >> r)
		cout << ans[r] - ans[l-1] << ((q) ? "\n" : "");
}