//
// Author: Harsh_Vasoya, DA-IICT
//

#include <bits/stdc++.h>

#define sync_off std::ios_base::sync_with_stdio(false); cin.tie(NULL);
#define lli long long int

using namespace std;

int main()
{
	int n;
	cin>>n;

	int a[n];
	int pos[n+1];
	unordered_set<int> hs;
	for(int i=0;i<n;i++){
		cin>>a[i];
		pos[i] = a[i];
		hs.insert(i+1);
	}

	int x = *hs.begin();
	int y = x;
	hs.erase(x);

	int cnt1=0,cnt2=0;
	while(!hs.empty()){
		y = pos[y];
		if(y==x){
			cnt1 += cnt2;
			cnt2 = -1;
			if(!hs.empty()){
				x = y = *hs.begin();
				hs.erase(x);
			}
		}
		else
			hs.erase(y);
		cnt2++;
	}

	cout<<"Um_nik";
	

    return 0;
}
