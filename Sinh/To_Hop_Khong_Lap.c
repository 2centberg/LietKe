#include <stdio.h>
void Init(int a[], int n);
void Print(int a[], int n);
int isLast(int a[],int n, int k);
void Gen(int a[], int n, int k);
void Swap(int *a, int *b);
int main()
{
	int n; scanf("%d", &n);
	int k; scanf("%d", &k);
	int a[100];
	Init(a, k);
	Print(a, k);
	while (isLast(a, n, k) == 0)
	{
		Gen(a, n, k);
		Print(a, k);
	}
	return 0;
};
void Init(int a[], int n)
{
	for (int i = 1; i <= n; i++)
		a[i] = i;
};
void Print(int a[], int n)
{
	static int count = 1;
    printf("%d : ", count++);
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	printf("\n");
};
int isLast(int a[], int n, int k)
{
	for (int i = 1; i <= k; ++i)
		if (a[i] != n - k + i)
			return 0;
	return 1;
};
void Swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
};
void Gen(int a[], int n, int k)
{
	int i = k;
	while (a[i] == n - k + i) --i;
	++a[i];
	for (int j = i + 1; j <= k; ++j)
		a[j] = a[j - 1] + 1;
};