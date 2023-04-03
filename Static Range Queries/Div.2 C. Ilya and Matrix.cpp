#include <bits/stdc++.h>
#define ll long long
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    FastIO;
    int n; cin >> n; ll mx=0; vector<ll> d(n), su(n + 1);
	ll sum = 0;
	for (int i = 0; i < n; i++) cin >> d[i], mx=max(d[i], mx);
	sort(d.begin(),d.end(), greater<ll>());
	for (int i = 0; i < n; i++) su[i + 1] = d[i] + su[i];
	for (int i = 1; i <= n; i *=4) sum += su[i];
	cout << sum;
}
