#include <stdlib.h>
#include <string.h>
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

void filter_brightness(Image *img, int amount) {
    long n = (long)img->width * img->height * 3;
    for (long i = 0; i < n; i++) {
        int v = img->pixels[i] + amount;
        if (v < 0) v = 0;
        if (v > 255) v = 255;
        img->pixels[i] = (unsigned char)v;
    }
}

/* Simple 3x3 box blur: each pixel becomes the average of its neighbors. */
void filter_blur(Image *img) {
    size_t n = (size_t)img->width * img->height * 3;
    unsigned char *src = malloc(n);
    memcpy(src, img->pixels, n);

    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            for (int c = 0; c < 3; c++) {
                int sum = 0, count = 0;
                for (int dy = -1; dy <= 1; dy++) {
                    for (int dx = -1; dx <= 1; dx++) {
                        int ny = y + dy, nx = x + dx;
                        if (ny < 0 || ny >= img->height || nx < 0 || nx >= img->width) continue;
                        sum += src[((size_t)ny * img->width + nx) * 3 + c];
                        count++;
                    }
                }
                img->pixels[((size_t)y * img->width + x) * 3 + c] = (unsigned char)(sum / count);
            }
        }
    }

    free(src);
}

/* Rotates the image 90 degrees clockwise; swaps width/height. */
static void rotate90_cw(Image *img) {
    int sw = img->width, sh = img->height;
    int dw = sh, dh = sw;
    unsigned char *dst = malloc((size_t)dw * dh * 3);

    for (int yd = 0; yd < dh; yd++) {
        for (int xd = 0; xd < dw; xd++) {
            int xs = yd;
            int ys = dw - 1 - xd;
            memcpy(dst + ((size_t)yd * dw + xd) * 3,
                   img->pixels + ((size_t)ys * sw + xs) * 3, 3);
        }
    }

    free(img->pixels);
    img->pixels = dst;
    img->width = dw;
    img->height = dh;
}

/* Rotates the image clockwise by degrees, which must be a multiple of 90. */
void filter_rotate(Image *img, int degrees) {
    int steps = ((degrees / 90) % 4 + 4) % 4;
    for (int i = 0; i < steps; i++) {
        rotate90_cw(img);
    }
}
