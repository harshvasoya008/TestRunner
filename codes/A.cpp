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
	int n,m;
	cin>>n>>m;

	if(m%n) {
		printf("-1\n");
		return 0;
	}

	int num = m/n;
	int x = 3;
	int cnt = 0;
	while (num > 1 && x > 1) {
		if (num%x==0) {
			num /= x;
			cnt++;
		} else {
			x--;
		}
	}

	if (num==1)
		printf("%d\n", cnt);
	else
		printf("-1\n");

    return 0;
}
