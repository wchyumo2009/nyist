/*	Auther: C.H King
 *	File name: nyist_60.c
 *	Build time: 2013/4/17
 *	Type: easy problem
 */
 
#include <stdio.h>
#include <string.h>

int main ()
{
	char name[21], tmp[21], wests, gb;
	int ansmoney, moneysum, avggr, classgr, essay, permoney;
	int n, i, x;
	scanf ("%d", &n);
	while (n --){
		scanf ("%d", &x);
		ansmoney = 0, moneysum = 0;
		while (x --){
			permoney = 0;
			scanf (" %s %d %d %c %c %d", tmp, &avggr, &classgr, &gb, &wests, &essay);
			if (avggr > 80 && essay >= 1){
				permoney += 8000;
			}
			if (avggr > 85 && classgr > 80){
				permoney += 4000;
			}
			if (avggr > 90){
				permoney += 2000;
			}
			if (avggr > 85 && wests == 'Y'){
				permoney += 1000;
			}
			if (classgr > 80 && gb == 'Y'){
				permoney += 850;
			}
			moneysum += permoney;
			if (permoney > ansmoney){
				strcpy (name, tmp);
				ansmoney = permoney;
			}
		}
		printf ("%s\n%d\n%d\n", name, ansmoney, moneysum);
	}
	return 0;
}
