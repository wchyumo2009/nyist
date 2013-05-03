/*	auther: C.H King
 *	buildtime: 2013/4/30
 */

#include <stdio.h>

#define MAXN 30000

int fa[MAXN];

void init ()
{
	int i;
	fa[0] = 1, fa[1] = 1;
	for (i = 2; i < MAXN; ++ i){
		fa[i] = (fa[i-1] + fa[i-2])%10000;
	}
}

int main ()
{
	int t, n;
	scanf ("%d", &t);
	init ();
	while (t --){
		scanf ("%d", &n);
		n %= MAXN;
		printf ("%d\n", fa[n+1]);
	}
}
