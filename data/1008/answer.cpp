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

int isTow(unsigned long n){
	
	return  n && (!(n&(n-1)));
}
void main()
{
	unsigned long n;
//	freopen("data1.in","r",stdin);
//	freopen("data1.out","w",stdout);
	while(cin>>n){
		if(!isTow(n)){
			cout<<"YES"<<endl;
		}else 	cout<<"NO"<<endl;
	}
	
}
