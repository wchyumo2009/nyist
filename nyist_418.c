/*	auther: C.H King
 *	buildtime: 2013/05/03
 *	type: calculation geometry
 */

#include <stdio.h>

int main ()
{
	int t;
	double m;
	scanf ("%d", &t);
	while (t --){
		scanf ("%lf", &m);
		double v = m, e = m;
		int i;
		for (i = 0; i < m-1; ++ i){
			v += i*(m-2-i)*m/4;
			e += (i*(m-2-i)+1)*m/2;
		}
		printf ("%.0f\n", e-v+1);
	}
	return 0;
}
