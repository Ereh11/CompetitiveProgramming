#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{

    FastIO;
    int n, q;
    cin >> n;
    vector<long long> v(n + 1), reord(n + 1);

	for (int i = 1; i <= n; i++) cin >> v[i];
	reord = v, sort(reord.begin(), reord.end());

	for (int i = 1; i <= n; i++) v[i] += v[i - 1], reord[i] += reord[i - 1];

	cin >> q;
	for (int i = 0, type, l, r; i < q && cin >> type >> l >> r; i++)
		cout << ((type == 1) ? v[r] - v[l - 1] : reord[r] - reord[l - 1]) << ((i != q - 1) ? "\n" : "");
  
}