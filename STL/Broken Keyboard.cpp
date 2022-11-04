#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{
    FastIO;
    string s;
	while (cin >> s)
	{
		list<char> lt; auto it = lt.end();

		for (auto& t : s)
			if (t == '[') it = lt.begin();
			else if (t == ']') it = lt.end();
			else lt.insert(it, t);

		for (auto& it : lt) cout << it;
		cout << "\n";
	}
    
}