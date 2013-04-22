/*	Auther: C.H King
 *	filename: nyist_289
 *	buildtime: 2013/4/22
 *	Type: DP
 */

#include <stdio.h>
#include <string.h>

int max (int a, int b)
{
	return a > b ? a : b;
}

int main ()
{
	int n, v;
	int apple[1001], price[1001], dp[1001];
	while (scanf ("%d%d", &n, &v), n+v){
		int i, j;
		for (i = 0; i < n; ++ i){
			scanf ("%d%d", &apple[i], &price[i]);
		}
		memset (dp, 0, sizeof (dp));
		for (i = 0; i < n; ++ i){
			for (j = v; j >= apple[i]; -- j){
				dp[j] = max (dp[j], dp[j-apple[i]]+price[i]);
			}
		}
		printf ("%d\n", dp[v]);
	}
	return 0;
}
