#include <stdio.h>
void out(int s[], int n) {
	static int i = 1;
	printf("%4d : ", i++);
	for (int i = 1; i <= n; i++)
		printf("%d ", s[i]);
	putchar('\n');
};
void init(int s[], int free[], int n) {
	s[0] = 0;
	for (int i = 1; i <= n; i++)
		s[i] = i, free[i] = 1;
};
void dfs(int j, int s[], int n, int k, int free[]) {
	for (int i = s[j - 1] + 1; i <= n - k + j; i++) {
		if (free[i] == 1) {
			s[j] = i;
			free[i] = 0;
			if (j == k)
				out(s, k);
			else
				dfs(j + 1, s, n, k, free);
			free[i] = 1;
		}
	}
};
void main(void) {
	int n, k; scanf("%d%d", &n, &k);
	int s[100], free[100];
	init(s, free, n);
	dfs(1, s, n, k, free);
};