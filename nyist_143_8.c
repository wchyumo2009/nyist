/*	auther: C.H King
 *	buildtime: 2013/4/27
 */

#include <stdio.h>
#include <stdbool.h>

int main ()
{
	int arr[5];
	int i;
	while (~scanf ("%d%d%d%d%d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4])){
		int a = arr[1] - arr[0], b = 1, t = arr[4];
		if (arr[0] != 0 && arr[1] != 0 && arr[2] != 0 && arr[3] != 0 && arr[4] != 0){
			b = arr[1]/arr[0];
		}
		if ((arr[2]-arr[1] == a) && (arr[3]-arr[2] == a) && (arr[4]-arr[3] == a)){
			for (i = 0; i < 5; ++ i){
				t += a;
				printf ("%d ", t);
			}
			printf ("\n");
		}
		else if ((arr[0] != 0 && arr[1] != 0 && arr[2] != 0 && arr[3] != 0 && arr[4] != 0) && (arr[1] == b*arr[0]) && (arr[2] == b*arr[1]) && (arr[3] == b*arr[2]) && (arr[4] == b*arr[3])){
			for (i = 0; i < 5; ++ i){
				t *= b;
				printf ("%d ", t);
			}
			printf ("\n");
		}
		else if ((arr[2] == arr[1] + arr[0]) && (arr[3] == arr[2] + arr[1]) && (arr[4] == arr[3]+arr[2])){
			int tm = arr[3];
			for (i = 0; i < 5; ++ i){
				int ans = t+tm;
				tm = t;
				t = ans;
				printf ("%d ", t);
			}
			printf ("\n");
		}
		else printf ("None\n");
	}
	return 0;
}
