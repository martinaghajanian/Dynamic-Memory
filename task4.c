#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char **strArr;
    int initialSize = 3;
    int totalSize = 5;

    strArr = (char **)malloc(initialSize * sizeof(char *));
    if (strArr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < initialSize; i++) {
        strArr[i] = (char *)malloc(50 * sizeof(char));
        if (strArr[i] == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
    }

    printf("Enter 3 strings: ");
    for (int i = 0; i < initialSize; i++) {
        scanf("%49s", strArr[i]);
    }

    strArr = (char **)realloc(strArr, totalSize * sizeof(char *));
    if (strArr == NULL) {
        printf("Memory reallocation failed!\n");
        return 1;
    }

    for (int i = initialSize; i < totalSize; i++) {
        strArr[i] = (char *)malloc(50 * sizeof(char));
        if (strArr[i] == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
    }

    printf("Enter 2 more strings: ");
    for (int i = initialSize; i < totalSize; i++) {
        scanf("%49s", strArr[i]);
    }

    printf("All strings:");
    for (int i = 0; i < totalSize; i++) {
        printf(" %s", strArr[i]);
    }
    printf("\n");

    for (int i = 0; i < totalSize; i++) {
        free(strArr[i]);
    }
    free(strArr);

    return 0;
}
