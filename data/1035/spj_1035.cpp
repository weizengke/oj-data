/*
special judge 1062
for n�׻÷�
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
	for(i=0;i<n;i++){ //��
		sum=0;
		for(j=0;j<n;j++){
			sum+=Ma[j][i];
		}
		if(sum!=S) return 0;
	}
	for(i=0;i<n;i++){//��
		sum=0;
		for(j=0;j<n;j++){
			sum+=Ma[i][j];
		}
		if(sum!=S) return 0;
	}
	sum=0;
	for(i=0;i<n;i++){//�Խ�
		sum+=Ma[i][i];
	}
	if(sum!=S) return 0;

	sum=0;
	for(i=0;i<n;i++){//�Խ�
		sum+=Ma[i][n-i-1];
	}

	if(sum!=S) return 0;

	return 1;
}

int main(int argc, char **argv){
	
	int n,i,j;
	int a,b;
	int ret=0;	
	freopen(argv[1],"r",stdin);  //��׼�����ļ���Ϊ���ԵĽ��
	dat = fopen(argv[2],"r");  //�û�������ļ���Ϊ���Ե�����
//	freopen("data1.in","r",stdin);  //��׼�����ļ���Ϊ���ԵĽ��
//	dat = fopen("data1.out","r");  //�û�������ļ���Ϊ���Ե�����
	if (!dat) {
	perror("no .dat file");
	return 0;
	}
	while(1)
	{
		a=0;b=0;
		if(scanf("%d",&n)!=EOF){
			//��ʼ����
			int matrix[MAX][MAX]={0};
			for(i=0;i<n;i++){
				for (j=0;j<n;j++){
					if(fscanf(dat,"%d",&matrix[i][j])!=1){
						printf("�����������\n");
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

		}else{//��������һ�������������Ƿ���ڶ���
			if(fscanf(dat,"%d",&a)==-1){ printf("Accepted\n");return 1;} //��ȷ
		    //�ж�����
			printf("�����������\n");
			fclose(dat);
			return 0;
		}
	}
	fclose(dat);
	return 0;
}
