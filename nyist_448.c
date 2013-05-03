/*	auther: C.H King
 *	buildtime: 2013/05/03
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAXN 110
int main ()
{
	int t, m, len, i;
	char num[MAXN];
	scanf ("%d", &t);
	while (t --){
		scanf ("%s %d", num, &m);
		len = strlen (num);
		m = len-m;
		int max = -1, pos = -1, s = 0;
		while (true){
			for (i = s; i < len - m + 1; ++ i){
				if (max < num[i] - '0'){
					max = num[i] - '0';
					pos = i;
				}
			}
			printf ("%d", max);
			s = pos+1;
			m --;
			max = -1;
			pos = -1;
			if (!m)break;
		}
		printf ("\n");
	}
	return 0;
}
