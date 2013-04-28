/*	auther: C.H King
 *	build time: 2013/4/25
 *	type: char 回文
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main ()
{
	int t, i, j, k;
	char str[110];
	scanf ("%d", &t);
	while (t --){
		scanf (" %s", str);
		int len = strlen (str);
		int first = 0;
//		printf ("%s\n", strt);
		while (true){
			for (i = first, j = len - 1; i < len; -- j, ++ i){
				if (str[j] != str[i] || i >= j){
//					printf ("%c %c", str[i], strt[j]);
					break;
				}
//				printf ("%c %c\n", str[i], str[j]);
			}
			if (i == j || i-1 == j)break;
			first ++;
		}
//		printf ("i=%d j=%d\n", i, j);
		for (k = 0; k < len; ++ k){
			printf ("%c", str[k]);
		}
		if (i == j)k = j-i+first-1;
		else if (i-1 == j)k =j-i+first;
		for (; k >= 0; -- k){
			printf ("%c", str[k]);
		}
		printf ("\n");
	}
	return 0;
}
