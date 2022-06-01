#include <stdio.h>
void out(int s[], int n) {
    static int count = 1;
    printf("%d : ", count++);
    for (int i = 1; i <= n; i++) 
        printf("%d ", s[i]);
    printf("\n");
};
void Try(int th, int s[], int visited[], int n, int k) {
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            s[th] = i;
            visited[i] = 1;
            if (th == k) out(s, k);
            else Try(th + 1, s, visited, n, k);
            visited[i] = 0;
        }
    }
};
void Init(int visited[], int n) {
    for (int i = 1; i <= n; i++) 
        visited[i] = 0;
}
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int s[100];
    int visited[100];
    Init(visited, n);
    Try(1, s, visited, n, k);
};