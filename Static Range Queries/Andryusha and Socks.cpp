#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    FastIO;
   
	int n, ans = 0, intable = 0; cin >> n;

	vector<bool> check(n + 1);

	for (int i = 0, val; i < n * 2 && cin >> val; i++)
		if (!check[val]) intable++, ans = max(ans, intable), check[val] = 1;
		else intable--, check[val] = 0;

	cout << ans;
}