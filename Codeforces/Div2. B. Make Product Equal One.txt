#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); } // to fast input and output.
    long long n, co = 0, neg = 0; cin >> n; vector<int> d(n);
	bool iszero = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> d[i];
		if (d[i] < 0) neg++;
		if (!d[i]) iszero = 1;
	}
	for (int i = 0; i < n; i++)
	{
		if (d[i] > 0) co += (d[i] - 1);
		else if(d[i] < 0) co += (abs(d[i]) - 1);
		else co++;
	}
	if ((neg & 1) && !iszero) co += 2;
	cout << co;
}
