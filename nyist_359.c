/*	auther: C.H King
 *	buildtime: 2013/4/29
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAXN 1000010

int main ()
{
	int t;
	char str[MAXN], st[MAXN];
	scanf ("%d", &t);
	getchar ();
	while (t --){
		scanf ("%s%s", str, st);
		int i, j, lenstr = strlen (str), lenst = strlen (st);
		int f = 0, pos = -1;
		for (i = 0; i < lenst; ++ i){
			if (f == 0){
				if (str[i] != st[i]){
					f = 1;
					pos = i;
					-- i;
				}
			}
			else if (f == 1){
				if (str[i+1] != st[i]){
					f = 2; 
					break;
				}
			}
		}
		if (f == 2)printf ("0\n");
		else {
			int ti = 1;
			if (pos == -1)pos = lenstr - 1;
			for (j = pos; j > 0; -- j){
				if (str[j] != str[j-1])break;
				ti ++;
			}
			printf ("%d\n", ti);
			for (int k = j; k <= pos; ++ k){
				printf ("%d ", k+1);
			}
			printf ("\n");
		}
	}
	return 0;
}
