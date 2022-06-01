#include <stdio.h>
#define ln putchar('\n')
void out(int s[], int n) {
    static int count = 1;
    printf("%d : ", count++);
    for (int i = 1; i <= n; i++) 
        printf("%d ", s[i]);
    printf("\n");
};
void Try(int th, int s[], int n, int k) {
    for (int i = 1; i <= n; i++) {
        s[th] = i;
        if (th == k) out(s, k);
        else Try(th + 1, s, n, k);
    }
};
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int s[100];
    Try(1, s, n, k);
};