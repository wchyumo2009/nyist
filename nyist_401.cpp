/*
 *	auther: C.H King
 *	buildtime: 2013/4/24
 *	acm.ccucomp.cn 1120

#include <stdio.h>
#include <string.h>

int main ()
{
	char mem[101][25];
	int n, k, i, m;
	char find[25];
	scanf ("%d", &n);
	for (i = 0; i < n; ++ i){
		scanf (" %s", mem[i]);
	}
	scanf ("%d", &k);
	while (k --){
		scanf ("%d", &m);
		int ans = 0;
		for (i = 0; i < m; ++ i){
			scanf ("%s", find);
			for (int j = 0; j < n; ++ j){
				if (strcmp (find, mem[j])==0){
					ans ++;
					break;
				}
			}
		}
		printf ("%d\n", ans);
	}
	return 0;
}*/

//N = R1^2*H1+R2^2*H2+...+Rn^2*Hn
//s = 2R1*H1+2R2*H2+...+2Rn*Hn+R1^2
//	poj 1190
/*
#include <stdio.h>

#define INF 0x3f3f3f3f

int n, m;
int ans;

int min (int a, int b)
{
	return a < b ? a : b;
}

//1^3+2^3+...+x^3=(x+1)*(x+1)*x*x/4

int get_3(int x)
{
	return (x+1)*(x+1)*x*x/4;
}

void dfs (int floor, int r, int h, int lfv, int s)
{
	if (s+lfv*2/r >= ans)return ;	//如果现在得到的面积加上最后剩余的体积在半径为r的情况下的面积比最优的结果大，停止搜索
	if (lfv < get_3(floor))return ;	//如果剩余的体积比在半径都是1的时候剩余层的体积小，则停止搜索
	if (floor == 0){	//最后一层搜索完成
		if (lfv == 0){
			if (ans > s)ans = s;
		}
		return ;
	}
	int k = 0, i, j, maxh;
	for (i = r-1; i >= floor; -- i){
		k = i*i;
		if (floor == m)s = k;
		maxh = min (h-1, (lfv-get_3 (floor-1))/k);
		for (j = maxh; j >= floor; -- j){
			dfs (floor-1, i, j, lfv-k*j, s+2*i*j);
		}
	}
}

int main ()
{
	while (~scanf ("%d%d", &n, &m)){
		ans = INF;
		dfs (m, 100, 10000, n, 0);
		if (ans == INF)printf ("0\n");
		else printf ("%d\n", ans);
	}
	return 0;
}*/

//	nyist_401
/*
#include <stdio.h>

int main ()
{
	int t, iCase;
	int n, k;
	scanf ("%d", &t);
	for (iCase = 1; iCase <= t; ++ iCase){
		scanf ("%d%d", &n, &k);
		if (k <= 1){
			if (n % 2)printf ("Case %d: first\n", iCase);
			else printf ("Case %d: second\n", iCase);
		}
		else {
			if (k >= n)printf ("Case %d: first\n", iCase);
			else printf ("Case %d: second\n", iCase);
		}
	}
	return 0;
}*/

/*nyist_675*/

#include <stdio.h>
#include <string.h>

int main ()
{
	int n;
	char name[101][11], pos[10];
	int arr[101];
	int i, cap;
	while (~scanf ("%d", &n)){
		for (i = 0; i < n; ++ i){
			scanf (" %s %s", name[i], pos);
			if (strcmp (pos, "rat") == 0){
				printf ("%s\n", name[i]);
				arr[i] = 0;
			}
			else if (strcmp (pos, "woman") == 0 || strcmp (pos, "child") == 0){
				arr[i] = 1;
			}
			else if (strcmp (pos, "man") == 0)arr[i] = 2;
			else cap = i;
		}
		for (i = 0; i < n; ++ i){
			if (arr[i] == 1){
				printf ("%s\n", name[i]);
			}
		}
		for (i = 0; i < n; ++ i){
			if (arr[i] == 2){
				printf ("%s\n", name[i]);
			}
		}
		printf ("%s\n", name[cap]);

	}
	return 0;
}