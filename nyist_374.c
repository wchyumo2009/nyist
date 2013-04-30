/*	auther: C.H King
 *	buildtime: 2013/4/29
 */

#include <stdio.h>
#include <string.h>

void set (double *arr, int len)
{
	int i;
	for (i = 0; i < len; i ++){
		arr[i] = 0.0;
	}
}

void output (double *a, int len)
{
	int i;
	for (i = 1; i < len; ++ i){
		printf ("%.6f ", a[i]);
	}
	printf ("\n");
}

int main ()
{
	double ans1[20], ans2[20];
	int t, m, n, k;
	int i, j;
	scanf ("%d", &t);
	while (t --){
		scanf ("%d%d%d", &n, &m, &k);
		set (ans2, m);
		ans2[k] = 1.0;
		for (i = 1; i < 2*n-1; ++ i){
			if (i&1){
				set (ans1, m);
				for (j = 1; j < m; ++ j){
					ans1[j] += ans2[j]*0.5;
					ans1[j-1] += ans2[j]*0.5;
				}
//				output (ans1, m);
			}
			else {
				set (ans2, m);
				for (j = 0; j < m; ++ j){
					if (j == 0){
						ans2[j+1] += ans1[j];
					}
					else if (j == m-1){
						ans2[j] += ans1[j];
					}
					else {
						ans2[j] += ans1[j]*0.5;
						ans2[j+1] += ans1[j]*0.5;
					}
				}
//				output (ans2, m);
			}
		}
		output (ans2, m);
	}
}
