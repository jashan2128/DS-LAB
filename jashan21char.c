#include <stdio.h>

int main() {
    char a[] = {'A', 'B', 'B', 'C', 'D'};
    int n = sizeof(a) / sizeof(a[0]);
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                printf("First repeated character is: %c\n", a[i]);
                return 0;
            }
        }
    }

    printf("No repeated character found\n");
    return 0;
}
