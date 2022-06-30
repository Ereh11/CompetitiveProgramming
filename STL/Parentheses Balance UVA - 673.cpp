#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    FastIO;
    int n, x; string s; 
	cin >> n;
	deque<int> dq; bool rev = 0;
	while (n-- && cin >> s)
	{
		if (s == "reverse") rev = !rev;

		if (s == "toFront" && !rev) cin >> x, dq.push_front(x);
		else if (s == "toFront" && rev)  cin >> x, dq.push_back(x);

		else if (s == "push_back" && !rev) cin >> x, dq.push_back(x);
		else if (s == "push_back" && rev) cin >> x, dq.push_front(x);

		else if (s == "front" && !rev) {
			if (dq.empty()) cout << "No job for Ada?\n";
			else cout << dq.front() << "\n", dq.pop_front();
		}
		else if (s == "front" && rev) {
			if (dq.empty()) cout << "No job for Ada?\n";
			else cout << dq.back() << "\n", dq.pop_back();
		}

		else if (s == "back" && !rev) {
			if (dq.empty()) cout << "No job for Ada?\n";
			else cout << dq.back() << "\n", dq.pop_back();
		}
		else if (s == "back" && rev) {
			if (dq.empty()) cout << "No job for Ada?\n";
			else cout << dq.front() << "\n", dq.pop_front();
		}
		
	}
}
