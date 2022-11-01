#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{
    FastIO;
    int n; string s; cin >> n; unordered_map<string, int> ump;

	cin.ignore();

	while (n--)
		getline(cin, s), ump[s]++;

	cout << ump.sz;
    
}