#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{

  FastIO;
  int n; cin >> n;
  vector<int> v(3);
 
	for (int i = 0, x; i<n && cin >> x; i++) v[i % 3] += x;
 
	if (v[0] == *max_element(v.begin(), v.end())) cout << "chest";
	else cout << ((v[1] == *max_element(v.begin(), v.end())) ? "biceps" : "back");
  
}