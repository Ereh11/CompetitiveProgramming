#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    FastIO;
    string s; cin >> s; 
    vector<int> frq(100005);
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == s[i + 1]) frq[i + 1] = 1;
		else frq[i + 1] = 0;
		frq[i + 1] += frq[i];
	}
	frq[s.size()] = frq[s.size()] + 1;
	int q, l, r; cin >> q;
	while (q-- && cin >> l >> r)
		cout << frq[r-1] - frq[l-1] << ((q)? "\n": "");
}
