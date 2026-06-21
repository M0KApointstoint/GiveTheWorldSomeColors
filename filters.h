#ifndef FILTERS_H
#define FILTERS_H

#include "ppm.h"

void filter_grayscale(Image *img);
void filter_invert(Image *img);
void filter_flip(Image *img);
void filter_brightness(Image *img, int amount);
void filter_blur(Image *img);

#endif
