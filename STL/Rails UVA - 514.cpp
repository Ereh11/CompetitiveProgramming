#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    FastIO;
    int n, x; cin >> n;
	while (n)
	{
		queue<int> qu; stack<int> st; int indx = 1;
		for (int i = 1; i <= n; i++)
		{
			cin >> x; if (!x) break;
			st.push(i), qu.push(x);
			while (!st.empty() && !qu.empty() && (qu.front() == st.top())) st.pop(), qu.pop();
		}
		if (!x) cin >> n;
		else cout << ((qu.empty()) ? "Yes" : "No");
		cout<< "\n";
	}
}
