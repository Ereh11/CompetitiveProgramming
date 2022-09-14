#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    FastIO;
    int n; long long sum = 0; cin >> n;
    
	vector<int> v(n), ans;
	
	unordered_map<double, int> isexist;

	for (auto& it : v) cin >> it, isexist[it]++, sum += it;

	for (int i = 0; i < n; i++) {

		sum -= v[i], isexist[v[i]]--;

		if (isexist[sum / 2.0]) ans.push_back(i + 1);

		sum += v[i], isexist[v[i]]++;
	}

	if (ans.empty()) return cout << "0\n", 0;

	cout << ans.size() << "\n";
	
	for (auto& it : ans) cout << it << " ";
}
