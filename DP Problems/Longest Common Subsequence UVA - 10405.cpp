#include <bits/stdc++.h>
#define ll long long
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int dp[1001][1001];
string s1, s2;
int LCS(int i, int j)
{
	if (i == s1.size() || j == s2.size()) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	if (s1[i] == s2[j]) return dp[i][j] = 1 + LCS(i + 1, j + 1);
	return dp[i][j] = max(LCS(i, j + 1), LCS(i + 1, j));
}
int main()
{
    FastIO;
	while (getline(cin, s1) && getline(cin, s2))
	{
		memset(dp, -1, sizeof dp);
		cout << LCS(0, 0) << '\n';
	}
}