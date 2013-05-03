/*	auther: C.H King
 *	buildtime: 2013/4/30
 */

#include <stdio.h>
#include <string.h>

typedef struct node{
	char cname[35];
	int score;
}node;

int main ()
{
	node no[110];
	int len, ans, n, t;
	int i, sc;
	char str[35];
	scanf ("%d", &t);
	while (t --){
		scanf ("%d", &n);
		memset (no, 0, sizeof (no));
		ans = 0;
		len = 0;
		while (n --){
			scanf (" %s %d", str, &sc);
			for (i = 0; i < len; ++ i){
				if (strcmp (no[i].cname, str) == 0){
					if (no[i].score < sc){
						no[i].score = sc;
						ans ++;
					}
					break;
				}
			}
			if (i >= len){
				strcpy (no[len].cname, str);
				no[len].score = sc;
				len ++;
			}
		}
		printf ("%d\n", ans);
	}
	return 0;
}
