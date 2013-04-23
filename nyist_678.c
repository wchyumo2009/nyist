/*	auther: C.H King
 *	filename: nyist_678.c
 *	buildtime: 2013/4/23
 *	type: partition method O(n)
 */


#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void partition(int a[], int left, int right, int k)
{
    int randNum = left + (rand() % (right - left + 1));
    int t = a[randNum];
    a[randNum] = a[left];
    a[left] = t;
 
    int i = left;
    int j = right;
    int key = a[left];
    while(i <= j)
    {
        if (a[i] <= key)
            i++;
        else
        {
            int t = a[j];
            a[j] = a[i];
            a[i] = t;
            j--;
        }
    }
    a[left] = a[j];
    a[j] = key;
    if (j == k)
        return;
    else if (j > k)
        return partition(a, left, j - 1, k);
    else
        return partition(a, j + 1, right, k);
}
 
int main()
{
    int n, k;
    int a[100005];
 
    while(scanf("%d%d", &n, &k) != EOF)
    {
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        srand(time(NULL));
        partition(a, 0, n - 1, k - 1);
        int sum = 0;
        for (int i = 0; i < k; ++ i){
        	sum += a[i];
        }
        printf ("%d\n", sum);
    }
}
