#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    FastIO;
   
	int n, k; string s, res; cin >> n >> k >> s;
	
	vector<int> frq(26);

	for (auto& it : s) frq[it - 97]++;

	for (int i = 0; i < 26; i++)
		while (k && frq[i]) frq[i]--, k--;

	for (int i = s.size() - 1; i >= 0; i--)
		((frq[s[i] - 97]) ? frq[s[i] - 97]-- : s[i] = 48);

	for (auto& it : s) if (it != 48) cout << it;
}