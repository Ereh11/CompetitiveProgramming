#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n; cin >> n; 
    vector<int>d(n), res;
    for (int i = 0; i < n; i++) cin>>d[i];
    for (int i = 0; i < n - 1; i++)
		if(d[i] >= d[i + 1]) res.push_back(d[i]);
    res.push_back(d.back());
    cout << res.size() <<'\n';
    for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
}