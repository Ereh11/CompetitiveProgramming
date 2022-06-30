#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    FastIO;
    int n;
	while (cin >> n, n != 0)
	{
		queue<int> qu; vector<int> disc;
		for (int i = 1; i <= n; i++) qu.push(i);
		while (qu.size() > 1) {
			disc.push_back(qu.front()), qu.pop();
			qu.push(qu.front()), qu.pop();
		}
		cout << "Discarded cards:" << ((!disc.empty()) ? " " : "");
		for (int i = 0; i < disc.size(); i++) cout << disc[i] << ((i != disc.size() - 1) ? ", " : "");
		cout << "\nRemaining card: " << qu.front() << "\n";
	}
}
