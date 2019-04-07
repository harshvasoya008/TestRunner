//
// Author: Harsh_Vasoya, DA-IICT
//

#include <bits/stdc++.h>

#define sync_off std::ios_base::sync_with_stdio(false); cin.tie(NULL);
#define lli long long int
#define hashmap unordered_map
#define hashset unordered_set

#define all(v) v.begin(),v.end()
#define contains(x,a) (x).find(a)!=(x).end()
#define pb push_back

#define pii pair<int,int>
#define mp make_pair
#define F first
#define S second

#define si(n)	 scanf("%d",&n)
#define sii(n,m) scanf("%d%d",&n,&m)
#define slli(n)  scanf("%lld",&n)
#define forn(i,a,b) for(int i=a;i<b;i++)

const int mod = 10000009;
const lli MOD = 1000000007;
const int INF = INT_MAX;
int DEBUG = 0;

using namespace std;

int main()
{
	vector<lli> pow2;
	lli y=1;
	while(y<=(lli)1e10){
		pow2.pb(y);
		y *= (lli)2;
	}

	int n;
	si(n);

	lli a[n];
	forn(i,0,n)
		slli(a[i]);

	sort(a,a+n);

	vector<lli> v[n];
	int max_size = -1;
	int idx = -1;

	forn(i,0,n){
		if(i==0){
			v[0].pb(a[0]);
			max_size = 1;
			idx = 0;
			continue;
		}

		for(lli x : pow2){
			if(*lower_bound(a,a+i+1,a[i]-x) == a[i]-x)
				v[i].pb(a[i]-x);
		}

		v[i].pb(a[i]);

		if(v[i].size() > max_size){
			max_size = v[i].size();
			idx = i;
		}
	}

	printf("%d\n", v[idx].size());
	for(lli x: v[idx])
		printf("%lld ", x);

    return 0;
}
