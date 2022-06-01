#include <stdio.h>
void print(int s[], int k) {
    static int i = 1;
    printf("%d : ", i++);
    for (int i = 1; i <= k; i++)
        printf("%d ", i[s]);
    printf("\n");
};
void bt(int t, int s[], int k, int n) {
    for (int i = 0; i <= n; i++) {
        s[t] = i;
        if (t == k)
            print(s, k);
        else
            bt(t + 1, s, k, n - s[t]);
    }
};
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int s[100];
    for (int i = 1; i <= k; i++)
        s[i] = 0;
    bt(1, s, k, n);
    return 0;
}