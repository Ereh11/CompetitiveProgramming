#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;
int main()
{
    int t; cin >> t;
	while (t--)
	{
		int n, sumd = 0, sumr = 0, co = 0; cin >> n; vector<int> d(n), res(n);
		for (int i = 0; i < n; i++) cin >> d[i], sumd += d[i];
		for (int i = 0; i < n; i++) cin >> res[i], sumr += res[i];
		if (sumr != sumd) cout << -1;
		else
		{
			vector<pair<pair<int,int>,int>>dec, inc;
			for (int i = 0; i < n; i++)
			{
				if (d[i] < res[i]) inc.push_back({ {d[i], res[i]},i + 1 }), co += abs(d[i] - res[i]);
				else if(d[i] > res[i]) dec.push_back({ {d[i], res[i]},i + 1 });
			}
			cout << co << '\n';
			for (int i = 0; i < dec.size(); i++)
			{
				while (dec[i].first.first > dec[i].first.second)
				{
					cout << dec[i].second << " ";
					if (inc.back().first.first < inc.back().first.second) cout << inc.back().second << '\n', inc.back().first.first++;
					else
					{  inc.pop_back(); cout << inc.back().second <<'\n', inc.back().first.first++; }
					dec[i].first.first--;
				}
			}
		}
		if (t) cout << '\n';
	}
}
