#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{

  FastIO;
  int n; cin >> n;
  vector<bool> isexist(n + 1);
  vector<int> ans;
	
	for (int i = 0, mx =0; i < n; i++)
	{
		for (int j = 0, x; j < n && cin >> x; j++)  mx = max(mx, x);

		if (!isexist[mx])
			ans.push_back(mx), isexist[mx] = 1;
		else 
			isexist[mx + 1] = 1, ans.push_back(mx + 1);

		mx = 0;
	}
	
	for (auto& it : ans) cout << it << " ";
  
}