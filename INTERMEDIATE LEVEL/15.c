#include <stdio.h>

#define MAX 10

int adj[MAX][MAX];
int n = 0;  // number of vertices

void createGraph() {
    int i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
}

void insertEdge() {
    int u, v;
    if(n == 0) {
        printf("Graph not created yet!\n");
        return;
    }
    printf("Enter edge (u v): ");
    scanf("%d%d", &u, &v);
    if(u >= n || v >= n || u < 0 || v < 0) {
        printf("Invalid vertices!\n");
        return;
    }
    adj[u][v] = adj[v][u] = 1;
    printf("Edge added between %d and %d\n", u, v);
}

void printMatrix() {
    int i, j;
    if(n == 0) {
        printf("Graph not created yet!\n");
        return;
    }
    printf("Adjacency Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }
}

void adjacentVertices() {
    int v, i;
    if(n == 0) {
        printf("Graph not created yet!\n");
        return;
    }
    printf("Enter vertex: ");
    scanf("%d", &v);
    if(v >= n || v < 0) {
        printf("Invalid vertex!\n");
        return;
    }
    printf("Vertices adjacent to %d: ", v);
    for(i = 0; i < n; i++) {
        if(adj[v][i] == 1)
            printf("%d ", i);
    }
    printf("\n");
}

int main() {
    int choice;
    while(1) {
        printf("\n1. Create Graph\n2. Insert Edge\n3. Print Adjacency Matrix\n4. List Adjacent Vertices\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        if(choice == 1)
            createGraph();
        else if(choice == 2)
            insertEdge();
        else if(choice == 3)
            printMatrix();
        else if(choice == 4)
            adjacentVertices();
        else if(choice == 5)
            break;
        else
            printf("Invalid choice!\n");
    }
    return 0;
}
