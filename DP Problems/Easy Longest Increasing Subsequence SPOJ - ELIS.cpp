#include <bits/stdc++.h>
#define ll long long
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int dp[11][11];
vector<int> v;
int LIS(int i, int indx)
{
	if (i == v.size()-1) return 0;
	if (dp[i][indx] != -1) return dp[i][indx];
	return dp[i][indx] = max(((v[i] > v[indx]) ? 1 + LIS(i + 1, i) : 0), LIS(i + 1, indx));
}
int main()
{
    FastIO;
    memset(dp, -1, sizeof dp);
	int n; cin >> n; v.resize(n + 1); 
	for(int i=0;i<n;i++) cin>>v[i];
	cout << LIS(0, n);
}
