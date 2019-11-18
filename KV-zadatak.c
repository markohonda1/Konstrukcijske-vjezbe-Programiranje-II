#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Header.h"



int main() {

	FILE *fp = fopen("Proizvodi.bin", "rb");

	if (fp == NULL) {
		fp = fopen("Proizvodi.bin", "wb");
		if (fp == NULL) {
			perror("Kreiranje");
		}
		else {

			fclose(fp);
		}
	}
	else {
		fclose(fp);
	}
	
	izbornik();
}


