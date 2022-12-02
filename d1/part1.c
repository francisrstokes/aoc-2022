#include "util.h"

int main() {
    StringArr_t lines = NULL;
    ReadLines("input.txt", &lines);

    uint32_t top3[3] = {0};
    size_t idx = 0;
    while (idx < arrlen(lines)) {
        uint32_t total = 0;
        while (idx < arrlen(lines) && strnlen(lines[idx], LINEBUF_SIZE) > 0) {
            total += atoi(lines[idx++]);
        }
        idx++;

        if (total > top3[0]) {
            top3[2] = top3[1];
            top3[1] = top3[0];
            top3[0] = total;
        } else if (total > top3[1]) {
            top3[2] = top3[1];
            top3[1] = total;
        } else if (total > top3[2]) {
            top3[2] = total;
        }
    }

    printf("Top 3 summed: %d\n", top3[0] + top3[1] + top3[2]);

    return 0;
}
