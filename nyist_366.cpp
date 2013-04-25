/*	auther: C.H King
 *	filename: nyist_366.cpp nyist_32 nyist_19
 *	buildtime: 2013/4/24
 *	type: dfs
 */
/*
#include <stdio.h>
#include <string.h>

char str[12];
bool used[12];
int x, m;

void dfs (int pre)
{
	if (pre == m){
		str[pre] = '\0';
		printf ("%s\n", str);
		return ;
	}
	for (int i = 1; i <= x; ++ i){
		if (!used[i]){
			used[i] = true;
			str[pre] = i+'0';
			dfs (pre + 1);
			used[i] = false;
		}
	}
}

int main ()
{
	int n;
	scanf ("%d", &n);
	while (n --){
		scanf ("%d%d", &x, &m);
		memset (used, false, sizeof (used));
		memset (str, 0, sizeof (str));
		dfs (0);
	}
	return 0;
}*/

#include <stdio.h>
#include <string.h>

int n, r;
char str[12];
bool used[12];

void dfs (int t, int pre)
{
	if (t == r){
		str[t] = '\0';
		printf ("%s\n", str);
		return ;
	}
	for (int i = pre; i >= 1; -- i){
		used[i] = true;
		str[t] = i+'0';
		dfs (t+1, i-1);
		used[i] = false;
	}
}

int main ()
{
	while (~scanf ("%d%d", &n, &r)){
		memset (used, false, sizeof (used));
		dfs (0, n);
	}
	return 0;
}