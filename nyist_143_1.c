/*	auther: C.H King
 *	build time: 2013/4/27
 */

#include <stdio.h>
#include <string.h>

int main ()
{
	int t, m, n, i;
	char str[210];
	scanf ("%d", &t);
	while (t --){
		scanf ("%d %s %d", &m, str, &n);
		for (i = 0; i < m; ++ i){
			str[i+m] = str[i];
		}
		n %= m;
		for (i = n; i < n+m; ++ i){
			printf ("%c", str[i]);
		}
		printf ("\n");
	}
	return 0;
}
