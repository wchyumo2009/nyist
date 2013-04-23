#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
//#include <iostream>
//#include <algorithm>

//using namespace std;

//int count[1000000000];

/*void get_min_nums(int *arr, int n, int *result, int k)
{
	int max, min, len, i;
	int *count;
	if (arr == NULL || n <= 0 || result == NULL || k <= 0)
		return;
	max = min = arr[0];
	for (i = 1; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		else if (arr[i] < min)
			min = arr[i]; //以上，通过一次遍历得知最大值和最小值
	}
	len = max - min + 1;
	if ((count = (int *) malloc(sizeof(int) * len)) == NULL)
		return;
	memset(count, 0, sizeof(int) * len);
	for (i = 0; i < n; i++)
		count[arr[i] - min]++; //元素值减去最小值作为计数数组下标
	for (i = 0; i < len; i++)
	{
		if (count[i] == 0)
			continue;
		if (count[i] >= k)
		{
			while (k--)
			*result++ = min + i;
			break;
		}
		k -= count[i];
		while (count[i]--)
		*result++ = min + i;
	}
	free(count);
}*/

void swap(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void HeapAdjust (int *a, int i, int size)
{
    int t = a[i];
    bool flag = true;
    int j = (i<<1);
    while (j <= size && flag){
        if (j+1<=size && a[j] < a[j+1]) ++ j;
        if (t >= a[j])flag = false;
        else {
            a[i] = a[j];
            i = j;
            j = (i<<1);
        }
    }
    a[i] = t;
}


//heap sort 
void HeapBuild (int *a, int size){
    int i;
    for (i = size/2; i >= 1; -- i){
        HeapAdjust (a, i, size);
    }
}
 
void HeapSort (int *a, int size)
{
    int i, tmp;
    for (i = size; i >= 1; -- i){
        tmp = a[1];
        a[1] = a[i];
        a[i] = tmp;
        HeapAdjust (a, 1, i-1);
    }
}

//partition
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
/*
int find_kth(int *v, int n, int k) {
    if (n == 1 && k == 0) return v[0];
 
    int m = (n + 4)/5;
    int medians[4005];
    for (int i=0; i<m; i++) {
        if (5*i + 4 < n) {
            int *w = v + 5*i;
            for (int j0=0; j0<3; j0++) {
                int jmin = j0;
                for (int j=j0+1; j<5; j++) {
                    if (w[j] < w[jmin]) jmin = j;
                }
                swap(w[j0], w[jmin]);
            }
            medians[i] = w[2];
        } else {
            medians[i] = v[5*i];
        }
    }
 
    int pivot = find_kth(medians, m, m/2);
 
    for (int i=0; i<n; i++) {
        if (v[i] == pivot) {
            swap(v[i], v[n-1]);
            break;
        }
    }
 
    int store = 0;
    for (int i=0; i<n-1; i++) {
        if (v[i] < pivot) {
            swap(v[i], v[store++]);
        }
    }
    swap(v[store], v[n-1]);
 
    if (store == k) {
        return pivot;
    } else if (store > k) {
        return find_kth(v, store, k);
    } else {
        return find_kth(v+store+1, n-store-1, k-store-1);
    }
}*/

void output (int *a, int len)
{
	printf ("%d", a[1]);
	for (int i = 2; i <= len; ++ i){
		printf (" %d", a[i]);
	}
	printf ("\n");
}

int cmp (const void *a, const void *b)
{
	int *fa = (int *)a;
	int *fb = (int *)b;
	return *fa - *fb < 0 ? -1 : 1;
}

int main ()
{
	int n, k, arr[200005], i;
	while (~scanf ("%d%d", &n, &k)){
		for (i = 1; i <= n; ++ i){
			scanf ("%d", &arr[i]);
		}
		if (k <= n/2){
			HeapBuild (arr, k);
		    for (i = k+1; i <= n; i ++){
		        if (arr[i] < arr[1]){
					arr[1] = arr[i];
		        	HeapAdjust (arr, 1, k);
		        }
		    }
		    HeapSort (arr, k);
		}
		else {
			srand(time(NULL));
		    partition(arr, 1, n, k);
//			find_kth (arr, n, k);
		    qsort(arr+1, k, sizeof (int), cmp);
		}
		output (arr, k);
	}
	return 0;
}
