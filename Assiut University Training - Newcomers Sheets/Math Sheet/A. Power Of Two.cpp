#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
#include <cmath>
#define ll long long
using namespace std;
int main()
{
	
    ll n; cin >> n;
	cout << (((int)log2(n) == log2(n)) ? "YES" : "NO");
}