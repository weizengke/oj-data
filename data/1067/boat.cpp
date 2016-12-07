#include<iostream>
using namespace std;

#define MAX 101
int n;
int rr[MAX][MAX],m[MAX];
//rr[i][j]第i站到第j站的直达游船租金
//m[i]表示第0站到第i个站的少费用，本题要求m[n]


void moneyDP(int rr[][MAX], int m[], int n)
{
	for (int i=1; i<=n; i++)
	{
		m[i] = rr[0][i];
		for (int j=i-1; j>=1; j--)
		{
			if (m[i]>m[j]+rr[j][i])
			{
				m[i] = m[j]+rr[j][i];
			}
		}
	}
}

#include "time.h"
#include "stdlib.h"
#include "windows.h"

void setData(){
	freopen("data.in","w",stdout);
	srand(unsigned(time(NULL)));
	int n ,T;
	T=95;
	while(T--){
		n = rand()%95+5;
		cout<<n<<endl;
		for(int i=0;i<n;i++){
			int a,b;
			a= rand()%99+1;
			cout<<a;
			for(int j=n-1;j>i+1;j--){
				b=rand()%99+a;
				a= b;
				cout<<" "<<b;
			}	
			if(i<n-1){
				b=rand()%99+a;
				a= b;
				cout<<" "<<b<<endl;
			}else{
				cout<<endl;
			}
		}
		cout<<endl;
	}

}


int main()
{
	int i,j,num=0,a;

//	setData();
	
	freopen("data1.in","r",stdin);

	int ii=1;

	while (cin>>n)
	{
		char filename_in[256];
		char filename_out[256];
		sprintf(filename_in,"in//data%d.in",ii);
		sprintf(filename_out,"in//data%d.out",ii);
		FILE *fp_in = fopen(filename_in, "w");
		FILE *fp_out = fopen(filename_out, "w");
		
		fprintf(fp_in, "%d\n",n);
		if (n==0)
		{
			break;
		}
		else
		{
			num++;
			for (i=0;i<n;i++)
			{	for (j=i+1;j<n;j++)
				{
					cin>>a;
						fprintf(fp_in, "%d ",a);
					rr[i][j]=a;
				}
				cin>>a;
				fprintf(fp_in, "%d\n",a);
					rr[i][j]=a;
			}
			moneyDP(rr, m, n);
			
			//	cout<<m[n]<<endl;		
				
		fprintf(fp_out, "%d\n",m[n]);
		}
		ii++;
	}
	return 0;
}
