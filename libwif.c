#include "wif.h"

#include <stdio.h>
#include <malloc.h>

int wif_parse(wif_image* img, char* data) {
	if (sscanf(data, "#WIF\n%d:%d\n", &img->width, &img->height) != 2)
		return -1;

	img->data = malloc(sizeof(char) * img->width * img->height * 3);

	int index, nl = 0;
	for (index = 0; nl < 2; index++)
		if (data[index] == '\n') nl++;

	for (int i = 0; i < img->width * img->height * 3; i++)
		img->data[i] = data[index+i];

	return 0;
}

int wif_parsef(wif_image* img, const char* path) {
	FILE* file = fopen(path, "r");
	if (file == NULL) return -1;

	fseek(file, 0, SEEK_END);
	int size = ftell(file);
	rewind(file);

	char* data = malloc(sizeof(char) * size);
	fread(data, sizeof(char), size, file);
	fclose(file);
	return wif_parse(img, data);
}

int wif_write(wif_image* img, const char* path) {
	FILE* file = fopen(path, "w");
	if (file == NULL) return -1;

	if (fprintf(file, "#WIF\n%d:%d\n", img->width, img->height) < 0)
		return -1;

	fwrite(img->data, sizeof(char), img->width * img->height * 3, file);

	fclose(file);
	return 0;
}

void wif_free(wif_image* img) {
	free(img->data);
	img->width = 0;
	img->height = 0;
}
