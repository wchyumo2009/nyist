/*	auther: C.H King
 *	filename: nyist_297.c
 *	buildtime: 2013/4/23
 *	google code jam the forth, GoroSort
 */
 
#include <stdio.h>

int main ()
{
	int t;
	scanf ("%d", &t);
	for (int iCase = 1; iCase <= t; ++ iCase){
		int n;
		scanf ("%d", &n);
		int ans = 0, i, nu;
		for (i = 1; i <= n; ++ i){
			scanf ("%d", &nu);
			if (nu != i)ans ++;
		}
		printf ("Case #%d: %.6f\n", iCase, (double)ans);
	}
	return 0;
}
