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

typedef struct {
	char name[20];
	int gold;
	int silver;
	int bronze;
}CONUTRY;

int comp(const void *a,const void *b)
{
	if((*(CONUTRY *)a).gold!=(*(CONUTRY *)b).gold) return (*(CONUTRY *)b).gold-(*(CONUTRY *)a).gold;
	if((*(CONUTRY *)a).silver!=(*(CONUTRY *)b).silver) return (*(CONUTRY *)b).silver-(*(CONUTRY *)a).silver;
	if((*(CONUTRY *)a).bronze!=(*(CONUTRY *)b).bronze) return (*(CONUTRY *)b).bronze-(*(CONUTRY *)a).bronze;
	return strcmp((*(CONUTRY *)a).name,(*(CONUTRY *)b).name);
}

int main(){
	int n;
	CONUTRY a[21];
	int i;
	//freopen("data.in","r",stdin);		
	while(cin>>n){
		for(i=0;i<n;i++) {
			cin>>a[i].name>>a[i].gold>>a[i].silver>>a[i].bronze;

		}
		qsort(a,n,sizeof(a[0]),comp);
		for(i=0;i<n;i++) {
			cout<<a[i].name<<endl;
			
		}	
	}

	return 0;
}




