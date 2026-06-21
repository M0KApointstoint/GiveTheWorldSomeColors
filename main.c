#include <stdio.h>
#include <string.h>
#include "ppm.h"
#include "filters.h"

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "usage: %s <input.ppm> <filter> <output.ppm>\n", argv[0]);
        return 1;
    }

    Image *img = ppm_read(argv[1]);
    if (!img) {
        fprintf(stderr, "failed to read %s\n", argv[1]);
        return 1;
    }

    if (strcmp(argv[2], "grayscale") == 0) {
        filter_grayscale(img);
    } else if (strcmp(argv[2], "invert") == 0) {
        filter_invert(img);
    } else if (strcmp(argv[2], "flip") == 0) {
        filter_flip(img);
    } else {
        fprintf(stderr, "unknown filter: %s\n", argv[2]);
        ppm_free(img);
        return 1;
    }

    int ok = ppm_write(argv[3], img) == 0;
    ppm_free(img);

    if (!ok) {
        fprintf(stderr, "failed to write %s\n", argv[3]);
        return 1;
    }
    return 0;
}
