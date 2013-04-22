/*	Auther: C.H King
 *	filename: nyist_271.c
 *	build time: 2013/4/22
 *	type: easy
 */

#include <stdio.h>
#include <stdbool.h>

#define MAXN 10005

int ans[MAXN] = {0};

int main ()
{
	int start, end, i, s, e;
	ans[1] = 1;
	for (i = 2; i < MAXN; i ++){
		int tmp = i;
		while (tmp >= i){
			if (tmp & 1){
				tmp = 3*tmp+1;
			}
			else {
				tmp >>= 1;
			}
			ans[i] ++;
		}
		ans[i] += ans[tmp];
	}
	while (~scanf ("%d%d", &s, &e)){
		int max = 0;
		if (s > e){
			start = e;
			end = s;
		}
		else {
			start = s;
			end = e;
		}
		for (i = start; i <= end; ++ i){
			if (max < ans[i])max = ans[i];
		}
		printf ("%d %d %d\n", s, e, max);
	}
	return 0;
}
