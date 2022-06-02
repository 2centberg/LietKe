#include <stdio.h>
void Init(int s[], int k, int n) {
    for (int i = 1; i <= k - 1; i++)
        s[i] = 0;
    s[k] = n;
}
void Out(int s[], int k) {
    static int count = 1;
    printf("%d : ", count++);
    for (int i = 1; i <= k; i++)
        printf("%d ", s[i]);
    printf("\n");
}
void NextConfigure(int s[], int k, int n) {
    int i = k;
    while (s[i] == 0) --i;
    ++s[i - 1];
    int t = s[i];
    for (int j = i; j <= k - 1; j++)
        s[j] = 0;
    s[k] = t - 1;
}
int main() {
    printf("x1+x2+...+xk=n\n");
    int n; int k;
    printf("n : "); scanf("%d", &n);
    printf("k : "); scanf("%d", &k);
    int s[100];
    Init(s,k,n);
    Out(s, k);
    while (s[1] != n) { // last configure
        NextConfigure(s, k, n);
        Out(s, k);
    }
    return 0;
}