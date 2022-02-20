#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, ans=0; cin>>n>>k;
    vector<int>d(n);
    for(int i=0;i<n;i++) cin>>d[i];
    for(int i=0;i<n;i++)
       for(int j=i+1;j<n;j++){
           if(!((d[i]+d[j])%k)) ans++;
       }
    cout<<ans;   
}
