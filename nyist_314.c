/*	auther: C.H King
 *	filename: nyist_314.c
 *	buildtime: 2013/4/23
 *	type: gcd,ax+by=c solve
 */

#include <stdio.h>

/*
int gcd (int a, int b)
{
	if (b == 0)return a;
	return gcd (b, a%b);
}

int getValue (int a, int b)
{
	int i, t;
	for (i = 3; i <= 20; ++ i){
		t = a+b;
		a = b;
		b = t;
		printf ("%d ", t);
	}
	printf ("\n");
}
*/

int main ()
{
	int t, m;
//	int g = gcd (2584, 4181);
	scanf ("%d", &t);
	while (t --){
		scanf ("%d", &m);
		int i;
		for (i = 0; m >= i*2584; i++){
			if ((m-i*2584)%4181 == 0)break;
		}
		if (m-i*2584 >= 0)
			printf ("%d %d\n", i, (m-i*2584)/4181);
		else printf ("No answer\n");
	}
	return 0;
}
