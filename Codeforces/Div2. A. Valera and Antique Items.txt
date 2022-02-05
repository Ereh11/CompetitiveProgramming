#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
int main()
{
    { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); } // to fast input and output.
    int n, v, co = 0, nu=0; cin >> n >> v; vector<int> sl;
	for (int i = 1; i <= n; i++)
	{
		cin >> nu; vector<int> d(nu);
		for (int i = 0; i < nu; i++) cin >> d[i];
		if (*min_element(d.begin(), d.end()) < v) co++, sl.push_back(i);
	}
	cout << co << '\n';
	for (int i = 0; i < sl.size(); i++) cout << sl[i] << " ";
}
