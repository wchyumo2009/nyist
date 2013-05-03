/*	auther: C.H King
 *	buildtime: 2013/4/30
 */

#include <stdio.h>
#include <string.h>

int main ()
{
	int t, n, s, p, anss, ansp;
	char str[21], tmp[21];
	scanf ("%d", &t);
	while (t --){
		scanf ("%d", &n);
		scanf (" %s %d %d", str, &anss, &ansp);
		n --;
		while (n --){
			scanf (" %s %d %d", tmp, &s, &p);
			if (s > anss){
				anss = s;
				strcpy (str, tmp);
				ansp = p;
			}
			else if (s == anss){
				if (p < ansp){
					anss = s;
					strcpy (str, tmp);
					ansp = p;
				}
				else if (p == ansp){
					if (strcmp (str, tmp) > 0){
						strcpy (str, tmp);
					}
				}
			}
		}
		printf ("%s\n", str);
	}
	return 0;
}
