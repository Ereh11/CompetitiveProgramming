#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    FastIO;
    int n; cin >> n; stack<int> st; vector<int> v(n), ans(n);
	for (auto& it : v) cin >> it;
	for (int i = n - 1; i >= 0; i--)
	{
		while (!st.empty() && st.top() <= v[i]) st.pop();
		ans[i] = st.empty() ? -1 : st.top();
		st.push(v[i]);
	}
	for (int i = 0; i < n; i++) cout << ans[i] << ((i != n - 1) ? " " : "");
}
