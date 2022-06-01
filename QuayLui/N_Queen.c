#include <stdio.h>
void out(int[], int);
void dfs(int, int[], int, int[], int[], int[]);
void init(int*, int);
int main()
{
	int n;
	scanf("%d", &n);
	int s[30];
	int a[30];
	init(a, n + 1);
	int b[60];
	init(b, 2 * n);
	int c[60];
	init(c, 2 * n);
	dfs(1, s, n, a, b, c);
};
void out(int s[], int n)
{
	static int count = 1;
	printf("%d : ", count++);
	for (int i = 1; i <= n; i++)
		printf("%d ", s[i]);
	putchar('\n');
};
void init(int a[], int n)
{
	for (int i = 1; i <= n; i++)
		a[i] = 1;
};
void dfs(int k, int s[], int n, int a[], int b[], int c[])
{
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == 1 && b[i + k] == 1 && c[i - k + n] == 1)
		{
			a[i] = 0; b[i + k] = 0; c[i - k + n] = 0;
			s[k] = i;
			if (k == n) out(s, n);
			else dfs(k + 1, s, n, a, b, c);
			a[i] = 1; b[i + k] = 1; c[i - k + n] = 1;
		}
	}
};
