#include "stdio.h"
#include "time.h"
#include "stdlib.h"
#include "iostream.h"
#include "string.h"


//背包问题：
/*
n个物品，各自重量为wi，包的容量为S，恰好能选出k个物品装满包。。

  */

int NN;
int SS;
int w[100]={0};
int knap(int s,int n){
	if(s==0){
		return 1;
	}
	if (s<0||(s>0&&n>NN-1)) return 0;
	if(knap(s-w[n],n+1)){
		printf("%d ",w[n]);
		return 1;
	}
	return knap(s,n+1);
}
void setData(int ii){
	int n,m;
	char filename_in[256];
	char filename_out[256];
	sprintf(filename_in,"in//data%d.in",ii);
	FILE *fp_in = fopen(filename_in, "w");
	
	n=rand()%10+1;
	m=rand()%100+1;
	//	cout<<n<<" "<<m<<endl;
	fprintf(fp_in,"%d %d\n",n,m);
	for(int i=0;i<n;i++){
			fprintf(fp_in,"%d ",rand()%50);	
	}
	fprintf(fp_in,"%d\n",rand()%50);
	fclose(fp_in);
}

void init(){
	for(int i=0;i<100;i++){
		w[i]=0;
	}
}

void main()
{

	int n,m,i,j;srand(unsigned(time(0))); 
	for(int ii=1;ii<21;ii++){

		init();
	//	memset(w,0,sizeof(w));
		setData(ii);
		char filename_in[256];
		char filename_out[256];
		sprintf(filename_out,"in//data%d.out",ii);
		FILE *fp_out = fopen(filename_out, "w");
			sprintf(filename_in,"in//data%d.in",ii);
	
		freopen(filename_in,"r",stdin);
	
		cin>>NN>>SS;
		for(i=0;i<NN;i++){
			cin>>w[i];
		}

		if(knap(SS,0)){
			printf("YES\n");
		fprintf(fp_out,"YES\n");
		}
		else {
			printf("NO\n");
			fprintf(fp_out,"NO\n");
		}

			
		fclose(fp_out);
	}
}
