/*	Auther: C.H King
 *	File name: nyist_85.c
 *	Build time: 2013/4/18
 *	Type: easy problem
 */
/*
#include <stdio.h>

int main ()
{
	int m, n;
	scanf ("%d", &m);
	while (m --){
		scanf ("%d", &n);
		int i;
		for (i = 0; (i+1)*i>>1 < n; i ++);
		int k = n-(((i-1)*i)>>1);
		if (!(i&1))printf ("%d/%d\n", k, i-k+1);
		else
			printf ("%d/%d\n", i-k+1, k);
	}
	return 0;
}*/

/*计算两点之间距离*/
/*
#include <stdio.h>
#include <math.h>

int main ()
{
	int n;
	float x1, x2, y1, y2;
	scanf ("%d", &n);
	while (n --){
		scanf ("%f%f%f%f", &x1, &y1, &x2, &y2);
		printf ("%.2f\n", sqrt (1.0*(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));
	}
	return 0;
}*/

/*判断等腰三角形，等边三角形，及是否是三角形*/

#include <stdio.h>

float fabs (float a)
{
	return a - 0 > 1e-9 ? a : -a;
}

int main ()
{
	int t, i;
	scanf ("%d", &t);
	for (i = 1; i <= t; i ++){
		float a, b, c;
		scanf ("%f%f%f", &a, &b, &c);
		printf ("Case #%d:\n", i);
		if (a <= 0 || b <= 0 || c <= 0){
			printf ("NO\n");
			continue;
		}
		if (a - b < 1e-9 && a - c < 1e-9){
			printf ("YE YE YE\n");
			continue;
		}
		if (a - b < 1e-9 || b - c < 1e-9 || a - c < 1e-9){
			printf ("YE YE\n");
			continue;
		}
		if (a+b > c && fabs(a-b) < c){
			printf ("YE\n");
			continue;
		}
		printf ("NO\n");
	}
	return 0;
}
