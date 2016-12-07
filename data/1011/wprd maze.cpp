#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

#define MAX 100

char word[MAX];
char maze[MAX][MAX];
int  vis[MAX][MAX];
int n,m;

typedef struct  
{
	int x;
	int y;
}PT;

int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};

int isValid(PT p){
	if(p.x<0||p.x>=n||p.y<0||p.y>=m||vis[p.x][p.y]){
		return 0;
	}
	return 1;
}

int dfs(PT p,int index){
	int i,j;
	if(index==strlen(word)){
		return 1;
	}
	PT next;
	for(i=0;i<4;i++){
		next.x=p.x+dir[i][0];
		next.y=p.y+dir[i][1];
		if(isValid(next)&&maze[next.x][next.y]==word[index]){
			//cout<<word[index];
			vis[next.x][next.y]=1;
			if(dfs(next,index+1)) return 1;
			vis[next.x][next.y]=0;
		}
	}

	return 0;
}

int solve(){
	PT p;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			p.x=i;p.y=j;
			if(dfs(p,0)) return 1;
		}
	}
	return 0;
}

void main()
{
	freopen("data1.in","r",stdin);
	freopen("data1.out","w",stdout);
	int i,j;
	while(cin>>n>>m){
		memset(word,0,sizeof(word));
		memset(maze,0,sizeof(maze));
		memset(vis,0,sizeof(vis));
		cin>>word;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				cin>>maze[i][j];
			}
		}
// 	
// 		cout<<word<<endl;
// 		for(i=0;i<n;i++){
// 			for(j=0;j<m;j++){
// 				cout<<maze[i][j]<<" ";
// 			}cout<<endl;
// 		}
	
		PT p;
		p.x=0;p.y=0;
		solve()?puts("YES"):puts("NO");
	}
	
}