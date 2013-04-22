/*	Auther: C.H King
 *	file name: nyist_286.c
 *	build time: 2013/4/22
 *	type: easy
 *	count the most count of animals
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

#define LEN 26

typedef struct animal{
	int count;
	char ani[11];
	struct animal *next[LEN];
}animal;

animal root = {0, "NULL"};
int max = 0;
char anim[11];

void insert (char *an, int len)
{
	int i;
	animal *cur, *newanimal;
	cur = &root;
	for (i = 0; i < len; ++ i){
		if (cur->next[an[i]-'a'] == NULL){
			newanimal = (animal *)malloc(sizeof (animal));
			memset (newanimal, 0, sizeof (animal));
			cur->next[an[i]-'a'] = newanimal;
		}
		cur = cur->next[an[i]-'a'];
	}
	cur->count = 1;
	strcpy (cur->ani, an);
}

bool find (char *an, int len)
{
	animal *cur = &root;
	int i;
	for (i = 0; i < len; ++ i){
		if (cur->next[an[i]-'a'] != NULL){
			cur = cur->next[an[i]-'a'];
		}
		else return false;
	}
	if (i >= len){
		cur->count ++;
		if (max < cur->count){
			max = cur->count;
			strcpy (anim, cur->ani);
		}
	}
	return true;
}

int main ()
{
	char an[11];
	int t, i;
	scanf ("%d", &t);
	getchar ();
	for (i = 0; i < t; ++ i){
		gets (an);
		int len = strlen (an);
		if (!find (an, len)){
			insert (an, len);
		}
	}
	if (t == 1)printf ("%s 1\n", an);
	else {
		printf ("%s %d\n", anim, max);
	}
	return 0;
}
