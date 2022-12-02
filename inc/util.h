#ifndef AOC_UTILS_H
#define AOC_UTILS_H

#include "stdint.h"
#include "stdbool.h"
#include "stdio.h"
#include "string.h"

#define STB_DS_IMPLEMENTATION
#include "stb-ds.h"

typedef char** StringArr_t;

#define LINEBUF_SIZE (256)

bool ReadLines(const char* filepath, StringArr_t* lines) {
    FILE* fp = fopen(filepath, "rb");

    size_t idx = 0;
    char lineBuf[LINEBUF_SIZE] = {0};

    char next;
    while (fread(&next, 1, 1, fp) == 1) {
        if (next == 0x0D) {
            // Consume the \n
            fread(&next, 1, 1, fp);

            // Create memory for the new line
            char* newLine = malloc(LINEBUF_SIZE);

            // Copy the temp line buffer to the new line
            strncpy(newLine, lineBuf, LINEBUF_SIZE);

            // Push the new line
            arrpush(*lines, newLine);

            // Reset the temp line buffer
            memset(lineBuf, 0, LINEBUF_SIZE);
            idx = 0;
        } else {
            lineBuf[idx++] = next;
        }
    }

    return true;
}

#endif  //AOC_UTILS_H
