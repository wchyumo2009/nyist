/*	auther: C.H King
 *	buildtime: 2013/4/30
 */
 
#include <stdio.h>
#include <math.h>

double getX1 (double a, double x1, double y1, double y2)	//x1 > x2
{
	return x1 - tan (a)*(y1-y2);
}

double getX2 (double a, double x1, double y1, double y2)	//x1 < x2
{
	return x1 + tan (a)*(y1-y2);
}

int main ()
{
	int t;
	double x1, x2, y1, y2, n, h;
	scanf ("%d", &t);
	while (t --){
		scanf ("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &n, &h);
		if (y1 > h){
			if (y2 >= y1){
				printf ("Impossible\n");
			}
			else {
				double a = (x1 < x2 ? atan ((x2-x1)/(y1-y2)) : atan ((x1-x2)/(y1-y2)));
				double xh = (x1 < x2 ? getX2 (a, x1, y1, h) : getX1 (a, x1, y1, h));
				double c = asin (1.0/n);
				if (n < 1.0){
					if (a >= c)printf ("Impossible\n");
					else {
						double b = asin (sin (a)/n);
						double x = (x1 < x2 ? xh + h*tan (b) : xh - h*tan (b));
						printf ("%.3f\n", x);
					}
				}
				else {
					double b = asin (sin (a)/n);
					double x = (x1 < x2 ? xh + h*tan (b) : xh - h*tan (b));
					printf ("%.3f\n", x);
				}
			}
		}
		else if (y1 - h < 1e-6){
			if (y2 >= y1){
				printf ("Impossible\n");
			}
			else {	//y1-y2/h == x1-x2/x1-x
				double x = x1-y1*(x1-x2)/(y1-y2);
				printf ("%.3f\n", x);
			}
		}
		else if (y1 < h){
			if (y2 < y1){
				double x = x1-y1*(x1-x2)/(y1-y2);
				printf ("%.3f\n", x);
			}
			else if (y2 - y1 < 1e-6)printf ("Impossible\n");
			else {
				double c = asin (n);
				double a = (x1 < x2 ? atan ((x2-x1)/(y2-y1)) : atan ((x1-x2)/(y2-y1)));
				if (a <= c)printf ("Impossible\n");
				else {	// h-y2/h-y1 == x-x2/x-x1
					double xh = (x1 < x2 ? getX1 (a, x1, y1, h) : getX2 (a, x1, y1, h));
					double x = (x1 < x2 ? xh + h*tan (a) : xh - h*tan (a));
					printf ("%.3f\n", x);
				}
			}
		}
	}
	return 0;
}

/*nyist_703 托兰定理*/

/*
#include <stdio.h>

int main ()
{
	int t, n;
	scanf ("%d", &t);
	while (t --){
		scanf ("%d", &n);
		printf ("%d\n", n*n/4);
	}
	return 0;
}*/
