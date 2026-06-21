#include "filters.h"

void filter_grayscale(Image *img) {
    long n = (long)img->width * img->height;
    for (long i = 0; i < n; i++) {
        unsigned char *p = img->pixels + i * 3;
        unsigned char gray = (unsigned char)(0.299 * p[0] + 0.587 * p[1] + 0.114 * p[2]);
        p[0] = p[1] = p[2] = gray;
    }
}

void filter_invert(Image *img) {
    long n = (long)img->width * img->height * 3;
    for (long i = 0; i < n; i++) {
        img->pixels[i] = (unsigned char)(255 - img->pixels[i]);
    }
}

/* Flips the image horizontally (mirrors left-right). */
void filter_flip(Image *img) {
    for (int y = 0; y < img->height; y++) {
        unsigned char *row = img->pixels + (long)y * img->width * 3;
        for (int x = 0; x < img->width / 2; x++) {
            unsigned char *a = row + x * 3;
            unsigned char *b = row + (img->width - 1 - x) * 3;
            for (int c = 0; c < 3; c++) {
                unsigned char tmp = a[c];
                a[c] = b[c];
                b[c] = tmp;
            }
        }
    }
}
