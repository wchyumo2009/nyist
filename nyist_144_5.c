/*	auther: C.H King
 *	buildtime: 2013/4/28
 */

#include <stdio.h>
#include <string.h>

#define MAXN 301

int max (int a, int b)
{
	return a > b ? a : b;
}

int main ()
{
	int t, arr[MAXN][MAXN], dp[MAXN];
	int i, j, k, l;
	int m, n;
	scanf ("%d", &t);
	while (t --){
		memset (arr, 0, sizeof (arr));
		scanf ("%d%d", &m, &n);
		for (i = 1; i <= m; ++ i){
			for (j = 1; j <= n; ++ j){
				scanf ("%d", &arr[i][j]);
			}
		}
		for (i = 1; i <= m; ++ i){
			for (j = 1; j <= n; ++ j){
				arr[i][j] += arr[i][j-1];
			}
		}
		int ans = 0;
		for (k = 1; k <= n; ++ k){
			for (l = k; l <= n; ++ l){
				memset (dp, 0, sizeof (dp));
//				if (k != l){
					for (i = 1; i <= m; ++ i){
						dp[i] = dp[i-1] > 0 ? (dp[i-1] + arr[i][l] - arr[i][k-1]) : arr[i][l]-arr[i][k-1];
						ans = max (ans, dp[i]);
					}
//				}
//				else {
//					for (i = 1; i <= m; ++ i){
//						dp[i] = dp[i-1] > 0 ? (dp[i-1] + arr[i][l] - arr[i][l-1]) : arr[i][l]-arr[i][l-1];
//						ans = max (ans, dp[i]);
//					}
//				}
			}
		}
		printf ("%d\n", ans);
	}
	return 0;
}
