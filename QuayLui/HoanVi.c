#include <stdio.h>
void permutation(int k, int p[], int n, int c[]);
void out(int a[], int n);
void main(void)
{
	int n;
	scanf("%d", &n);
	int p[100];
	int c[100];
	for (int i = 1; i <= n; i++)
		c[i] = 1;
	permutation(1, p, n, c);
};
void permutation(int k, int p[], int n, int c[])
{
	for (int i = 1; i <= n; i++)
	{
		if (c[i] == 1)
		{
			p[k] = i;
			c[i] = 0;
			if (k == n) out(p, n);
			else permutation(k + 1, p, n, c);
			c[i] = 1;
		}
	}
};
void out(int a[], int n)
{
	static int count = 1;
	printf("%d : ", count++);
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	printf("\n");
};
