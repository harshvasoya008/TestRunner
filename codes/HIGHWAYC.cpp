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

typedef struct Car{
	int vel;
	int dir;
	int pos;
	int len;
}T;

int main()
{
	sync_off

	int test;
	cin>>test;
	while(test--){
		int n,s,y;
		cin>>n>>s>>y;

		T cars[n];
		forn(i,0,n) cin>>cars[i].vel;
		forn(i,0,n){ 
			short di; 
			cin>>di; 
			if(!di) di=-1;
			cars[i].dir = di;
			cars[i].vel *= di;
		}
		forn(i,0,n) cin>>cars[i].pos;
		forn(i,0,n) cin>>cars[i].len;

		double t_chef = (double)y/s;
		double t_curr = 0.0000000;
		double error = 1e-6;

		forn(i,0,n){
			double da = (double)(cars[i].pos + cars[i].vel*t_curr);
			double db = da - cars[i].dir*cars[i].len;
			double ta = (double)(0.0 + (-1)*error*cars[i].dir - da)/cars[i].vel;

			if((abs(db-0.0) > error && db*cars[i].vel > 0) 
				|| (da*db > 0 && ta > t_chef)){
				t_curr += t_chef;
				continue;
			}

			double tb = (double)(0.0 - (db+error))/cars[i].vel;
			t_curr += tb + t_chef;

 		}

 		cout<<t_curr<<"\n";
	}

    return 0;
}
