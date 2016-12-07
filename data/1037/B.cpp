#include <stack>
#include<iostream>
#include <cmath>
#include <ctype.h> 
#include <cstdlib>
using namespace std;

char expr[1000];

int Check(char *str)   //ºÏ≤È¿®∫≈∆•≈‰–‘
{
	stack <char> s;
	int i=0;
	while (str[i]!='\0')
	{
		if(str[i]=='(') s.push(str[i]);
		if(str[i]==')'){
			if(s.empty()) return 0;
			else s.pop();
		}
		i++;
	}
	if(s.empty()) return 1;
	else return 0;
}
int main()
{

  // freopen("data.in","r",stdin);
   while(gets(expr))
   {  
	 if(!Check(expr)){
		 cout<<"NO"<<endl;
	 }else{
		 cout<<"YES"<<endl;
	 }
   }
	return 0;
}