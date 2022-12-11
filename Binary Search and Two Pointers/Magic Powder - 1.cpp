#include <bits/stdc++.h>
using namespace std;

void FASTIO()
{
    ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
}

bool BS(int k, vector<int>& a, vector<int>& b, int ans)
{
 
    for (int i = 0; i < a.size(); i++)
    {
        int need = a[i] * ans;
        if (need > b[i] && k < need - b[i]) return 0;
        else if (need > b[i] && k >= need - b[i]) k -= (need - b[i]);
    }
 
    return 1;
}

int main()
{
	FASTIO();
 
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto& it : a) cin >> it;
    for (auto& it : b) cin >> it;
 
    int st = 0, en = 2005;
 
    while (st <= en)
    {
        int mid = ((st + en) >> 1);
        (BS(k, a, b, mid) ? st = mid + 1 : en = mid - 1);
    }
 
    cout << st - 1;
}