#include "util.h"

int main() {
    StringArr_t lines = NULL;
    ReadLines("input.txt", &lines);

    uint32_t largestValue = 0;
    size_t idx = 0;
    while (idx < arrlen(lines)) {
        uint32_t total = 0;
        while (idx < arrlen(lines) && strnlen(lines[idx], LINEBUF_SIZE) > 0) {
            total += atoi(lines[idx++]);
        }
        idx++;

        if (total > largestValue) {
            largestValue = total;
        }
    }

    printf("Largest value: %d\n", largestValue);

    return 0;
}
