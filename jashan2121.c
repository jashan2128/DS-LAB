#include <stdio.h>

int main() {
    int a[] = {1, 4, 5, 7, 8, 9, 40, 60, 100, 120};
    int m = 10;
    int target = 40;

    int low = 0;
    int high = m - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (a[mid] == target) {
            printf("Element found at index %d\n", mid);
            return 0;
        }
        else if (a[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    printf("Element not found\n");
    return 0;
}

