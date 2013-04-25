/*	auther: C.H King
 *	filename: nyist_353.cpp
 *	build time: 2013/4/24
 *	type: bfs and queue
 */

#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

typedef struct position{
	int x;
	int y;
	int z;
	int t;
}position;

queue <position > Q;
int dir[6][3] = {{0, 0, 1}, {0, 1, 0}, {1, 0, 0}, {-1, 0, 0}, {0, -1, 0}, {0, 0, -1}};
char map[31][31][31];
bool used[31][31][31];
int l, r, c;
position start;

bool isLegal (position pos)
{
	if (pos.x >= 1 && pos.x <= l && pos.y >= 1 && pos.y <= r && pos.z >= 1 && pos.z <= c && (map[pos.x][pos.y][pos.z] == '.' || map[pos.x][pos.y][pos.z] == 'E'))return true;
	return false;
}

void bfs ()
{
	while (!Q.empty ()){
		Q.pop ();
	}
	memset (used, false, sizeof (used));
	Q.push (start);
	used[start.x][start.y][start.z] = true;
	bool flag = false;
	int ans, i;
	while (!Q.empty ()){
		position front = Q.front ();
		Q.pop ();
		for (i = 0; i < 6; i ++){
			position tmp;
			tmp.x = front.x+dir[i][0];
			tmp.y = front.y+dir[i][1];
			tmp.z = front.z+dir[i][2];
			tmp.t = front.t+1;
			if (!used[tmp.x][tmp.y][tmp.z] && isLegal (tmp)){
				used[tmp.x][tmp.y][tmp.z] = true;
				if (map[tmp.x][tmp.y][tmp.z] == 'E'){
					flag = true;
					ans = tmp.t;
					break;
				}
				Q.push (tmp);
			}
		}
		if (flag)break;
	}
	if (flag){
		printf ("Escaped in %d minute(s).\n", ans);
	}
	else printf ("Trapped!\n");
}

int main ()
{
	int i, j, k;
	while (~scanf ("%d%d%d", &l, &r, &c)){
		if (l == 0 && r == 0 && c == 0)break;
		getchar ();
		for (i = 1; i <= l; ++ i){
			for (j = 1; j <= r; ++ j){
				for (k = 1; k <= c; ++ k){
					scanf ("%c", &map[i][j][k]);
					if (map[i][j][k] == 'S'){
						start.x = i, start.y = j, start.z = k, start.t = 0;
					}
				}
				getchar ();
			}
			getchar ();
		}
/*		for (i = 1; i <= l; ++ i){
			for (j = 1; j <= r; ++ j){
				for (k = 1; k <= c; ++ k){
					printf ("%c", map[i][j][k]);
				}
				printf ("\n");
			}
			printf ("\n");
		}*/
		bfs ();
	}
	return 0;
}