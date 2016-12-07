#include<stdio.h>
long a[32768];

int main()
{

	freopen("data4.in","r",stdin);
	freopen("data4.out","w",stdout);
    long n,i;
    a[0]=0;
    for( i = 1 ; i < 32768 ; i++ )
    { if(i%6==1&&i!=1)
    a[i]=a[i-1]+(i/6);
    else a[i]=a[i-1]+(i/6+1); 
    
    }
    while(scanf("%d",&n)!=EOF&&n<32768)
        printf("%d\n",a[n]);
    return 0;
    
}

