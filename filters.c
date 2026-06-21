#include "filters.h"

void filter_grayscale(Image *img) {
    long n = (long)img->width * img->height;
    for (long i = 0; i < n; i++) {
        unsigned char *p = img->pixels + i * 3;
        unsigned char gray = (unsigned char)(0.299 * p[0] + 0.587 * p[1] + 0.114 * p[2]);
        p[0] = p[1] = p[2] = gray;
    }
}
