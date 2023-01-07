#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
bool check(ll Brd, ll Sag, ll Chs, vector<ll> &a, vector<ll> &b, ll amount, ll money)
{
	ll amountBrd = amount * Brd, amountSag = amount * Sag, amountChs = amount * Chs; 
	if (amountBrd > a[0]) amountBrd-= a[0], money -= (b[0] * amountBrd);
	if (amountSag > a[1]) amountSag-= a[1], money -= (b[1] * amountSag);
	if (amountChs > a[2]) amountChs-= a[2], money -= (b[2] * amountChs);
	return (money < 0) ? false : true;
}
ll BS(ll Brd, ll Sag, ll Chs)
{
	ll st= 1, en= (ll)(1e14), mid, money;
 
	vector<ll> a(3), b(3); 
 
	for (auto &it : a) cin >> it;
	for (auto &it : b) cin >> it;
 
	cin >> money;
 
	while(st <= en)
	{
		mid = (st + en) /2;
		((check(Brd, Sag, Chs, a, b, mid, money)) ? st = (mid + 1) : en = (mid - 1));
	}
	return (st - 1);
}
int main() 
{
	
	string s; cin>> s;
	ll Brd= 0, Sag= 0, Chs= 0;
	for(auto &it: s)
		if(it =='B') Brd++; else ((it =='S')? Sag++ : Chs++);
	cout<< BS(Brd, Sag, Chs);
}