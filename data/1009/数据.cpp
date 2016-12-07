#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int isVowel(char c){
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U'){
		return 1;
	}else return 0;
}
bool isUpperCase(char c){return c>='A' && c<='Z';}
bool isLowerCase(char c){return c>='a' && c<='z';}
char toLowerCase(char c){return (isUpperCase(c))?(c+32):c;}
char toUpperCase(char c){return (isLowerCase(c))?(c-32):c;}
int main(){
	int n;
	string line;
	int i;
	freopen("data.in","r",stdin);	
	int ii=1;
	while(getline(cin,line)){

		char filename_in[256];
		char filename_out[256];
		sprintf(filename_in,"in//data%d.in",ii);
		sprintf(filename_out,"in//data%d.out",ii);
		FILE *fp_in = fopen(filename_in, "w");
		FILE *fp_out = fopen(filename_out, "w");

		fprintf(fp_in, "%s\n",line.c_str());	
		for(i=0;i<line.length();i++) {
			if(line[i]==' '){
				cout<<" ";
				fprintf(fp_out, " ");
				continue;
			}
			char c;
			if(isVowel(line[i])){
				c=toUpperCase(line[i]);
			}else {
				c=toLowerCase(line[i]);
			}
			cout<<c;
			fprintf(fp_out, "%c", c);
		}
		cout<<endl;
			fprintf(fp_out, "\n");
		ii++;
		fclose(fp_in);
		fclose(fp_out);
	}

	return 0;
}




