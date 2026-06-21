#ifndef PPM_H
#define PPM_H

typedef struct {
    int width;
    int height;
    unsigned char *pixels; /* RGB triplets, width * height * 3 bytes */
} Image;

Image *ppm_read(const char *path);
int ppm_write(const char *path, const Image *img);
void ppm_free(Image *img);

#endif
