/*
special judge 1062
for n阶幻方
  */
#include <cstdio>
#include <iostream>
using namespace std;

#define MAX 101
FILE *dat, *diff;

int test(int Ma[MAX][MAX],int n){
	int i,j;
	//S=n(n ^2+1) /2 
	int S=n*(n*n+1)/2;
	int sum;
	for(i=0;i<n;i++){ //列
		sum=0;
		for(j=0;j<n;j++){
			sum+=Ma[j][i];
		}
		if(sum!=S) return 0;
	}
	for(i=0;i<n;i++){//行
		sum=0;
		for(j=0;j<n;j++){
			sum+=Ma[i][j];
		}
		if(sum!=S) return 0;
	}
	sum=0;
	for(i=0;i<n;i++){//对角
		sum+=Ma[i][i];
	}
	if(sum!=S) return 0;

	sum=0;
	for(i=0;i<n;i++){//对角
		sum+=Ma[i][n-i-1];
	}

	if(sum!=S) return 0;

	return 1;
}

int main(int argc, char **argv){
	
	int n,i,j;
	int a,b;
	int ret=0;	
	freopen(argv[1],"r",stdin);  //标准输入文件作为测试的结果
	dat = fopen(argv[2],"r");  //用户的输出文件作为测试的输入
//	freopen("data1.in","r",stdin);  //标准输入文件作为测试的结果
//	dat = fopen("data1.out","r");  //用户的输出文件作为测试的输入
	if (!dat) {
	perror("no .dat file");
	return 0;
	}
	while(1)
	{
		a=0;b=0;
		if(scanf("%d",&n)!=EOF){
			//开始处理
			int matrix[MAX][MAX]={0};
			for(i=0;i<n;i++){
				for (j=0;j<n;j++){
					if(fscanf(dat,"%d",&matrix[i][j])!=1){
						printf("少输出了内容\n");
						fclose(dat);
						return 0;
					}
				}
			}
// 			for(i=0;i<n;i++){
// 				for (j=0;j<n;j++){
// 					cout<<matrix[i][j]<<" ";
// 				}cout<<endl;
// 			}
			if(test(matrix,n)==0) {printf("Wrong Answer\n");return 0;}

		}else{//测试样例一结束，检测输出是否存在多余
			if(fscanf(dat,"%d",&a)==-1){ printf("Accepted\n");return 1;} //正确
		    //有多余了
			printf("多输出了内容\n");
			fclose(dat);
			return 0;
		}
	}
	fclose(dat);
	return 0;
}
