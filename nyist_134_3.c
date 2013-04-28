/*	auther: C.H King
 *	buildtime: 2013/4/25
 */

#include <stdio.h>
#include <stdlib.h>

int cmp (const void *a, const void *b)
{
	int *fa = (int *)a;
	int *fb = (int *)b;
	return *fa-*fb < 0 ? -1 : 1;
}

int main ()
{
	int t, n, arr[1005], i, j;
	scanf ("%d", &t);
	while (t --){
		scanf ("%d", &n);
		for (i = 0; i < n; ++ i){
			scanf ("%d", &arr[i]);
		}
		qsort (arr, n, sizeof (int), cmp);
		int ans = 0, t = 0;
		for (i = 0; i < n; ++ i){
			t += arr[i];
			ans += t;
		}
		printf ("%d\n", ans);
	}
	return 0;
}
