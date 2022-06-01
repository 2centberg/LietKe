#include <stdio.h>
void Init(int a[], int n);
void Print(int a[], int n);
int isLast(int a[],int n);
void Gen(int a[], int n);
void Swap(int *a, int *b);
int main()
{
	int n; scanf("%d", &n);
	int a[100];
	Init(a, n);
	Print(a, n);
	int stop = isLast(a, n);
	for (; !stop;)
	{
		Gen(a, n);
		Print(a, n);
		stop = isLast(a, n);
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
int isLast(int a[], int n)
{
	for (int i = 1; i < n; i++)
		if (a[i] < a[i + 1]) return 0;
	return 1;
};
void Swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
};
void Gen(int a[], int n)
{
	for (int i = n; i > 1; i--)
		if (a[i] > a[i - 1]) //a[i-1] sai vi tri
		{
			for (int j = n; j > i - 1; j--)
				if (a[j] > a[i - 1]) // phan tu cuoi cung >a[i-1]
				{
					Swap(&a[i - 1], &a[j]);
					int l = i, r = n;
					for (; l < r; l++, r--)
						Swap(&a[l], &a[r]);
					break;
				}
			return;
		}
};