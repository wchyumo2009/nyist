/*	Auther: C.H King
 *	File name: nyist_62.c
 *	Build time: 2013/4/17
 *	Type: easy problem
 */

#include <stdio.h>
#include <math.h>
#include <string.h>

#define bool int
#define false 0
#define true 1

bool isprime (int a)
{
	int i;
	if (a == 0 || a == 1)return false;
	for (i = 2; i*i <= a; i ++){
		if (a % i == 0)return false;
	}
	return true;
}

int main ()
{
	int maxn, minn, len, num[26], n, i;
	char str[101];
	scanf ("%d", &n);
	getchar ();
	while (n --){
		scanf ("%s", str);
		memset (num, 0, sizeof (num));
		for (i = 0; str[i] != '\0'; i ++){
			num[str[i]-'a'] ++;
		}
		maxn = 0, minn = 101;
		for (i = 0; i < 26; i ++){
			if (maxn < num[i])maxn = num[i];
			if (minn > num[i] && num[i] != 0)minn = num[i];
		}
		if (isprime (maxn-minn))printf ("Lucky Word\n%d\n", maxn-minn);
		else printf ("No Answer\n0\n");
	}
	return 0;
}
