#include <stdio.h>
#include <string.h>

int main ()
{
	int t, n, arr[14];
	bool used[14];
	scanf ("%d", &t);
	while (t --){
		scanf ("%d", &n);
		int i, an = 1, p = 0, j;
		memset (used, false, sizeof (used));
		while (an <= n){
			i = an+1;
			bool f = false;
			while (true){
				for (j = p; j < n; ++ j){
					if (!used[j]){
						i --;
						if (i == 0){
							f = true;
							used[j] = true;
							break;
						}
					}
				}
				p = 0;
				if (f)break;
			}
//			printf ("j = %d\n", j);
			arr[j] = an;
			p = j;
			an ++;
		}
		arr[j] = n;
		printf ("%d", arr[0]);
		for (i = 1; i < n; ++ i){
			printf (" %d", arr[i]);
		}
		printf ("\n");
	}
	return 0;
}