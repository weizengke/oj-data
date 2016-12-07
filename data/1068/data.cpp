
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream.h>
#define  MAX 10000
int mul(int *a,int len,int b)
{
	int  i, j;
	for(i = 0; i <len/2; i++)   //逆置
	{
		a[i]^=a[len-i-1]^=a[i]^=a[len-i-1];
	}
	
	a[0] = a[0] * b;  
	for(i = 1; i < len; i++) 	
	{
		a[i] = a[i] * b;
		a[i] = a[i] + a[i - 1] /10;
		a[i - 1] = a[i - 1] % 10;
	}
	while(a[len - 1] >= 10)	
	{	
		len++;
		a[len - 1] = a[len - 2] / 10;
		a[len - 2] = a[len - 2] % 10;         
	}
	for(i = 0; i <len/2; i++)  //转正
	{
		a[i]^=a[len-i-1]^=a[i]^=a[len-i-1];
	}
	return len;
}

int mod(int aa[],int len ,int b)     //高精度模运算  高精度除以低精度
{
	int  i,d;
	for(i = 0; i < len/2; i++)  aa[i]^=aa[len-i-1]^=aa[i]^=aa[len-i-1];
	d = 0;
	for(i = len - 1; i >= 0 ; i--)
	{
		d = d * 10 + aa[i];
		d = d % b; 
	}  
	for(i = 0; i < len/2; i++)  aa[i]^=aa[len-i-1]^=aa[i]^=aa[len-i-1];
	return d;
}    

int div(int *a,int len ,int b)     //高精度除以低精度
{
	int  i,d,j;
	for(i = 0; i < len/2; i++)  a[i]^=a[len-i-1]^=a[i]^=a[len-i-1];
	d = 0;
	j=0;
	for(i = len - 1; i >= 0 ; i--)
	{
		d = d * 10 + a[i];
		a[i] = d/b;
		d = d % b; 
	}  

	for(i=len-1;i>=0;i--){
		if(a[i]>0){
			len=i+1;
			break;
		}
	}

	for(i = 0; i < len/2; i++)  a[i]^=a[len-i-1]^=a[i]^=a[len-i-1];

	
	return len;
}    


int add(int *a,int len ,int b){ //only +1

	int  i, j,carry;
	for(i = 0; i <len/2; i++)   //逆置
	{
		a[i]^=a[len-i-1]^=a[i]^=a[len-i-1];
	}
	
	carry = b;
	for(i=0;i<len;i++){
		if(carry==0){
			break;
		}
		a[i] = a[i] + carry;
		carry = a[i]/10;
		a[i]%=10;
	}

	if(carry>0){
		a[len++]=carry;
	}
	for(i = 0; i <len/2; i++)  //转正
	{
		a[i]^=a[len-i-1]^=a[i]^=a[len-i-1];
	}
	return len;

}

int main()
{
	int i,j,n,l,m;
	int a[MAX];
	freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);

	int ii=1;

	while(scanf("%d",&n)!=EOF){

		char filename_in[256];
		char filename_out[256];
		sprintf(filename_in,"in//data%d.in",ii);
		sprintf(filename_out,"in//data%d.out",ii);
		FILE *fp_in = fopen(filename_in, "w");
		FILE *fp_out = fopen(filename_out, "w");
		
		fprintf(fp_in, "%d\n",n);

		memset(a,0,sizeof(a));
		a[0]=3;
		l=1;
		for(i=2;i<=n;i++){
			l=mul(a,l,3);
		}
		l = add(a,l,1);
		l=div(a,l,2);

		for(i=0;i<l;i++)   
		{
			printf("%d",a[i]);
			fprintf(fp_out, "%d",a[i]);
		}
		printf("\n");
			fprintf(fp_out, "\n");

			ii++;
	}
	return 0;
}