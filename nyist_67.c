/*	Auther: C.H King
 *	File name: nyist_67.c
 *	Build time: 2013/4/17
 *	Type: geometry
 */

#include <stdio.h>
#include <math.h>

int main ()
{
	int x1, y1, x2, y2, x3, y3;
	while (scanf ("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3)){
		if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0 && x3 == 0 && y3 == 0)break;
		double a = sqrt (1.0*(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
		double b = sqrt (1.0*(x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
		double c = sqrt (1.0*(x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
		double s = (a+b+c)/2.0;
		printf ("%.1f\n", sqrt (s*(s-a)*(s-b)*(s-c)));
	}
	return 0;
}
