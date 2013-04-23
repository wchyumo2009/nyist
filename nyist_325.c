/*	auther: C.H King
 *	filename: nyist_325 
 *	Type: dfs
 *	build time: 2013/4/23
 */

#include <stdio.h>

int sum[21], n, avg, weight[21];
int ans;

int max (int a, int b)
{
	return a > b ? a : b;
}

void dfs (int i, int cnt)
{
	if (i == 0){
		ans = max (ans, cnt);
		return ;
	}
	if (ans == avg || cnt + sum[i] <= ans)return ;//¼ôÖ¦
	if (cnt + weight[i] <= avg)dfs (i-1, cnt+weight[i]);//¼ôÖ¦
	dfs (i-1, cnt);
}

int main ()
{
	int i;
	while (~scanf ("%d", &n)){
		for (i = 1; i <= n; ++ i){
			scanf ("%d", &weight[i]);
			sum[i] = sum[i-1]+weight[i];
		}
		avg = sum[n]/2;
		ans = 0;
		dfs (n, 0);
		printf ("%d\n", sum[n]-2*ans);
	}
	return 0;
}
/*
#include <stdio.h>

int n, weight[21];
int min, sum;

int abs (int a)
{
	return a > 0 ? a : -a;
}

void dfs (int pre, int tsum)
{
	if (pre == n){
		return ;
	}
	if (abs(sum-tsum*2)<min){
		min = abs(sum-tsum*2);
	}
	if (tsum > sum/2)return ;
	dfs (pre+1, tsum);
	dfs (pre+1, tsum+weight[pre]);
}

int main ()
{
	int i;
	while (~scanf ("%d", &n)){
		sum = 0;
		for (i = 0; i < n; i ++){
			scanf ("%d", &weight[i]);
			sum += weight[i];
		}
		min = 1000000;
		dfs (0, 0);
		printf ("%d\n", min);
	}
	return 0;
}*/
/*
#include <stdio.h>
#include <string.h>

int dp[100005];

int max (int a, int b)
{
	return a > b ? a : b;
}

int main ()
{
	int n, weight[21];
	while (~scanf ("%d", &n)){
		int i, sum = 0;
		for (i = 0; i < n; ++ i){
			scanf ("%d", &weight[i]);
			sum += weight[i];
		}
		int j;
		memset (dp, 0, sum/2*sizeof (int));
		for (i = 0; i < n; ++ i){
			for (j = sum/2; j >= weight[i]; -- j){
				dp[j] = max (dp[j], dp[j-weight[i]]+weight[i]);
			}
		}
		printf ("%d\n", sum-dp[sum/2]*2);
	}
	return 0;
}*/