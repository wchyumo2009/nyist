/*	auther: C.H King
 *	buildtime: 2013/05/03
 *	type: big number sum
 */

#include <stdio.h>
#include <string.h>

int main ()
{
	int t, iCase;
	char add1[1010], add2[1010];
	int len1, len2, len, sum[1010];
	scanf ("%d", &t);
	for (iCase = 1; iCase <= t; ++ iCase){
		scanf ("%s %s", add1, add2);
		len1 = strlen (add1);
		len2 = strlen (add2);
		int i, j;
		len = 0;
		for (i = len1 - 1, j = len2 - 1; i >= 0 && j >= 0; -- i, -- j){
			sum[len ++] = add1[i]-'0'+add2[j]-'0';
		}
		while (i >= 0){
			sum[len ++] = add1[i]-'0';
			-- i;
		}
		while (j >= 0){
			sum[len ++] = add2[j]-'0';
			-- j;
		}
		int one = 0;
		for (i = 0; i < len; ++ i){
			sum[i] += one;
			one = sum[i]/10;
			sum[i] %= 10;
		}
		if (one){
			sum[len ++] = one;
		}
		printf ("Case %d:\n%s + %s = ", iCase, add1, add2);
		for (i = len-1; i >= 0; -- i){
			printf ("%d", sum[i]);
		}
		printf ("\n");
	}
	return 0;
}
