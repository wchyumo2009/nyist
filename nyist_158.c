/*	auther: C.H King
 *	buildtime: 2013/4/28
 */

#include <stdio.h>

#define MAXN 105

int main ()
{
	long long fac[MAXN];
	fac[0] = 1;
	int i;
	for (i = 1; i < MAXN; ++ i){
		fac[i] = fac[i-1]*i;
	}
	int m, n;
	while (~scanf ("%d%d", &m, &n)){
		long long ans = 1;
		while (m){
			ans *= (fac[m]/fac[n]/fac[m-n]);
			m -= n;
		}
		printf ("%d\n", (int)(ans % 2013));
	}
	return 0;
}
