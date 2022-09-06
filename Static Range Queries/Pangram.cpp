#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    FastIO;
   
	int n; string s; cin >> n >> s;
	
	vector<bool> frq(26);

	for (auto& it : s) it = tolower(it), frq[it - 97] = 1;
	
	for (int i = 0; i < 26; i++) if (!frq[i]) return cout << "NO", 0;

	cout << "YES";
}