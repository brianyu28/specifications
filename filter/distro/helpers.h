#include "bmp.h"

// blur image with strength
void blur(int height, int width, RGBTRIPLE image[height][width]);

// convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]);

// reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]);

// convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width]);
