/*	Auther: C.H King
 *	File name: nyist_94.c
 *	Build time: 2013/4/18
 *	Type: easy problem
 */
/*
#include <stdio.h>

int main ()
{
	int n, m, k;
	scanf ("%d", &m);
	while (m --){
		scanf ("%d%d", &n, &k);
		int ans = n;
		while (n>=k){
			int tmp = n/k;
			ans += tmp;
			n -= tmp*k;
			n += tmp;
		}
		printf ("%d\n", ans);
	}
	return 0;
}*/

/*nyist_97 兄弟郊游问题*/
/*
#include <stdio.h>

int main ()
{
	int n, m, x, y, z;
	scanf ("%d", &n);
	while (n --){
		scanf ("%d%d%d%d", &m, &x, &y, &z);
		double minute = 1.0*x*m/(y-x);
		printf ("%.2f\n", z*minute);
	}
	return 0;
}*/

/*nyist_111 分数加减法*/
/*
#include <stdio.h>

int gcd (int a, int b)
{
	if (b == 0)return a;
	return gcd (b, a%b);
}

int main ()
{
	int a, b, c, d;
	char o;
	while (~scanf ("%d/%d%c%d/%d", &a, &b, &o, &c, &d)){
		int e, f;
		f = b*d;
		if (o == '-')e = a*d-c*b;
		else if (o == '+')e = a*d+c*b;
		if (e == 0)printf ("0\n");
		else {
			if (e < 0)printf ("-");
			e = e > 0 ? e : -e;
			int t = gcd (e, f);
			if (f/t == 1)printf ("%d\n", e/t);
			else printf ("%d/%d\n", e/t, f/t);
		}
	}
	return 0;
}*/

/*nyist_112 指数运算*/
/*
#include <stdio.h>

int main ()
{
	int x, n;
	while (~scanf ("%d%d", &x, &n)){
		if (n == 0)printf ("1\n");
		else {
			int i;
			long long ans = 1;
			for (i = 1; i <= n; i ++){
				ans *= x;
			}
			printf ("%lld\n", ans);
		}
	}
	return 0;
}*/

/*nyist_113 字符串替换*/
/*
#include <stdio.h>
#include <string.h>

int main ()
{
	char str[1005];
	while (gets(str)){
		int len = strlen (str), i;
		for (i = 0; i < len; i ++){
			if (str[i] == 'y' && i+2 < len && str[i+1] == 'o' && str[i+2] == 'u'){
				printf ("we");
				i += 2;
			}
			else printf ("%c", str[i]);
		}
		printf ("\n");
	}
	return 0;
}*/

/*nyist_122 Triangular Sums*/
/*
#include <stdio.h>

int main ()
{
	int n, sum, cas, k;
	scanf ("%d", &k);
	for (cas = 1; cas <= k; cas ++){
		scanf ("%d", &n);
		int ans = 0, tmp = 3, i;
		for (i = 1; i <= n; i ++){
			ans += i*tmp;
			tmp += i+2;
		}
		printf ("%d %d %d\n", cas, n, ans);
	}
}*/

/*nyist_124 排序求中位数*/

#include <stdio.h>

int partition (int *input, int n, int start, int end)
{
    int pos = start - 1, i = start, tmp;
    for (;i < end; ++ i){
        if (input[i] < input[end]){
            ++ pos;
            tmp = input[i];
            input[i] = input[pos];
            input[pos] = tmp;
        }
    }
    ++ pos;
    tmp = input[pos];
    input[pos] = input[end];
    input[end] = tmp;
    return pos;
}
 
void getLeastNumbers (int *input, int n, int k)
{
    int start = 0;
    int end = n-1;
    int index = partition (input, n, start, end);
    while (index != k){
        if (index > k){
            end = index - 1;
            index = partition (input, n, start, end);
        }
        else {
            start = index + 1;
            index = partition (input, n, start, end);
        }
    }
}

int main ()
{
	int t, m, arr[1005], i, j;
	scanf ("%d", &t);
	while (t --){
		scanf ("%d", &m);
		for (i = 0; i < m; i ++){
			scanf ("%d", &arr[i]);
		}
		if (m == 1)printf ("%d\n", arr[0]);
		else {
			getLeastNumbers (arr, m, m/2+1);
			int max = arr[0];
			for (i = 1; i <= m/2; i ++){
				if (max < arr[i])max = arr[i];
			}
			printf ("%d\n", max);
		}
	}
	return 0;
}
