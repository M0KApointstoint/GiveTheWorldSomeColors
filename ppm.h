#ifndef PPM_H
#define PPM_H

typedef struct {
    int width;
    int height;
    unsigned char *pixels; /* RGB triplets, width * height * 3 bytes */
} Image;

#endif
