#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, day, mon; cin>>n; vector<int> d(n);
    for(int i=0;i<n;i++) cin>>d[i];
    cin>>day>>mon;
    int i=0,j=0, sum=0, len=0, ans=0;
    while(i<n&&j<n)
    {
        if(d[j]+sum<=day) 
        {
          sum+=d[j], len++, j++;
          if(sum==day&&len==mon) ans++, sum-=d[i], len--, i++;
        }
        else sum-=d[i], len--, i++;
    }
    cout<<ans;
}
