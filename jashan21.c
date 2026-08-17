#include <stdio.h>

int main() {
    int a[5] = {10, 5, 20, 8, 1};
    int largest, second;

    largest = a[0];
    second = a[0];

    for(int i = 1; i < 5; i++) {
        if(a[i] > largest) {
            second = largest;
            largest = a[i];
        }
        else if(a[i] > second && a[i] != largest) {
            second = a[i];
        }
    }


    printf("Largest = %d\n", largest);
    printf("Second largest = %d\n", second);
  
    return 0;
}
