#include <stdio.h>
#include <stdbool.h>

#define MAX_FRIENDS 100 // 

int start[MAX_FRIENDS + 1]; 
int value[MAX_FRIENDS * 2]; 


void initialize() {
    for (int i = 0; i <= MAX_FRIENDS; i++) {
        start[i] = -1;
    }
}
void add(int u, int v) {
    value[start[u]] = v;
    start[u]++;
    value[start[v]] = u;
    start[v]++;
}
void unfriend(int u, int v) {
    for (int i = 0; i < start[u]; i++) {
        if (value[i] == v) {
            while (i < start[u] - 1) {
                value[i] = value[i + 1];
                i++;
            }
            start[u]--;
            break;
        }
    }
    for (int i = 0; i < start[v]; i++) {
        if (value[i] == u) {
            while (i < start[v] - 1) {
                value[i] = value[i + 1];
                i++;
            }
            start[v]--;
            break;
        }
    }
}
void list(int u) {
    printf("Friend %d:", u);
    for (int i = 0; i < start[u]; i++) {
        printf(" %d", value[i]);
    }
    printf("\n");
}
int main() {
    initialize();

    while (true) {
        char cmd[10];
        int u, v;
        scanf("%s", cmd);

        if (cmd[0] == 'A') {
            scanf("%d %d", &u, &v);
            add(u, v);
        } else if (cmd[0] == 'U') {
            scanf("%d %d", &u, &v);
            unfriend(u, v);
        } else if (cmd[0] == 'L') {
            scanf("%d", &u);
            list(u);
        } else if (cmd[0] == 'e') {
            break;
        }
    }

    return 0;
}

