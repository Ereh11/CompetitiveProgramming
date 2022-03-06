#include <bits/stdc++.h>
#define ll long long
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
const int  N = 1e4 + 1;
vector<int> d; 
ll dp[N];
ll Farida(int i)
{
	if (i >= d.size()) return 0;
	if (dp[i] != -1) return dp[i];
	return dp[i] = max(d[i] + Farida(i + 2), Farida(i + 1));
}
int main()
{
	FastIO;
	int t; cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int n; cin >> n; d.resize(n); memset(dp, -1, sizeof dp);
		for(int i=0;i<n;i++) cin>>d[i];
		cout << "Case " << i << ": " << Farida(0) << '\n';
	}
}