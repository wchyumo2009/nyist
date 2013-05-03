/*	auther: C.H King
 *	buildtime: 2013/05/03
 * mod n and than *10+1
 */

#include <stdio.h>

int main ()
{
	int n, t;
	while (~scanf ("%d", &n)){
		t = 1;
		int ans = 1;
		while (t){
			t %= n;
			if (t)ans ++;
			else break;
			t = t*10+1;
		}
		printf ("%d\n", ans);
	}
	return 0;
}
