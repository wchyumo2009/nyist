/************************************************************************
 > File Name: nyist_301.cpp
 > Author: C.H Wong
 > Mail: wchyumo2009@163.com 
 > Created Time: Tue 31 Mar 2015 04:24:16 PM CST
 ***********************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const long long MOD = 1000007;
const int ML = 3;

long long A[ML][ML], E[ML][ML], tm[ML][ML];
long long t, n, f1, f2;

/*****************************************************************************
 ** Funtion name:setE
 ** Parameter:	e[][]	--type long long
 ** Description:it is used to set e as an identity matrix
 ** Return:	NULL
 *****************************************************************************/

void setE(long long e[ML][ML])
{
	for (int i = 0; i < ML; ++i){
		for (int j = 0; j < ML; ++j){
			e[i][j] = (i==j ? 1 : 0);
		}
	}
}

void init()
{
	setE(E);
	A[0][0] = A[0][2] = A[1][2] = A[2][0] = 0;
	A[1][0] = A[2][2] = 1;
}

/*****************************************************************************
 ** Funtion name:multiplyMatrix
 ** Parameter:	a[][], b[][]	--type: long long, long long
 ** Description:this function is used to calculate the result of one given 
 **		two-dimensional matrix multiply by other two-dimensional 
 **		matrix, then the result is stored in the second parameter 
 **		b;
 ** Return:	NULL
 *****************************************************************************/

void multiplyMatrix(long long a[ML][ML], long long b[ML][ML])
{
	long long tm[ML][ML];
	for (int i = 0; i < ML; ++i){
		for (int j = 0; j < ML; ++j){
			tm[i][j] = 0;
			for (int k = 0; k < ML; ++k){
				tm[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	for(int i = 0; i < ML; ++i){
		for (int j = 0; j < ML; ++j){
			b[i][j] = tm[i][j] % MOD;
		}
	}
}

/*****************************************************************************
 ** Function name:fun
 ** Parameter:	none
 ** Description:this function used a fast method named two power matrix
 **		multiplication to calculate power(A, n) where A is a matrix
 **		of m by m;
 **		the recursion is f(n)=a*f(n-2)+b*f(n-1)+c, so the returned
 **		value is f(n);
 ** return:	long long
 *****************************************************************************/

long long fun()
{
	if (n == 1)return f1;
	else if(n == 2)return f2;
	n -= 2;
	while (n >= 1){
		if (n&1){
			multiplyMatrix(A, E);
		}
		multiplyMatrix(A, A);
		n >>= 1;
	}
	return (((f1*E[0][1] + f2*E[1][1] + E[2][1])%MOD)+MOD)%MOD;
}

int main()
{
	scanf ("%lld", &t);
	while(t--){
		init();
		scanf ("%lld%lld%lld%lld%lld%lld", &f1, &f2, &A[0][1], &A[1][1], &A[2][1], &n);
		printf ("%lld\n", fun());
	}
	return 0;
}
