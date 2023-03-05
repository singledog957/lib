#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
int a[3000006];
int cmp(const void*, const void*);
int comp(int*);
int k;
int main()
{
	int i;
	scanf("%d", &k);
	for (i = 0; i < 3 * k + 1; i++)
	{
		scanf("%d", &a[i]);
	}
	/*qsort(a, 3 * k + 1, sizeof(int), cmp);*/
	printf("%d", comp(a));
}
//int cmp(const void* a, const void* b)
//{
//	return (*(int*)a - *(int*)b);
//}
int comp(int* a)
{
	int i = 0;
	for (; i < 3 * k + 1; i += 3)
	{
		if (a[i] == a[i + 1] && a[i] == a[i + 2])
			continue;
		break;
	}
	if (a[i] == a[i + 1]) return a[i + 2];
	else if (a[i] == a[i + 2]) return a[i + 1];
	else if (a[i + 1] == a[i + 2]) return a[i];
}