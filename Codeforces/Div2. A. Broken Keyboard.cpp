#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;
int main()
{
    { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); } // to fast input and output.
    int t; cin >> t;
	while (t--)
	{
		string s, res; cin >> s; 
		vector<bool> isext(26);
		while(s.size()!=0)
		{
			if (!res.size()) 
			    res.push_back(s.back()), s.pop_back();
			else if(s.back() == res.back()) 
			        s.pop_back(), res.pop_back();
			else 
			   res.push_back('0'), res.push_back(s.back()), s.pop_back();
		}
		sort(res.begin(),res.end());
		for (int i = 0; i < res.size(); i++) 
		       if (res[i] != '0' && !isext[res[i] - 97]) 
		               cout << res[i], isext[res[i] - 97] = 1;
		if (t) cout << '\n';
	}
}
