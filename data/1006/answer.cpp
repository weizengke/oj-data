#include<iostream>
#include<sstream>
#include<cstdio>
using namespace std;
int main()
{
	string str, line;
	double average=0;
	int sLength,sum;
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	while(getline(cin,line))
	{	
		sLength=0;
		sum=0;
		istringstream stream(line);
		while(stream>>str)
		{
			sLength+=str.length();
			sum++;
		}
	//	cout<<sLength<<" "<<sum<<endl;
		
		printf("%.2f\n",1.0*sLength/sum);

	}	
	return 0;
}