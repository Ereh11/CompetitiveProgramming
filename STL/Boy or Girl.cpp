#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{
    FastIO;
    vector<bool> v(26);

	int ans = 0; string s; cin >> s;

	for (auto& it : s) if (!v[it - 97]) v[it - 97] = 1, ans++;

	cout << ((ans & 1) ? "IGNORE HIM!" : "CHAT WITH HER!");
    
}