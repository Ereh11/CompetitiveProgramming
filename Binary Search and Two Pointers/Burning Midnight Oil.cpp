#include <bits/stdc++.h>
#define ll long long
#define FastIO ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
using namespace std;

bool check(int v, int n, int k)
{ 
    int cnt = 1; ll ans = v, su = v;
    
    while (ans)
        ans = v / (int)pow(k, cnt++), su += ans;
        
    return su >= n;
}
int main()
{
    FastIO;
    int n, k; cin >> n >> k;
 
    int l = 0, r = 1e9;
    while (l <= r)
    {
        int mid = ((l + r) >> 1);
        if (check(mid, n, k)) r = mid - 1;
        else l = mid + 1;
    }
 
    cout << l;
}