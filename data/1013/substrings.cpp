#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

const int MAX = 1024;
char ans[MAX][MAX];
int nSum;
int isHave;
int cmp(const void* a, const void* b ){
	return strcmp((char*)a,(char*)b);
}

void pushString(char *str){
	int i;
	for(i=0;i<nSum;i++){
		if(strcmp(ans[i],str)==0){
			return ;
		}
	}
	if(i==nSum){
		strcpy(ans[nSum++],str);
	}
}

int getSubIndex(char*strA,char*strB){
	bool bFlag=false;
	for(int i=0;i<strlen(strA);i++){
		for(int j=0;j<strlen(strB);j++){
			if(strA[j+i]!=strB[j]) break;
		}
		if(j==strlen(strB)) return i;
	}
	return -1;
} 
void getSubstring(char *str,int st,int en,char *return_s){
	 int j=0;
	 for(int i=st;i<en;i++){
		 return_s[j++]=str[i];
	 }
}
void findSubs(char *A,char *B,char *C){
	
	int nLenA=strlen(A);int nLenB=strlen(B);int nLenC=strlen(C);
	int nPosPrev=0;	int nPosLast=0;
	for(int i=0;i<nLenA;i=nPosPrev+1){
		nPosPrev=getSubIndex(&A[i],B);
		if(nPosPrev>-1){
			nPosPrev+=i;
	
			for(int j=nPosPrev+nLenB;j<nLenA;j=nPosLast+1){
				nPosLast = getSubIndex(&A[j],C);
				if(nPosLast>-1){
					nPosLast+=j;
					char tmp[1024]={0};
					getSubstring(A,nPosPrev,nPosLast+nLenC,tmp);
					pushString(tmp);
					isHave=1;
				}else break;
			}
		}else {
			return;
		}
	}
}

void main()
{
	freopen("data1.in","r",stdin);
	freopen("data1.out","w",stdout);
	char str1[1024]={0};
	char str2[1024]={0};
	char str3[1024]={0};
	while(cin>>str1>>str2>>str3){
		isHave=0;
		memset(ans,0,sizeof(ans));
		nSum=0;
	//	cout<<str1<<" "<<str2<<" "<<str3<<endl;
			findSubs(str1,str2,str3);

			qsort(ans,nSum,sizeof(ans[0]),cmp);

			for(int i=0;i<nSum;i++){
				cout<<ans[i]<<endl;
			}
			if(!isHave)  cout<<"no substring"<<endl;
		 	 cout<<endl;
	}

}
