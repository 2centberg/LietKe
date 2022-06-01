#include"iostream"
using namespace std;
void Init(int[], int );
void Print(int[], int);
bool isLast(int[],int );
void Gen(int[], int);
int main()
{
	int n; cin >> n;
	int* a = new int[n + 1];
	Init(a, n);
	Print(a, n);
	int stop = isLast(a, n);
	for (; !stop;)
	{
		Gen(a, n);
		Print(a, n);
		stop = isLast(a, n);
	}
	delete[] a;
};
void Init(int a[], int n)
{
	for (int i = 1; i <= n; i++)
		a[i] = 0;
};
void Print(int a[], int n)
{
	static int count = 1;
	cout << count++ << " : ";
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << "\n";
};
bool isLast(int a[], int n)
{
	for (int i = 1; i <= n; i++)
		if (a[i] == 0) return 0;
	return 1;
};
void Gen(int a[], int n)
{
	for (int i = n; i >= 1; i--) {
		if (a[i] == 0) {
			a[i] = 1;
			for (int j = i + 1; j <= n; j++)
				a[j] = 0;
			return;
		}
	}
};
