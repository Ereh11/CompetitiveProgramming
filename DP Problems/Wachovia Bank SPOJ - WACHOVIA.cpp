#include <bits/stdc++.h>
#define ll long long
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
const int  N = 1e3 + 7;
vector<pair<int, int>> d; 
int dp[201][N];
int Kidnape(int i, int w)
{
	if (i == d.size()) return 0;
	if (dp[i][w] != -1) return dp[i][w];
	int op1 = (d[i].first <= w) ? d[i].second + Kidnape(i + 1, w - d[i].first) : 0;
	int op2 = Kidnape(i + 1, w);
	return dp[i][w] = max(op1, op2);
}
int main()
{
	FastIO;
	int t; cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int n, k; cin >> k >> n; d.resize(n); 
		memset(dp, -1, sizeof dp);
		for (int i = 0; i < n; i++) cin >> d[i].first >> d[i].second;
		cout << "Hey stupid robber, you can get " << Kidnape(0, k) << '.' << '\n';
	}
}