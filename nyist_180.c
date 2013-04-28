/*	auther: C.H King
 *	filename: nyist_180.c
 *	buildtime: 2013/4/26
 *	type: char sort
 */

#include <stdio.h>
#include <string.h>

int main ()
{
	int n, lens, lenm, len, i, j;
	char num[1001], str[1001], tmp[1001];
	scanf ("%d", &n);
	while (n --){
		scanf ("%s", tmp);
		len = strlen (tmp);
		lens = lenm = 0;
		for (i = 0; i < len; ++ i){
			if (tmp[i] >= '0' && tmp[i] <= '9')num[lenm ++] = tmp[i];
			else if (tmp[i] >= 'a' && tmp[i] <= 'z' || (tmp[i] >= 'A' && tmp[i] <= 'Z'))str[lens ++] = tmp[i];
		}
		for (i = 0; i < lenm; ++ i){
			for (j = 0; j < lenm-i-1; ++ j){
				if (num[j] < num[j+1]){
					char t = num[j];
					num[j] = num[j+1];
					num[j+1] = t;
				}
			}
		}
		num[lenm] = '\0';
		printf ("%d ", lens);
		for (i = lens - 1; i >= 0; -- i){
			printf ("%c", str[i]);
		}
		printf ("\n%d %s\n", lenm, num);
	}
	return 0;
}
