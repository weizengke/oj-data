#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

const int MAX_SIZE = 100;
int N,S,P,ans;
int vis[MAX_SIZE];


int main()
{
//	freopen("data.in","r",stdin);
	freopen("B-small-attempt2.in","r",stdin);
	freopen("B-s.out","w",stdout);
	int T,Case,i,a;
	cin>>T;
	Case=1;
	while(Case<=T){
		cout<<"Case #"<<Case++<<": ";
		ans=0;
		cin>>N>>S>>P;
		for(i=0;i<N;i++){
			cin>>a;
			if(a==0){
				if(P==0){
					ans++;
				}
				continue;
			}
			if(a>(P-1)*3){
				ans++;
			}else if(a>=(3*P-4)){
				if(S){
					ans++;
					S--;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
