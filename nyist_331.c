/*	auther: C.H King
 *	filename: nyist_331.cpp
 *	build time: 2013/4/23
 *	type: gcd
 */

#include <stdio.h>

int gcd (int a, int b)
{
	return b == 0 ? a : gcd (b, a%b);
}

int main ()
{
	int m, n;
	while (~scanf ("%d%d", &m, &n)){
		if (m == -1 && n == -1)break;
		if (gcd (m, n)==1)printf ("YES\n");
		else printf ("POOR Haha\n");
	}
	return 0;
}