/*	Auther: C.H King
 *	filename: nyist_667.c
 *	buildtime: 2013/4/20
 *	type: geometry
 */

#include <stdio.h>
#include <math.h>

//PI
#define PI acos (-1.0)

//calculate the distance of two point
double distance (double x, double y, double x2, double y2)
{
	return sqrt (1.0*(x2-x)*(x2-x)+(y2-y)*(y2-y));
}

//line get the X
double getX (double k, double x, double y, double ny)
{
	return (ny-y)/k+x+0.0;
}

//line get the Y
double getY (double k, double x, double y, double nx)
{
	return k*(nx-x)+y+0.0;
}

//bsearch to find the x in line that satisfy the distance d
double getnX (double d, double x, double y, double k, double left, double right, int a)
{
	double mid;
	while (right - left > 1e-6){
		mid = (left + right)/2.0;
		if (d < distance (x, y, mid, getY(k, x, y, mid))){
			if (k > 0){
				if (a < 90){
					right = mid;
				}
				else if (a < 270){
					left = mid;
				}
			}
			else if (k < 0){
				if (a < 180){
					left = mid;
				}
				else right = mid;
			}
		}
		else {
			if (k > 0){
				if (a < 90)left = mid;
				else right = mid;
			}
			else if (k < 0){
				if (a < 180)right = mid;
				else left = mid;
			}
		}
	}
	return mid;
}


//maybe it runs even circles, maybe it runs odd sircles.but you should deal with them seperatly.

int main ()
{
	int tml, tmw, tmx, tmy, tmr, a, v, s;
//	printf ("%f\n", tan (PI/4));
	while (scanf ("%d%d%d%d%d%d%d%d", &tml, &tmw, &tmx, &tmy, &tmr, &a, &v, &s)){
		if (tml == 0 && tmw == 0 && tmx == 0 && tmy == 0 && tmr == 0 && a == 0 && v == 0 && s == 0)break;
		int ts = v*s;
		if (a == 0){
			int time = ts / (tml-2*tmr);
			ts = ts % (tml-2*tmr);
			if (!(time & 1)){
				if (ts + tmx <= tml-tmr)printf ("%.2f %.2f\n", (double)(ts+tmx), (double)tmy);
				else printf ("%.2f %.2f\n", 2.0*(tml-tmr)-(ts+tmx), (double)tmy);
			}
			else {
				tmx = tml - tmx;
				if (tmx - ts >= tmr)printf ("%.2f %.2f\n", (double)(tmx-ts), (double)tmy);
				else printf ("%.2f %.2f\n", (double)(ts-tmx+2.0*tmr), (double)tmy);
			}
		}
		else if (a == 180){
			int time = ts / (tml-2*tmr);
			ts = ts % (tml-2*tmr);
			if (!(time&1)){
				if (tmx - ts >= tmr)printf ("%.2f %.2f\n", (double)(tmx-ts), (double)tmy);
				else printf ("%.2f %.2f\n", (double)(ts-tmx+2.0*tmr), (double)tmy);
			}
			else {
				tmx = tml - tmx;
				if (tmx + ts <= tml - tmr)printf ("%.2f %.2f\n", (double)(tmx+ts), (double)tmy);
				else printf ("%.2f %.2f\n", 2.0*(tml-tmr)-(ts+tmx), (double)tmy);
			}
		}
		else if (a == 90){
			int time = ts / (tmw-2*tmr);
			ts = ts % (tmw-2*tmr);
			if (!(time&1)){
				if (ts + tmy <= tmw-tmr)printf ("%.2f %.2f\n", (double)tmx, (double)(ts+tmy));
				else printf ("%.2f %.2f\n", (double)tmx, 2.0*(tmw-tmr)-(ts+tmy));
			}
			else {
				tmy = tmw-tmy;
				if (tmy-ts >= tmr)printf ("%.2f %.2f\n", (double)tmx, (double)(tmy-ts));
				else printf ("%.2f %.2f\n", (double)tmx, (double)(ts-tmy+2.0*tmr));
			}
		}
		else if (a == 270){
			int time = ts / (tmw-2*tmr);
			ts = ts % (tmw-2*tmr);
			if (!(time&1)){
				if (tmy-ts >= tmr)printf ("%.2f %.2f\n", (double)tmx, (double)(tmy-ts));
				else printf ("%.2f %.2f\n", (double)tmx, (double)(ts-tmy+2.0*tmr));
			}
			else {
				tmy = tmw-tmy;
				if (ts + tmy <= tmw-tmr)printf ("%.2f %.2f\n", (double)tmx, (double)(ts+tmy));
				else printf ("%.2f %.2f\n", (double)tmx, 2.0*(tmw-tmr)-(ts+tmy));
			}
		}
		else {
			double ha = a/180.0*PI;
			double k1;
			double k2, tx, ty;
			double vs = 1.0*v*s;
			double x = tmx+0.0, y = tmy+0.0, w = tmw+0.0, l = tml+0.0, r = tmr+0.0;
			if (a < 90 || (a > 180 && a < 270)){
				k1 = tan (ha);
				k2 = tan (PI-ha);
			}
			else {
				k2 = tan (ha);
				k1 = tan (PI-ha);
			}
			while (1){
				if (a < 90){
					ty = w-r;
					tx = getX (k1, x, y, ty);
					if (tx <= l-r){
						double d = distance (x, y, tx, ty);
						if (d >= vs){
							tx = getnX (vs, x, y, k1, x, l-r, a);
							printf ("%.2f %.2f\n", tx+0.005, getY (k1, x, y, tx)+0.005);
							break;
						}
						a = 360-a;
						x = tx, y = ty;
						vs -= d;
					}
					else {
						tx = l-r;
						ty = getY(k1, x, y, tx);
						double d = distance (x, y, tx, ty);
						if (d >= vs){
							tx = getnX (vs, x, y, k1, x, l-r, a);
							printf ("%.2f %.2f\n", tx+0.005, getY (k1, x, y, tx)+0.005);
							break;
						}
						a = 180-a;
						x = tx, y = ty;
						vs -= d;
					}
				}
				else if (a < 180){
					ty = w-r;
					tx = getX (k2, x, y, ty);
					if (tx >= r){
						double d = distance (x, y, tx, ty);
						if (d >= vs){
							tx = getnX (vs, x, y, k2, r, x, a);
							printf ("%.2f %.2f\n", tx+0.005, getY (k2, x, y, tx)+0.005);
							break;
						}
						a = 360-a;
						x = tx, y = ty;
						vs -= d;
					}
					else {
						tx = r;
						ty = getY (k2, x, y, tx);
						double d = distance (x, y, tx, ty);
						if (d >= vs){
							tx = getnX (vs, x, y, k2, r, x, a);
							printf ("%.2f %.2f\n", tx+0.005, getY (k2, x, y, tx)+0.005);
							break;
						}
						a = 180-a;
						x = tx, y = ty;
						vs -= d;
					}
				}
				else if (a < 270){
					tx = r;
					ty = getY (k1, x, y, tx);
					if (ty >= r){
						double d = distance (x, y, tx, ty);
						if (d >= vs){
							tx = getnX (vs, x, y, k1, r, x, a);
							printf ("%.2f %.2f\n", tx+0.005, getY (k1, x, y, tx)+0.005);
							break;
						}
						a = 540-a;
						x = tx, y = ty;
						vs -= d;
					}
					else {
						ty = r;
						tx = getX (k1, x, y, ty);
						double d = distance (x, y, tx, ty);
						if (d >= vs){
							tx = getnX (vs, x, y, k1, r, x, a);
							printf ("%.2f %.2f\n", tx+0.005, getY (k1, x, y, tx)+0.005);
							break;
						}
						a = 360-a;
						x = tx, y = ty;
						vs -= d;
					}
				}
				else if (a < 360){
					ty = r;
					tx = getX (k2, x, y, ty);
					if (tx <= l-r){
						double d = distance (x, y, tx, ty);
						if (d >= vs){
							tx = getnX (vs, x, y, k2, x, l-r, a);
							printf ("%.2f %.2f\n", tx+0.005, getY (k2, x, y, tx)+0.005);
							break;
						}
						a = 360-a;
						x = tx, y = ty;
						vs -= d;
					}
					else {
						tx = l-r;
						ty = getY (k2, x, y, tx);
						double d = distance (x, y, tx, ty);
						if (d >= vs){
							tx = getnX (vs, x, y, k2, x, l-r, a);
							printf ("%.2f %.2f\n", tx+0.005, getY (k2, x, y, tx)+0.005);
							break;
						}
						a = 540-a;
						x = tx, y = ty;
						vs -= d;
					}
				}
			}
		}
	}
	return 0;
}
