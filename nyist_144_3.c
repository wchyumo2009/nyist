/*	auther: C.H King
 *	buildtime: 2013/4/28
 */

#include <stdio.h>
#include <stdbool.h>

#define MAXN 30010

int main ()
{
	int t, n, arr[MAXN], dp[MAXN];
	bool sign[MAXN];
	scanf ("%d", &t);
	while (t --){
		int i, j, max = 0;
		scanf ("%d", &n);
		for (i = 1; i <= n; ++ i){
			scanf ("%d", &arr[i]);
			dp[i] = 1;
			sign[i] = false;
		}
		dp[0] = 1;
		for (i = 1; i <= n; ++ i){
			for (j = i-1; j > 0; -- j){
				if (sign[j] && arr[i] > arr[j] && dp[i] <dp[j]+1){
					dp[i] = dp[j]+1;
					sign[i] = false;
					break;
				}
				else if (!sign[j] && arr[i] < arr[j] && dp[i] < dp[j]+1){
					dp[i] = dp[j]+1;
					sign[i] = true;
					break;
				}
			}
			if (dp[i] == 1)dp[i] = dp[i-1];
			max = max < dp[i] ? dp[i] : max;
		}
		printf ("%d\n", max);
	}
	return 0;
}
