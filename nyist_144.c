/*	Auther: C.H King
 *	File name: nyist_144.c
 *	Build time: 2013/4/19
 *	Type: gcd
 */

#include <stdio.h>

int abs (int a)
{
	return a > 0 ? a : -a;
}

int gcd (int a, int b)
{
	if (b == 0)return a;
	return gcd (b, a%b);
}

int main ()
{
	int a, b, n;
	scanf ("%*s");
	while (~scanf ("%d%d%d", &a, &b, &n)){
		if (!(n%gcd(a, b)))printf ("Yes\n");
		else printf ("No\n");
	}
	return 0;
}
