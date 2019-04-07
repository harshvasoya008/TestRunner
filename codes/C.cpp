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

template<class T1,class T2>ostream&operator<<(ostream& os,const pair<T1,T2>&p){os<<"["<<p.first<<","<<p.second<<"]";return os;}
template<class T>ostream&operator<<(ostream& os,const vector<T>&v){os << "[";bool first=true;for (T it:v){if (!first)os<<", ";first = false;os<<it;}os<<"]";return os;}
template<class T>ostream&operator<<(ostream& os,set<T>&v){os<<"[";bool first=true;for (T it:v){if(!first)os<<", ";first=false;os<<it;}os<<"]";return os;}
template<class T1,class T2>ostream&operator<<(ostream& os,map<T1,T2>&v){os<<"[";bool first=true;for(pair<T1,T2> it:v){if(!first)os<<", ";first=false;os<<"("<<it.F<<","<<it.S<<")";}os<<"]";return os;}
template<class T1,class T2>ostream&operator<<(ostream& os,unordered_map<T1,T2>&v){os<<"[";bool first=true;for(pair<T1,T2> it:v){if(!first)os<<", ";first=false;os<<"("<<it.F<<","<<it.S<<")";}os<<"]";return os;}
void print_arr(lli arr[],int n){cout<<("[");forn(i,0,n){cout<<(arr[i]);if(i!=n-1) cout<<(", ");}cout<<("]\n");}

bool comp(pii &a, pii &b) {
	if (a.S == b.S && a.S < 0)
		return true;

	return abs(a.S) > abs(b.S);
}

int main()
{
	int n;
	si(n);

	lli p[n], minP=0, maxP=0;
	p[0] = 0L;

	forn(i,1,n) {
		int qi;
		si(qi);
		p[i] = p[i-1] + qi;
		minP = min(minP, p[i]);
		maxP = max(maxP, p[i]);	
	}

	if (1-minP != n-maxP) {
		printf("-1\n");
		return 0;
	}

	lli x = 1-minP;
	hashmap<int,bool> vis;

	forn(i,0,n) {
		p[i] += x;
		if (p[i] < 1 || p[i] > n || vis[p[i]]) {
			printf("-1\n");
			return 0;
		}

		vis[p[i]] = true;
	}

	forn(i,0,n)
		printf("%lld ", p[i]);

    return 0;
}
