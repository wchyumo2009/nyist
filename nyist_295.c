/*	auther: C.H King
 *	filename: nyist_295.c
 *	build time: 2013/4/23
 *	type: char
 */

#include <stdio.h>

int get

int main ()
{
	int t, c, d, n;
	char comb[37][4], opp[29][3], base[101];
	int i, j, cas;
	scanf ("%d", &t);
	for (cas = 1; cas <= t; ++ cas){
		printf ("Case #%d: [", cas);
		scanf ("%d", &c);
		for (i = 0; i < c; ++ i){
			scanf ("%s", comb[i]);
		}
		scanf ("%d", &d);
		for (i = 0; i < d; ++ i){
			scanf ("%s", opp[i]);
		}
		scanf ("%d", &n);
		scanf ("%s", base);
	}
	return 0;
}
