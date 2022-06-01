#include <stdio.h>
void Init(int a[], int visited[], int n);
void Print(int a[], int n);
int isLast(int a[],int n, int k);
void Gen(int a[], int visited[], int n, int k);
void Swap(int *a, int *b);
int main()
{
	int n; scanf("%d", &n);
	int k; scanf("%d", &k);
    int a[100];
    int visited[100] = { 0 };
    Init(a, visited, k);
    Print(a, k);
	while (isLast(a, n, k) == 0)
	{
		Gen(a, visited, n, k);
		Print(a, k);
	}
	return 0;
};
void Init(int a[], int visited[], int n)
{
	for (int i = 1; i <= n; i++)
    {
        a[i] = i;
        visited[i] = 1;
    }
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
        if (a[i] != n - i + 1)
			return 0;
	return 1;
};
void Swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
};
void Gen(int a[], int visited[], int n, int k)
{
    int i = k;

    visited[a[i]] = 0;
    while (1) {
        if (a[i] == n) {
            --i;
            visited[a[i]] = 0;
            continue;
        }
        if(visited[a[i] + 1] == 1)
            ++a[i];
        else 
        {
            ++a[i];
            break;
        }
    }
    visited[a[i]] = 1;
    for (int j = i + 1; j <= k; j++) {
        for (int h = 1; h <= k; h++) {
            if (visited[h] == 0)
            {
                a[j] = h;
                visited[h] = 1;
                break;
            }
        }
    }
}