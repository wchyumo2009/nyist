/*	auther: C.H King
 *	filename: nyist_181.c
 *	buildtime: 2013/4/26
 *	type: N!
 */

#include <stdio.h>

int main ()
{
	long long arr[21];
	int T, i, n;
	arr[1] = 1;
	for (i = 2; i < 21; ++ i){
		arr[i] = i*arr[i-1];
//		printf ("%lld ", arr[i]);
	}
	scanf ("%d", &T);
	while (T --){
		scanf ("%d", &n);
		if (n == 1)printf ("1\n");
		else if (n == 2)printf ("3\n");
		else {
			long long ans = 3;
			int t = -1;
			for (i = 3; i <= n; ++ i){
				ans += t*arr[i];
				t *= -1;
			}
			printf ("%lld\n", ans);
		}
	}
}
