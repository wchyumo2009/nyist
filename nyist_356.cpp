/*	auther: C.H King
 *	filename: nyist_356.cpp
 *	buildtime: 2013/4/24
 *	type: DP
 */

#include <stdio.h>

int main ()
{
	int t;
	scanf ("%d", &t);
	while (t --){
		int n, tm;
		scanf ("%d", &n);
		scanf ("%d", &tm);
		int i, k, b = tm, c = 0;
		for (i = 1; i < n; ++ i){
			scanf ("%d", &tm);
			k = c + tm > b ? c + tm : b;
			c = b - tm > c ? b - tm : c;
			b = k;
		}
		printf ("%d\n", b > c ? b : c);
	}
	return 0;
}