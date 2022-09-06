#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    FastIO;
   
	int n, val; cin >> n; 
	vector<int> frq(3);
	
	while (n-- && cin >> val) frq[val % 3]++;
	
	cout << frq[0] / 2 + min(frq[1], frq[2]);
}