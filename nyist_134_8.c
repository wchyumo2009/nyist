/*	auther: C.H King
 *	build time: 2013/4/25
 *	Type: prim
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define INF 0x3f3f3f3f
#define MAXN 101

int map[MAXN][MAXN];
int m;

void init ()
{
	int i, j;
	for (i = 1; i <= m; ++ i){
		for (j = 1; j <= m; ++ j){
			map[i][j] = INF;
		}
	}
}

int prim ()
{
	bool used[MAXN];
	int lowcost[MAXN];
	int i, j, res = 0, mnt, minc;
	memset (used, false, sizeof (used));
	for (i = 1; i <= m; ++ i){
		lowcost[i] = map[1][i];
	}
	used[1] = true;
	for (i = 1; i < m; ++ i){
		minc = INF, mnt = -1;
		for (j = 1; j <= m; ++ j){
			if (!used[j] && minc > lowcost[j]){
				mnt = j, minc = lowcost[j];
			}
		}
		if (mnt == -1)return -1;
		res += minc;
		used[mnt] = true;
		for (j = 1; j <= m; ++ j){
			if (!used[j] && lowcost[j] > map[mnt][j]){
				lowcost[j] = map[mnt][j];
			}
		}
	}
	return res;
}

int main ()
{
	int t, n, from, to, value, res;
	scanf ("%d", &t);
	while (t --){
		scanf ("%d%d", &n, &m);
		init ();
		while (n --){
			scanf ("%d%d%d", &from, &to, &value);
			if (map[from][to] > value)map[from][to] = map[to][from] = value;
		}
		res = prim ();
		if (res == -1)printf ("No solution\n");
		else printf ("%d\n", res);
	}
	return 0;
}
