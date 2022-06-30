#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
	FastIO;
	int n; cin >> n; stack<int> st;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		if (st.empty()) st.push(x);
		else {
			if (x == st.top() || !(abs(x - st.top()) & 1)) st.pop();
			else st.push(x);
		}
	}
	cout << ((st.sz <= 1) ? "YES" : "NO");
}

    
 
