#include <stdio.h>
void print(int s[], int k) {
    static int i = 1;
    printf("%d : ", i++);
    for (int i = 1; i <= k; i++)
        printf("%d ", i[s]);
    printf("\n");
};
void bt(int t, int s[], int visited[][100], int k, int n) {
    for (int i = 0; i <= n; i++) {
        if (t == k) {
            s[t] = n;
            print(s, k);
            return;
        }
        if (visited[t][i] == 1)
            continue;
        s[t] = i;
        visited[t][i] = 1;
        bt(t + 1, s, visited, k, n - s[t]);
        visited[t][i] = 0;
    }
};
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int s[100];
    int visited[100][100];
    for (int i = 1; i <= k; i++)
        s[i] = 0;
    for (int i = 1; i <= k; i++)
        for (int j = 0; j <= n; j++)
            visited[i][j] = 0;
    bt(1, s, visited, k, n);
};