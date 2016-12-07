#include<iostream>
#include<sstream>
#include<cstdio>
using namespace std;

#define two(X) (1<<(X))//NOTES:two(
#define contain(S,X) (((S)&two(X))!=0)//NOTES:contain(
int isPow(int n){
	return !(n&(n-1));
}
int getK(int n){
	int i,j,K;
	for(i=1;i<=n;i=i+2){
		if(n%i) continue;
		if(isPow(n/i)){
			for(j=0;j<n/i;j++){
				if(two(j)==n/i){
					return j;
				}
			}
		}
	}
	return 0;
}

int main()
{
	freopen("data.in","r",stdin);
//		freopen("data.out","r",stdin);
	freopen("data.out","w",stdout);
	int i=1,n,ii=1;
	while(cin>>n)
	{	
		char filename_in[256];
		char filename_out[256];
		sprintf(filename_in,"in//data%d.in",ii);
		sprintf(filename_out,"in//data%d.out",ii);

		FILE *fp_in = fopen(filename_in, "w");
		FILE *fp_out = fopen(filename_out, "w");
		fprintf(fp_in, "%d\n",n);	

		cout<<two(getK(n)+1)<<endl;
		fprintf(fp_out, "%d\n",two(getK(n)+1));
		fclose(fp_in);
		fclose(fp_out);
		ii++;
	}	
	return 0;
}