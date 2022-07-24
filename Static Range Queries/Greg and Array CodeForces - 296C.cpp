#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    FastIO;
    int n, m, q; cin >> n >> m >> q;
	vector<int> d(n); 
	for(auto& it: d) cin>> it;
	vector<pair<long long, pair<long long, long long>>> prq;
	
	for (int i = 0; i < m; i++)	{
		int fr, to, val; cin >> fr >> to >> val;
		prq.push_back({ val, { --fr,to } });
	}
	
	vector<long long> frq_wh(m + 1);
	
	for (int i = 0, x, y; i < q && cin >> x >> y; i++)frq_wh[--x]++, frq_wh[y]--;
	
	for (int i = 1; i <= m; i++) frq_wh[i] += frq_wh[i - 1];
	
	vector<long long> sum(n + 7);
	
	for (int i = 0; i < m; i++) {
		sum[prq[i].second.first] += prq[i].first * frq_wh[i];
		sum[prq[i].second.second] -= prq[i].first * frq_wh[i];
	}
	
	for (int i = 1; i < n; i++) sum[i] += sum[i - 1];
	
	for (int i = 0; i < n; i++) cout << d[i] + sum[i] << " ";
}

