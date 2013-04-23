/*	auther: C.H King
 *	filename: nyist_295.c
 *	build time: 2013/4/23
 *	type: char
 */

#include <stdio.h>
#include <stdbool.h>

char comb[74][4], opp[29][3], base[101];
int c, d, n;

void output (char *str, int len )
{
	if (len == 0)return ;
	printf ("%c", str[0]);
	for (int i = 1; i < len; i ++){
		printf (", %c", str[i]);
	}
}

bool isIn (char *str, int len, char c)
{
	for (int i = 0; i < len; i ++){
		if (str[i] == c)return true;
	}
	return false;
}

void convert ()
{
	char out[101];
	int i, len = 0;
	for (i = 0; i < n; ++ i){
		out[len++] = base[i];
		if (len >= 2){
			bool f = false;
			while (!f){
				f = true;
				for (int j = 0; j < 2*c; ++ j){
					if (out[len-1] == comb[j][0] && out[len-2] == comb[j][1]){
						len -= 2;
						out[len ++] = comb[j][2];
						break;
					}
				}
			}
			for (int j = 0; j < d; ++ j){
				if (isIn (out, len, opp[j][0]) && isIn (out, len, opp[j][1])){
					len = 0;
					break;
				}
			}
		}
	}
	output (out, len);
}

int main ()
{
	int t;
	int i, j, iCase;
	scanf ("%d", &t);
	for (iCase = 1; iCase <= t; ++ iCase){
		scanf ("%d", &c);
		for (j = 0, i = 0; i < c; ++ i){
			scanf ("%s", comb[j]);
			j ++;
			comb[j][1] = comb[j-1][0], comb[j][0] = comb[j-1][1], comb[j][2] = comb[j-1][2];
			j ++;
		}
		scanf ("%d", &d);
		for (i = 0; i < d; ++ i){
			scanf ("%s", opp[i]);
		}
		scanf ("%d %s", &n, base);
		printf ("Case #%d: [", iCase);
		convert ();
		printf ("]\n");
	}
	return 0;
}
