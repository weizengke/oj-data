#include<iostream>
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