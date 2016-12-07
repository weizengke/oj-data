/*#include<iostream>
#include<sstream>
#include<cstdio>
using namespace std;

bool isUpperCase(char c){return c>='A' && c<='Z';}
bool isLowerCase(char c){return c>='a' && c<='z';}
char toLowerCase(char c){return (isUpperCase(c))?(c+32):c;}
char toUpperCase(char c){return (isLowerCase(c))?(c-32):c;}

int main()
{
	string str, line;
	int i,j,n;
	freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	int ii=1;
	while(getline(cin,line)){	
	//	cout<<line<<endl;


		char filename_in[256];
		char filename_out[256];
		sprintf(filename_in,"in//data%d.in",ii);
		sprintf(filename_out,"in//data%d.out",ii);
		
		FILE *fp_in = fopen(filename_in, "w");
		FILE *fp_out = fopen(filename_out, "w");
		fprintf(fp_in,"%s\n",line.c_str());	
		

		istringstream stream(line);
		int isCentenceFirst=1;
		while(stream>>str)
		{		
			int isWordsFirst=1;
			int isWordFirst=1;
			for(i=0;i<str.length();i++){
			//	cout<<str[i];
				if(!isalpha(str[i])){isWordFirst=1;continue;}	
				
				if(isWordFirst){
					
					if(isWordsFirst){
						if(isCentenceFirst){
							isCentenceFirst=0;
						}else {cout<<" ";	fprintf(fp_out, " ");}
						isWordsFirst=0;
					}else {cout<<" ";	fprintf(fp_out, " ");}
					cout<<toUpperCase(str[i]);
					fprintf(fp_out, "%c",toUpperCase(str[i]));
					isWordFirst=0;
				}else {
					cout<<str[i];
					fprintf(fp_out, "%c",str[i]);
				}
			
			}
		}
			cout<<"."<<endl;
			fprintf(fp_out, ".");

			fclose(fp_in);
			fclose(fp_out);
			ii++;

	}
	return 0;
}
*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

//////////////////////////////// multiple testcases ////////////////////////////////

double fac(int n){
	double ans=1;

	for(int i=1;i<=n;i++){
		ans*=i;
	}

	return ans;
}
typedef struct {
	char ch;
	int nCount;
}LETTER;

int isAppea(LETTER l[100],char c,int sum){
	for(int i=0;i<sum;i++){
		if(l[i].ch==c){
			return i;
		}
	}
	return -1;
}

int main(void){
	freopen("data.in","r",stdin);
//	freopen("data_small.out","w",stdout);
	int i,j,k;
	char str[100]={0};
	int ii=1;
	while(gets(str)){
	//	cout<<str<<endl;

		char filename_in[256];
		char filename_out[256];
		sprintf(filename_in,"in//data%d.in",ii);
		sprintf(filename_out,"in//data%d.out",ii);
		
		FILE *fp_in = fopen(filename_in, "w");
		FILE *fp_out = fopen(filename_out, "w");
		fprintf(fp_in,"%s\n",str);	


		LETTER letters[100];
	    int sum=0;
		for(i=0;i<strlen(str);i++){
			int flag = isAppea(letters,str[i],sum);
			
			if(flag<0){
				letters[sum].ch=str[i];
				letters[sum].nCount=1;
					sum++;
			}else{
				letters[flag].nCount++;
			
			}
		}
		
		
		double ans=fac(strlen(str));
		//cout<<ans<<endl;
		for(i=0;i<sum;i++){
			ans/=fac(letters[i].nCount);			
		}
		cout<<ans<<endl;
			fprintf(fp_out,"%.0f\n",ans);	
			ii++;
	}
	

	return 0;
}






