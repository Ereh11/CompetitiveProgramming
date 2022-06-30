#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    FastIO;
    int t, type, x; cin >> t;
	deque<int> dq;
	while (t-- && cin >> type)
	{
		if (type == 1) cin >> x, dq.push_back(x);
		else if (type == 2) { if (!dq.empty()) dq.pop_front(); }
		else
		{
			if (!dq.empty()) cout << dq.front() << "\n";
			else cout << "Empty!" << "\n";
		}
	}
}
