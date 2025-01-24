#include <stdio.h>
#include <stdlib.h>

#define nov 4
#define noe 4

int queue[nov];
int front = -1, rear = -1;

void enqueue(int n) {
    if (rear == nov - 1) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = n;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return -1;  // Return an error value
    }
    int v = queue[front];
    front++;
    if (front > rear) {
        front = -1;
        rear = -1;  // Reset the queue when it becomes empty
    }
    return v;
}

int isempty() {
    return (front == -1);
}

void createadjmat(int adjmat[][nov], int edges[][2]) {
    for (int i = 0; i < nov; i++) {
        for (int j = 0; j < nov; j++) {
            adjmat[i][j] = 0;
        }
    }
    for (int i = 0; i < noe; i++) {
        int x = edges[i][0];
        int y = edges[i][1];
        adjmat[x][y] = 1;
        adjmat[y][x] = 1;  // For undirected graph
    }
}

void printadjmat(int adjmat[][nov]) {
    for (int i = 0; i < nov; i++) {
        for (int j = 0; j < nov; j++) {
            printf("%d\t", adjmat[i][j]);
        }
        printf("\n");
    }
}

void bfs(int adjmat[][nov], int visited[], int s) {
    enqueue(s);
    printf("%d ", s);
    visited[s] = 1;

    while (!isempty()) {
        int v = dequeue();
        for (int i = 0; i < nov; i++) {
            if (adjmat[v][i] == 1 && visited[i] == 0) {
                printf("%d ", i);
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main() {
    int edges[noe][2] = {{0, 1}, {0, 2}, {1, 3}, {2, 3}};
    int adjmat[nov][nov];
    createadjmat(adjmat, edges);
    printadjmat(adjmat);
    
    int visited[nov] = {0};  // Initialize visited array
    printf("\nAfter BFS traversal:\n");
    bfs(adjmat, visited, 0);
    return 0;
}