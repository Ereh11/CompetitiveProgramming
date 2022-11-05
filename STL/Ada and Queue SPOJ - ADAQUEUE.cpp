#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    FastIO;
    int n, x; string s; cin >> n;
    deque<int> dq; bool ok = 1;
    while (n-- && cin >> s)
	{
		 if (s == "reverse") ok = !ok;
		 else if (s == "front")
		 {
			 if (dq.empty()) cout << "No job for Ada?";
			 else if (ok)  cout << dq.front(), dq.pop_front();
			 else cout << dq.back(), dq.pop_back();
			 cout << "\n";
		 }
		 else if (s == "back") 
		 {
			 if (dq.empty()) cout << "No job for Ada?";
			 else if (ok)  cout << dq.back(), dq.pop_back();
			 else cout << dq.front(), dq.pop_front();
			 cout << "\n";
		 }
		 else if (s == "toFront")
			 cin >> x, ((ok) ? dq.push_front(x) : dq.push_back(x));
		 else 
			 cin >> x, ((ok) ? dq.push_back(x) : dq.push_front(x));
	}
}
