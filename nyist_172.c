#include <stdio.h>
#include <string.h>

#define bool int
#define true 1
#define false 0

bool map[106][106] = {0};

bool isLegal (int x, int y){
	if (x >= 1 && y >= 1 && x <= 100 && y <= 100)return true;
	return false;
}

int main ()
{
	int n;
	char op[6];
	int x, y, l;
	scanf ("%*s");
	while (~scanf ("%s %d%d%d", op, &x, &y, &l)){
		int i, j;
		if (op[0] == 'B'){
			for (i = x; i <= x+l-1 && i <= 100; i ++){
				for (j = y; j <= y+l-1 && j <= 100; j ++){
					if (isLegal(i, j))
						map[i][j] = true;
				}
			}
		}
		else if (op[0] == 'W'){
			for (i = x; i <= x+l-1 && i <= 100; i ++){
				for (j = y; j <= y+l-1 && j <= 100; j ++){
					if (isLegal(i, j))
						map[i][j] = false;
				}
			}
		}
		else if (op[0] == 'T'){
			int ans = 0;
			for (i = x; i <= x+l-1 && i <= 100; i ++){
				for (j = y; j <= y+l-1 && j <= 100; j ++){
					if (isLegal(i, j))
						if (map[i][j])ans ++;
				}
			}
			printf ("%d\n", ans);
		}
	}
	return 0;
}
