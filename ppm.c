#include <stdio.h>
#include <stdlib.h>
#include "ppm.h"

/* Reads a binary (P6) or ASCII (P3) PPM file into a freshly allocated Image. */
Image *ppm_read(const char *path) {
    FILE *f = fopen(path, "rb");
    if (!f) return NULL;

    char magic[3];
    int width, height, maxval;
    if (fscanf(f, "%2s %d %d %d", magic, &width, &height, &maxval) != 4 ||
        magic[0] != 'P' || (magic[1] != '6' && magic[1] != '3')) {
        fclose(f);
        return NULL;
    }

    Image *img = malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    size_t n = (size_t)width * height * 3;
    img->pixels = malloc(n);

    if (magic[1] == '6') {
        fgetc(f); /* skip the single whitespace byte after maxval */
        if (fread(img->pixels, 1, n, f) != n) {
            free(img->pixels);
            free(img);
            fclose(f);
            return NULL;
        }
    } else {
        for (size_t i = 0; i < n; i++) {
            int value;
            if (fscanf(f, "%d", &value) != 1) {
                free(img->pixels);
                free(img);
                fclose(f);
                return NULL;
            }
            img->pixels[i] = (unsigned char)value;
        }
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
