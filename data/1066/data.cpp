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

#define UL unsigned long
#define PB push_back

#define INF 99999999999999UL

#define SIZE(a) (int)(a.size())
#define LENGTH(a) (int)(a.length())

#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,n,m) for(int i=(n);i<=(m);i++)
#define STRUMIEN(A,B) istringstream A(B)
#define SWAP(a,b) (a)^=(b)^=(a)^=(b)//NOTES:SWAP(
#define MIN(a,b) (a>b)?b:a;  //NOTES:MAX(
#define MAX(a,b) (a>b)?a:b;  //NOTES:MAX(
#define two(X) (1<<(X))//NOTES:two(    2^x
#define twoL(X) (((unsigned long)(1))<<(X))//NOTES:twoL(

const double pi=acos(-1.0); //NOTES:pi
const double eps=1e-11;     //NOTES:eps

bool isUpperCase(char c){return c>='A' && c<='Z';}//NOTES:isUpperCase(
bool isLowerCase(char c){return c>='a' && c<='z';}//NOTES:isLowerCase(
bool isLetter(char c){return c>='A' && c<='Z' || c>='a' && c<='z';}//NOTES:isLetter(
bool isDigit(char c){return c>='0' && c<='9';}//NOTES:isDigit(
char toLowerCase(char c){return (isUpperCase(c))?(c+32):c;}//NOTES:toLowerCase(
char toUpperCase(char c){return (isLowerCase(c))?(c-32):c;}//NOTES:toUpperCase(

template<class T> 
string toString(T n){ostringstream ost;ost<<n;ost.flush();return ost.str();}//NOTES:toString(
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}//NOTES:toInt(
double toDouble(string s){double r=0;istringstream sin(s);sin>>r;return r;}//NOTES:toDouble(

template<class T> inline T getMin(T a,T b){return (a<b)?a:b;}//NOTES:getMin(
template<class T> inline T getMax(T a,T b){return (a<b)?b:a;}//NOTES:getMax(
template<class T> inline T gcd(T a,T b)//NOTES:gcd(
{if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b)//NOTES:lcm(
{if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<class T> inline T euclide(T a,T b,T &x,T &y)//NOTES:euclide(
{if(a<0){T d=euclide(-a,b,x,y);x=-x;return d;}
if(b<0){T d=euclide(a,-b,x,y);y=-y;return d;}
if(b==0){x=1;y=0;return a;}else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}
}
//END OF SOLO Template
class CarolsSinging{
public:
	int n;
	int len;
	unsigned long mint;
	unsigned long bit[10];
	void DFS(unsigned long res,int m,unsigned long u){
		int t=res;
	//	cout<<"res0="<<res<<endl;
		if(t==(1<<n)-1){
		//	cout<<u<<endl;
			if(u<mint) mint=u;
			return ;
		}
		
		for(int i=m;i<len;i++){
			DFS(res,i+1,u);
			DFS(res|bit[i],i+1,u+1);
		}
	}

		int choose(vector <string> lyrics){
			n=lyrics.size();
			len=lyrics[0].size();
			mint=999999;
			memset(bit,0,sizeof(int)*10);
		//	cout<<"n="<<n<<endl;
			REP(i,len){
				REP(j,n){
					int t=0;
					if(lyrics[j][i]=='Y') t=1;
					bit[i]+=t<<(n-j-1);
					//cout<<bit[i]<<" ";
				}	
				//cout<<endl;
			}

			DFS(0,0,0);
			return mint;
		}
};
int main(){
	freopen("data.in","r",stdin);
//	freopen("data1.out","w",stdout);
	int T;
	vector <string> s;
	string str;
	int ii=1;
	while (cin>>T){

		
		char filename_in[256];
		char filename_out[256];
		sprintf(filename_in,"in//data%d.in",ii);
		sprintf(filename_out,"in//data%d.out",ii);
		FILE *fp_in = fopen(filename_in, "w");
		FILE *fp_out = fopen(filename_out, "w");
		
		fprintf(fp_in, "%d\n",T);


		s.clear();
		for(int i=0;i<T-1;i++){
			cin>>str;
			fprintf(fp_in, "%s\n",str.c_str());
			s.PB(str);
		}
			cin>>str;
			fprintf(fp_in, "%s\n",str.c_str());
			s.PB(str);

		CarolsSinging C;
		cout<<C.choose(s)<<endl;

		fprintf(fp_out, "%d\n",C.choose(s));

		ii++;
	}
	

}