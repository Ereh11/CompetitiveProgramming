#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
	FastIO;
	// using monotonicstack
	int n; cin >> n; stack<int> st; vector<int> res(n), v(n);
	for(auto&it:v) cin>>it;
	for (int i = n-1; i >=0; i--)
	{
		while (!st.empty() && st.top() <= v[i]) st.pop();
		res[i] = st.empty() ? -1 : st.top();
		st.push(v[i]);
	}
	for (auto& it : res) cout << it << " ";
}

    
 
