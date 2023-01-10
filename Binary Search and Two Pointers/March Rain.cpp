#include <bits/stdc++.h>
#define ll long long
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;
bool Can(int val, int k, vector<int>& v)
{
    int cnt = 1, pref = v[0];
    for (int i = 1; i < v.size(); i++)
        if (v[i] - pref + 1 > val)  cnt++, pref = v[i];

    return cnt <= k;
}
int main()
{
    FastIO;
    int t = 1;  cin >> t;
    while(t--)
    {
        int n, k; cin >> n >> k;
        vector<int> v(n);

        for (auto& it : v) cin >> it;
    

        int l = 0, r = 1e9;
        while (l <= r)
        {
            int mid = ((l + r) >> 1);
            if (Can(mid, k, v)) r = mid - 1;
            else l = mid + 1;
        }

        cout << l;

        cout << (t ? "\n" : "");
    }
}