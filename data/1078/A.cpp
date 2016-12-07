#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

char table[]="yhesocvxduiglbkrztnwjpfmaq";

int main(int argc, char* argv[])
{
	//freopen("A-small-attempt0.in","r",stdin);
	//freopen("A.out","w",stdout);
	int T,Case,i;
	cin>>T;
	char inputStr[101];
	Case=1;
	getchar();
	while(Case<=T){
		cout<<"Case #"<<Case++<<": ";
		gets(inputStr);
		for(i=0;i<strlen(inputStr);i++){
			if(inputStr[i]==' '){
				cout<<" ";
			}else {
				cout<<table[inputStr[i]-97];
			}
		}
		cout<<endl;
	}

	return 0;
}
