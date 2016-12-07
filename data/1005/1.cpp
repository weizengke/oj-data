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

struct MYPOINT{double x,y;};
struct line{MYPOINT a,b;};

double distance(MYPOINT p1,MYPOINT p2){
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

//费马点
//到三角形三顶点距离之和最小的点
MYPOINT ferment(MYPOINT a,MYPOINT b,MYPOINT c){
	MYPOINT u,v;
	double step=fabs(a.x)+fabs(a.y)+fabs(b.x)+fabs(b.y)+fabs(c.x)+fabs(c.y);
	int i,j,k;
	u.x=(a.x+b.x+c.x)/3;
	u.y=(a.y+b.y+c.y)/3;
	while (step>1e-10)
		for (k=0;k<10;step/=2,k++)
			for (i=-1;i<=1;i++)
				for (j=-1;j<=1;j++){
					v.x=u.x+step*i;
					v.y=u.y+step*j;
					if (distance(u,a)+distance(u,b)+distance(u,c)>distance(v,a)+distance(v,b)+distance(v,c))
						u=v;
				}
	return u;
}

int main(){

	//setData();
	freopen("data1.in","r",stdin);
	freopen("data1.out","w",stdout);
		MYPOINT p1,p2,p3,p;
		while(cin>>p1.x>>p1.y>>p2.x>>p2.y>>p3.x>>p3.y){
			p=ferment(p1,p2,p3);
		//	cout<<p.x<<" "<<p.y<<endl;
			printf("%.6f %.6f\n",p.x,p.y);
		}
		
		return 0;
}