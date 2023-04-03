#include <bits/stdc++.h>
#define FastIO {ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);}
using namespace std;
const int N=1e4+1;
int main()
{
	FastIO;
	int n, q; cin >> n; vector<int> v(n), prfx(n + 1);
	for (int i = 0; i < n; i++) cin >> v[i];
	for (int i = 0; i < n; i++) prfx[i] = v[i] + prfx[max(0, i - 1)];
	cin >> q;
	while (q--)
	{
		int x, y; cin >> x >> y;
		cout << prfx[max(y, x)] - ((min(y, x) == 0) ? 0 : prfx[min(y, x) - 1]) << "\n";
	}
}
