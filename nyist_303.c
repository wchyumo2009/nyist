/*	auther: C.H King
 *	filename: nyist_303.c
 *	buildtime: 2013/4/23
 *	type: 进制转换
 */

#include <stdio.h>
#include <string.h>

int main ()
{
	int n;
	char gnum[11];
	scanf ("%d", &n);
	while (n --){
		scanf (" %s", gnum);
		int len = strlen (gnum), i;
		if (gnum[0] >= '0' && gnum[0] <= '9'){
			int ans = 0, ll = 0;
			char str[11];
			for (i = 0; i < len; ++ i){
				ans = ans*10+gnum[i]-'0';
			}
			while (ans != 0){
				if (ans % 26 == 0){
					str[ll ++] = 'Z';
					ans --;
				}
				else {
					str[ll ++] = (ans%26-1)+'A';
				}
				ans/=26;
			}
			for (i = ll-1; i >= 0; -- i){
				printf ("%c", str[i]);
			}
			printf ("\n");
		}
		else if (gnum[0] >= 'A' && gnum[0] <= 'Z'){
			int ans = 0;
			for (i = 0; i < len; ++ i){
				ans = ans*26+gnum[i]-'A'+1;
			}
			printf ("%d\n", ans);
		}
	}
	return 0;
}
