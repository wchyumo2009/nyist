#include <stdio.h>

int min (int a, int b)
{
	return a < b ? a : b;
}

int main ()
{
	int t;
	scanf ("%d", &t);
	for (int iCase = 1; iCase <= t; ++ iCase){
		int n;
		scanf ("%d", &n);
		n --;
		int ans, mi, sum;
		scanf ("%d", &ans);
		sum = mi = ans;
		int tmp;
		while (n --){
			scanf ("%d", &tmp);
			ans ^= tmp;
			sum += tmp;
			mi = min (mi, tmp);
		}
		printf ("Case #%d: ", iCase);
		if (ans != 0)printf ("NO\n");
		else printf ("%d\n", sum-mi);
	}
	return 0;
}
