#include <stdio.h>
#include <stdlib.h>
#include "ppm.h"

/* Reads a binary PPM (P6) file into a freshly allocated Image. */
Image *ppm_read(const char *path) {
    FILE *f = fopen(path, "rb");
    if (!f) return NULL;

    char magic[3];
    int width, height, maxval;
    if (fscanf(f, "%2s %d %d %d", magic, &width, &height, &maxval) != 4 ||
        magic[0] != 'P' || magic[1] != '6') {
        fclose(f);
        return NULL;
    }
    fgetc(f); /* skip the single whitespace byte after maxval */

    Image *img = malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->pixels = malloc((size_t)width * height * 3);

    if (fread(img->pixels, 1, (size_t)width * height * 3, f) != (size_t)width * height * 3) {
        free(img->pixels);
        free(img);
        fclose(f);
        return NULL;
    }

    fclose(f);
    return img;
}

/* Writes an Image out as a binary PPM (P6) file. Returns 0 on success. */
int ppm_write(const char *path, const Image *img) {
    FILE *f = fopen(path, "wb");
    if (!f) return -1;

    fprintf(f, "P6\n%d %d\n255\n", img->width, img->height);
    size_t n = (size_t)img->width * img->height * 3;
    size_t written = fwrite(img->pixels, 1, n, f);

    fclose(f);
    return written == n ? 0 : -1;
}

void ppm_free(Image *img) {
    if (!img) return;
    free(img->pixels);
    free(img);
}
