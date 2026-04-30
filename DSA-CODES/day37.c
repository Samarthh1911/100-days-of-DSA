#include <stdio.h>
#include <string.h>

int queue[100], size = 0;

void insert(int val) {
    int i = size - 1;
    // shift larger elements right to maintain sorted order (ascending)
    while (i >= 0 && queue[i] > val) {
        queue[i + 1] = queue[i];
        i--;
    }
    queue[i + 1] = val;
    size++;
}

void delete() {
    if (size == 0) { printf("-1\n"); return; }
    printf("%d\n", queue[0]);
    // shift all elements left
    for (int i = 0; i < size - 1; i++)
        queue[i] = queue[i + 1];
    size--;
}

void peek() {
    if (size == 0) { printf("-1\n"); return; }
    printf("%d\n", queue[0]);
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        char op[10];
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            int val;
            scanf("%d", &val);
            insert(val);
        } else if (strcmp(op, "delete") == 0) {
            delete();
        } else if (strcmp(op, "peek") == 0) {
            peek();
        }
    }

    return 0;
}