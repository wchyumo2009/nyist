/*	auther: C.H King
 *	filename: nyist_294.c
 *	buildtime: 2013/4/23
 *	type: DP
 */

#include <stdio.h>

int abs (int a)
{
	return a > 0 ? a : -a;
}

int max (int a, int b)
{
	return a > b ? a : b;
}

int main ()
{
	int t, cas;
	scanf ("%d", &t);
	for (cas = 1; cas <= t; ++ cas){
		int lastP[2] = {1, 1};	//the start position is one
		int lastans[2] = {0, 0};	//to record the id's current answer
		char c;
		int i, n, q;
		scanf ("%d", &n);
		int ans = 0;
		for (i = 0; i < n; ++ i){
			scanf (" %c %d", &c, &q);
			int id = 0;
			if (c == 'B')id = 1;
			ans = max (ans, abs (q-lastP[id])+lastans[id])+1;
			lastP[id] = q;
			lastans[id] = ans;
		}
		printf ("Case #%d: %d\n", cas, ans);
	}
	return 0;
}
