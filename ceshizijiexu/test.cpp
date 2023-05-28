#include <stdio.h>

int main() {
    int num = 0x01020304;
    char *p = (char *)&num;
    if (*p == 0x04) {
        printf("Little Endian\n");
    } else if (*p == 0x01) {
        printf("Big Endian\n");
    } else {
        printf("Unknown\n");
    }
    return 0;
}
