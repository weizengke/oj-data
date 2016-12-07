#include<stdio.h>
#include<string.h>
int main()
{
	freopen("data.in","r",stdin);
		char str[1000]={'\0'};
		while(gets(str))
		{
			int i=0;
			while(i<=strlen(str))
			{	
				int j=0;
				int ti=i;
				while(str[i]!=' '&&str[i]!='\0') {i++;}
				for(int fi=i-1;fi>=ti;fi--)
				{
					printf("%c",str[fi]);
				}
				if(str[i]!='\0') printf(" ");
				i++;
			}
			printf("\n");
		}
	return 0;
}	