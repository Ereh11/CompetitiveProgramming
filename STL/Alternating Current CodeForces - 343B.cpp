#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    FastIO;
    string s; cin >> s;
	stack<char> st;
	for (auto& it : s)
	{
		if (st.empty()) st.push(it);
		else
		{
			if (st.top() == '+' && it == '+' || st.top() == '-' && it == '-') st.pop();
			else st.push(it);
		}
	}
	cout << ((st.empty()) ? "Yes" : "No");
}
