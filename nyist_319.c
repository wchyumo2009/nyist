//折线分平面 f(n)=2*n*n-n+1
/*	filename: nyist_319.c
 */
 
#include <stdio.h>

int main ()
{
	int n, m;
	scanf ("%d", &n);
	while (n --){
		scanf ("%d", &m);
		printf ("%d\n", 2*m*m-m+1);
	}
	return 0;
}
