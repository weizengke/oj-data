#include <iostream> 
using namespace std; 
int hcf(int u,int v)       //获取最小公倍数
{
	int t,r;
	if (v>u)
	{t=u;u=v;v=t;}
	while ((r=u%v)!=0)
	{u=v;
	v=r;}
	return(v);
     }

int main() 
{ 
	char num[10];
		int a,b,gcd,n,i,j;
		freopen("data1.in","r",stdin);
		freopen("data1.out","w",stdout);
	while(atoi(gets(num))!=0)
	{	i=0;
	    b=0;
		while (num[i]!='\0')
		{
			i++;
		}
		n=atoi(num);
		
		for(j=0;j<i;j++) b=b*10+9;
		gcd=hcf(n,b);

		n=n/gcd;                  //化简分数
		b=b/gcd;      
			cout<<n<<"/"<<b<<endl;
	}


	return 0; 
}