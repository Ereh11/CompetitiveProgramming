#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
#include <cmath>
#define ll long long
using namespace std;
int main()
{
	
	int n, cnt = 0; cin >> n; 
	vector<int> d(n), su(n + 1, 0);
	for (int i = 0; i < n; i++) 
	    cin >> d[i], su[i + 1] = d[i] + su[i];
	for (int i = 0; i < n-1; i++)
		(su[i + 1] == su[n] - su[i + 1]) ? cnt++ : 0;
	cout << cnt;
}