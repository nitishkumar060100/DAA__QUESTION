/ Kruskal's Algorithm
#include <stdio.h>
#include <stdlib.h>
struct Edge {
    int u, v, weight;
};
int parent[100];
int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}
void unionSet(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b)
        parent[b] = a;
}
int compare(const void *a, const void *b) {
    struct Edge *e1 = (struct Edge *)a;
    struct Edge *e2 = (struct Edge *)b;
    return e1->weight - e2->weight;
}
int main() {
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);
    struct Edge edges[E];
    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d",
              &edges[i].u,
              &edges[i].v,
              &edges[i].weight);
    }
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }
    qsort(edges, E, sizeof(struct Edge), compare);
    int totalWeight = 0;
    int count = 0;
    printf("\nEdges in MST:\n");
    for (int i = 0; i < E && count < V - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        if (find(u) != find(v)) {
            printf("%d -- %d = %d\n",
                   u, v, edges[i].weight);
            totalWeight += edges[i].weight;
            unionSet(u, v);
            count++;
        }
    }
    printf("\nMinimum Cost = %d\n", totalWeight);
    return 0;
}
