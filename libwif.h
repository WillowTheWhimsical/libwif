#ifndef WIF_H
#define WIF_H

typedef struct wif_image {
	unsigned char* data;
	unsigned int width, height;
} wif_image;

// Parse WIF data from memory
int wif_parse(wif_image* img, char* data);

// Parse WIF data from a file
int wif_parsef(wif_image* img, const char* path);

// Write WIF data to a file
int wif_write(wif_image* img, const char* path);

// Free allocated WIF data from memory
void wif_free(wif_image* img);

#endif
