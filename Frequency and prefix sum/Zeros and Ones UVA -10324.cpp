#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;  int cnt=1;
    while(cin>>s)
	{
        if(!s.size()) break;
		int n, a, b; cin>>n;
		vector<int> d(s.size());
		for (int i = 1; i < s.size(); i++)	{
			if (s[i] == s[i - 1]) d[i] = d[i - 1];
			else d[i] =i;
		}
		cout << "Case " << cnt++ << ":"<<"\n";
		while (n--)
		{
			cin >> a >> b;
		    cout<<((d[a] == d[b]) ? "Yes" : "No")<<"\n";
		}
	}
	return 0;
}