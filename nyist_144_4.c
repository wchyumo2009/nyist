/*	auther: C.H King
 *	buildtime: 2013/4/28
 */

//dir	0 north	1 east	2 south	3 west

#include <stdio.h>

typedef struct point{
	int x;
	int y;
	int dir;
}point;

void getP (point *p, char op)
{
	if (op == 'L'){
		if (p->dir > 0)(p->dir) --;
		else if (p->dir == 0)p->dir = 3;
	}
	else if (op == 'R'){
		if (p->dir < 3)(p->dir) ++;
		else if (p->dir == 3)p->dir = 0;
	}
	else if (op == 'M'){
		if (p->dir == 0){
			(p->y) ++;
		}
		else if (p->dir == 1){
			(p->x) ++;
		}
		else if (p->dir == 2){
			(p->y) --;
		}
		else if (p->dir == 3){
			(p->x) --;
		}
	}
}

int main ()
{
	int t, i;
	char str[105];
	point ans;
	scanf ("%d", &t);
	while (t --){
		ans.x = ans.y = ans.dir = 0;
		scanf ("%s", str);
		for (i = 0; str[i] != '\0'; ++ i){
			getP (&ans, str[i]);
		}
		printf ("%d %d ", ans.x, ans.y);
		if (ans.dir == 0)printf ("N\n");
		else if (ans.dir == 1)printf ("E\n");
		else if (ans.dir == 2)printf ("S\n");
		else if (ans.dir == 3)printf ("W\n");
	}
}
