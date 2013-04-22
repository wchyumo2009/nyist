/*	auther: C.H King
 *	filename: nyist_173.c
 *	build time: 2013/4/21
 *	type: easy
 */
/*
#include <stdio.h>
#include <string.h>

int main ()
{
	char str[305];
	int len, i, ans;
	while (gets (str)){
		len = strlen (str);
		if (len == 1 && str[0] == '#')break;
		ans = 0;
		for (i = 1; i <= len; i ++){
			if (str[i-1] >= 'A' && str[i-1] <= 'Z'){
				ans += i*(str[i-1]-'A'+1);
			}
		}
		printf ("%d\n", ans);
	}
	return 0;
}*/

/*nyist_175 fox's sequence*/
/*
#include <stdio.h>

int main ()
{
	int n;
	int i, arr[16];
	while (scanf ("%d", &n), n){
		for (i = 0; i < n; i ++){
			scanf ("%d", &arr[i]);
		}
		if (n < 5){
			printf ("NO\n");
			continue;	
		}
		int a = arr[1] - arr[0];	//0<a
		if (a <= 0){
			printf ("NO\n");
			continue;
		}
		i = 2;
		while (i < n && arr[i]-arr[i-1] == a){
			i ++;
		}
		if (i >= n){
			printf ("NO\n");
			continue;
		}
		a = arr[i]-arr[i-1];	//a<b
		if (a >= 0){
			printf ("NO\n");
			continue;
		}
		while (i < n && arr[i]-arr[i-1] == a){
			i ++;
		}
		if (i >= n){
			printf ("NO\n");
			continue;
		}
		a = arr[i] - arr[i-1];
		if (a == 0){
			while (i < n && arr[i]-arr[i-1] == a){	//b<=c
				i ++;
			}
			if (i >= n){
				printf ("NO\n");
				continue;
			}
			a = arr[i]-arr[i-1];
			if (a <= 0){
				printf ("NO\n");
				continue;
			}
			while (i < n && arr[i]-arr[i-1] == a){	//b==c
				i ++;
			}
			if (i >= n){
				printf ("NO\n");
				continue;
			}
			a = arr[i] - arr[i-1];
			if (a >= 0){
				printf ("NO\n");
				continue;
			}
			while (i < n && arr[i]-arr[i-1] == a){
				i ++;
			}
			if (i < n){
				printf ("NO\n");
			}
			else printf ("YES\n");
			
		}
		else if (a > 0){
			while (i < n && arr[i]-arr[i-1] == a){	//b==c
				i ++;
			}
			if (i >= n){
				printf ("NO\n");
				continue;
			}
			a = arr[i] - arr[i-1];
			if (a >= 0){
				printf ("NO\n");
				continue;
			}
			while (i < n && arr[i]-arr[i-1] == a){
				i ++;
			}
			if (i < n){
				printf ("NO\n");
			}
			else printf ("YES\n");
		}
		else {
			printf ("NO\n");
			continue;
		}
	}
	return 0;
}*/

/*nyist_189 兔子的烦恼*/
/*
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main ()
{
	int n, m;
	bool used[1001];
	while (~scanf ("%d%d", &m, &n)){
		int tm = 0, nt = 0;
		memset (used, false, sizeof (used));
		while (true){
			if (used[tm])break;
			used[tm] = true;
			tm = (tm+m)%n;
			nt ++;
		}
//		printf ("nt = %d\n", nt);
		if (nt != n)printf ("YES\n");
		else printf ("NO\n");
	}
	return 0;
}*/


/*nyist_198*/
/*
#include <stdio.h>
#include <string.h>

int main ()
{
	char map[10] = {'O', 'O', 'T', 'T', 'F', 'F', 'S', 'S', 'E', 'N'}, num[11];
	int t, len, i;
	scanf ("%d", &t);
	while (t --){
		scanf ("%s", num);
		len = strlen (num);
		for (i = len - 1; i >= 0; -- i){
			printf ("%c", map[num[i]-'0']);
		}
		printf ("\n");
	}
	return 0;
}*/

/*nyist_215 poj_1844*/
/*
#include <stdio.h>
#include <stdbool.h>

#define MAXN 1000

int main ()
{
	int s, i;
	int sum[MAXN];
	sum[0] = 0;
	for (i = 1; i < MAXN; i ++){
		sum[i] = sum[i-1] + i;
	}
//	printf ("%d\n", sum[MAXN-1]);
	while (scanf ("%d", &s), s){
		i = 0;
		while (sum[i] < s)i ++;
		while (true){
			if (!((sum[i]-s)&1)){
				printf ("%d\n", i);
				break;
			}
			i ++;
		}
	}
	return 0;
}*/

/*nyist_219 蔡勒公式*/
// today: 2013/4/21:星期日
/*
#include <stdio.h>

int main ()
{
	int year, day, month;
	while (~scanf ("%d%d%d", &year, &month, &day)){
		if (month == 1 || month == 2){
			year --;
			month += 12;
		}
		printf ("%d\n", (day+2*month+3*(month+1)/5+year+year/4-year/100+year/400+1)%7);
	}
	return 0;
}*/

/*nyist_249  DP*/
/*
#include <stdio.h>

int min (int a, int b)
{
	return a < b ? a : b;
}

int main ()
{
	int mmin[101][101];
	int n, arr[101];
	int i, j;
	while (scanf ("%d", &n), n){
		for (i = 0; i < n; ++ i){
			scanf ("%d", &arr[i]);
			for (j = 0; j < n; ++ j){
				mmin[i][j] = 0;
			}
			mmin[i][i] = arr[i];
		}
		int max = 0;
		for (i = 0; i < n; ++ i){
			for (j = i+1; j < n; ++ j){
				mmin[i][j] = min (mmin[i][j-1], mmin[j][j]);
				int tmp = (j-i+1)*mmin[i][j];
				if (max < tmp)max = tmp;
			}
		}
		printf ("%d\n", max);
	}
	return 0;
}*/

/*nyist_252 递推*/
/*
#include <stdio.h>

#define MAXN 41

int main ()
{
	int a1[MAXN], a0[MAXN], n, i;
	a1[0] = a0[0] = 0;
	a1[1] = a0[1] = 1;
	for (i = 2; i < MAXN; ++ i){
		a1[i] = a0[i-1];
		a0[i] = a1[i-1] + a0[i-1];
	}
	scanf ("%*s");
	while (~scanf ("%d", &n)){
		printf ("%d\n", a1[n] + a0[n]);
	}
	return 0;
}*/

/*nyist_254*/
/*
#include <stdio.h>
#include <stdlib.h>

int cmp (const void *a, const void *b)
{
	int *fa = (int *)a;
	int *fb = (int *)b;
	return *fa-*fb < 0 ? -1 : 1;
}

int main ()
{
	int arr[200005], n, t, i;
	scanf ("%d", &t);
	while (t --){
		scanf ("%d", &n);
		for (i = 0; i < n; i ++){
			scanf ("%d", &arr[i]);
		}
		qsort (arr, n, sizeof (int), cmp);
		int max = 0, tmp = 1, a = arr[0], ans;
		for (i = 1; i < n; i ++){
			if (a != arr[i]){
				if (max < tmp){
					max = tmp;
					ans = a;
				}
				tmp = 1;
				a = arr[i];
			}
			else {
				tmp ++;
			}
		}
		if (max < tmp){
			ans = a;
		}
		printf ("%d\n", ans);
	}
	return 0;
}*/

/*nyist_256*/
/*
#include <stdio.h>

int main ()
{
	int t, k, i;
	scanf ("%d", &t);
	while (t --){
		scanf ("%d", &k);
		double sn = 0.0;
		for (i = 1; ; ++ i){
			sn += 1.0/i;
			if (sn > (double)k)break;
		}
		printf ("%d\n", i);
	}
	return 0;
}*/

/*nyist_269*/
/*
#include <stdio.h>
#include <string.h>

int main ()
{
	int ans[82] = {1, 10, 45, 165, 495, 1287, 3003, 6435, 12870, 24310, 43749, 75501, 125565, 202005, 315315, 478731, 708444, 1023660, 1446445, 2001285, 2714319, 3612231, 4720815, 6063255, 7658190, 9517662, 11645073, 14033305, 16663185, 19502505, 22505751, 25614639, 28759500, 31861500, 34835625, 37594305, 40051495, 42126975, 43750575, 44865975, 45433800, 45433800, 44865975, 43750575, 42126975, 40051495, 37594305, 34835625, 31861500, 28759500, 25614639, 22505751, 19502505, 16663185, 14033305, 11645073, 9517662, 7658190, 6063255, 4720815, 3612231, 2714319, 2001285, 1446445, 1023660, 708444, 478731, 315315, 202005, 125565, 75501, 43749, 24310, 12870, 6435, 3003, 1287, 495, 165, 45, 9, 1};
	int s;
	memset (ans, 0, sizeof (ans));
	for (j = 0; j < 10; ++ j)//2
		for (k = 0; k < 10; ++ k)//3
			for (l = 0; l < 10; ++ l)//4
				for (m = 0; m < 10; ++ m)//5
					for (n = 0; n < 10; ++ n)//6
						for (o = 0; o < 10; ++ o)//7
							for (p = 0; p < 10; ++ p)//8
								for (q = 0; q < 10; ++ q)//9
									for (r = 0; r < 10; ++ r)//10
										ans[j+k+l+m+n+o+p+q+r] ++;
	ans[1] ++;
	for (i = 0; i < 82; ++ i){
		printf ("%d, ", ans[i]);
	}
	while (~scanf ("%d", &s)){
		printf ("%d\n", ans[s]);
	}
	return 0;
}*/

#include <stdio.h>
#include <string.h>

int main ()
{
	int ans[11][82];
	int s, i, j, k, fans;
	memset (ans, 0, sizeof (ans));
	for (i = 1; i <= 9; ++ i){
		ans[1][i] = 1;
	}
	for (i = 2; i < 10; ++ i){
		for (j = 1; j <= 81; ++ j){
			ans[i][j] = ans[i-1][j];
			for (k = 1; k <= 9 && j - k >= 0; ++ k){
				ans[i][j] += ans[i-1][j-k];
			}
		}
	}
	while (~scanf ("%d", &s)){
		for (i = 1, fans = 0; i < 10; ++ i)fans += ans[i][s];
		printf ("%d\n", s == 1 ? fans+1 : fans);
	}
	return 0;
}
