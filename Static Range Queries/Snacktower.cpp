#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{

  FastIO;
  int n, tgt;
  cin >> n, tgt = n;
  vector<bool> frq(n + 1);
	
	for (int i = 0, x; i < n && cin >> x; i++)
	{
		frq[x] = 1;
		while (frq[tgt]) cout << tgt << " ", tgt--;
		cout << ((i != n - 1) ? "\n" : "");
	}
  
}