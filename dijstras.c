#include <stdio.h>

#define MAX 10

int choose(int dist[], int s[], int n) {
    int j = 1, min = 100, w;
    for (w = 1; w <= n; w++)
        if ((dist[w] < min) && (s[w] == 0)) {
            min = dist[w];
            j = w;
        }
    return j;
}

void spath(int v, int cost[][MAX], int dist[], int n) {
    int w, u, i, num, s[MAX];
    for (i = 1; i <= n; i++) {
        s[i] = 0;
        dist[i] = cost[v][i];
    }
    s[v] = 1;
    dist[v] = 0;

    for (num = 2; num <= n; num++) {
        u = choose(dist, s, n);
        s[u] = 1;
        for (w = 1; w <= n; w++)
            if ((dist[u] + cost[u][w]) < dist[w] && !s[w])
                dist[w] = dist[u] + cost[u][w];
    }
}

int main() {
    int i, j, cost[MAX][MAX], dist[MAX], n, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix (use 999 for infinity):\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &cost[i][j]);
    printf("Enter the source vertex: ");
    scanf("%d", &v);

    spath(v, cost, dist, n);

    printf("Shortest distances from vertex %d:\n", v);
    for (i = 1; i <= n; i++)
        printf("%d to %d = %d\n", v, i, dist[i]);

    return 0;
}

