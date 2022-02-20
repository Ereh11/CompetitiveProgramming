#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin>>n; vector<int> d(n);
    for(int i=0;i<n;i++) cin>>d[i];
    int mn=d[0],mx=d[0], cntmn=0, cntmx=0;
    for(int i=1;i<n;i++)
    {
       if(d[i]>mx) mx=d[i], cntmx++;
       if(d[i]<mn) mn=d[i], cntmn++;
    }
    cout<<cntmx<<" "<<cntmn;
    return 0;
}
