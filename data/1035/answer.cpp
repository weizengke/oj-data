//存在三种情况下的幻方
#include <stdio.h>
#include <stdlib.h>
#define M 400
#define SWAP(x,y) {int t; t = x; x = y; y = t;}

void odd(int N) {//N=2n+1
	int i, j, key;
	int square[M+1][M+1] = {0};
	i = 0;
	j = (N+1) / 2;
	for(key = 1; key <= N*N; key++) {
		if((key % N) == 1)
			i++;
		else {
			i--;
			j++;
		}
		if(i == 0)
			i = N;
		if(j > N)
			j = 1;
		square[i][j] = key;
	}
	for(i = 1; i <= N; i++) {
		for(j = 1; j <N; j++)
		{	printf("%d ", square[i][j]);}
		printf("%d", square[i][j]);
		printf("\n");
	}
}
//--------------------------------------------//4n
void _Second(int N) {     //4N
	int i, j;
	int square[M+1][M+1] = {0};
	for(j = 1; j <= N; j++) {
		for(i = 1; i <= N; i++){
			if(j % 4 == i % 4 || ((j + i) % 4) == 1)
				square[i][j] = (N+1-i) * N -j + 1;
			else
				square[i][j] = (i - 1) * N + j;
		}
	}
	for(i = 1; i <= N; i++) {
		for(j = 1; j < N; j++)
		{	printf("%d ", square[i][j]);}
		printf("%d", square[i][j]);
		printf("\n");
	}
}
//------------------------//2(2n+1)

void magic_o(int square[][M], int n) {
	int count, row, column;
	row = 0;
	column = n / 2;
	for(count = 1; count <= n*n; count++) {
		square[row][column] = count; // 填A
		square[row+n][column+n] = count + n*n; // 填B
		square[row][column+n] = count + 2*n*n; // 填C
		square[row+n][column] = count + 3*n*n; // 填D
		if(count % n == 0)
			row++;
		else {
			row = (row == 0) ? n - 1 : row - 1 ;
			column = (column == n-1) ? 0 : column + 1;
		}
	}
}
void exchange(int x[][M], int n) {
	int i, j;
	int m = n / 4;
	int m1 = m - 1;
	for(i = 0; i < n/2; i++) {
		if(i != m) {
			for(j = 0; j < m; j++) // 處理規則 1
				SWAP(x[i][j], x[n/2+i][j]);
			for(j = 0; j < m1; j++) // 處理規則 2
				SWAP(x[i][n-1-j], x[n/2+i][n-1-j]);
		}
		else { // 處理規則 3
			for(j = 1; j <= m; j++)
				SWAP(x[m][j], x[n/2+m][j]);
			for(j = 0; j < m1; j++)
				SWAP(x[m][n-1-j], x[n/2+m][n-1-j]);
		}
	}
}

void _Third(int N) {              //2(2N+1)
	int square[M][M] = {0};
	int i, j;
	magic_o(square, N/2);
	exchange(square, N);
	for(i = 0; i < N; i++) {
		for(j = 0; j < N-1; j++)
		{	printf("%d ", square[i][j]);}
		printf("%d", square[i][j]);
		printf("\n");
	}
}
//--------------------

int main()
{
	int N;
	while(scanf("%d",&N)!=EOF&&N>2)
	{
		if (N%2!=0)
		{
			odd(N);
		}
		else if (N%4==0)
		{
			_Second(N);
		}
		else _Third(N);
	}
	return 0;
}