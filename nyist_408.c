/*	auther: C.H King
 *	buildtime: 2013/5/3
 *	m^x*x/n
 */

#include <stdio.h>

long long gcd (long long a, long long b)
{
	if (b == 0)return a;
	return gcd (b, a%b);
}

int main ()
{
	int t, iCase;
	long long n, m;
	scanf ("%d", &t);
	for (iCase = 1; iCase <= t; ++ iCase){
		scanf ("%lld%lld", &n, &m);
		int i;
		long long s = 1;
		for (i = 1; ; ++ i){
			s *= m;
			if (s >= n)break;
		}
		s *= i;
		long long gc = gcd (s, n);
		printf ("Case %d: %lld/%lld\n", iCase, s/gc, n/gc);
	}
	return 0;
}
