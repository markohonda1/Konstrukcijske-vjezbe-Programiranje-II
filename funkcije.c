#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Header.h"




int BrojProizvoda() {
	int a=0;
	do {
		printf("Koliko proizoda unosite?\n");
		scanf("%d", &a);
	} while (a < 0);
	return a;
}


PROIZVOD* ZauzimanjePr(PROIZVOD* pokNaPr,int n) {
	
	pokNaPr = (PROIZVOD*)calloc(100,sizeof(PROIZVOD));
	return pokNaPr;
}



int UnosProizvoda(PROIZVOD* pokNaPr, int n) {

	static int counter;
	FILE *fp = NULL;
	fp = fopen("Proizvodi.bin", "ab");
	if (fp == NULL) {
		printf("Datoteka ne postoji na disku.\n");

	}
	else {



		for (int i = 0; i < n; i++) {
			printf("\nUnesite ime proizvoda: ");
			scanf(" %34[^\n]", pokNaPr[i].ime_proizvoda);
			printf("Unesite cijenu proizvoda: ");
			scanf("%f", &pokNaPr[i].cijena);
			printf("Unesite kolicinu proizvoda: ");
			scanf("%d", &pokNaPr[i].kolicina);
			printf("Unesite dan unosa proizvoda: ");
			scanf("%hu", &pokNaPr[i].dan);
			printf("Unesite mjesec unosa proizvoda: ");
			scanf("%hu", &pokNaPr[i].mjesec);
			printf("Unesite godinu unosa proizvoda: ");
			scanf("%hu", &pokNaPr[i].godina);
			counter++;
		}
		
			fwrite(pokNaPr, sizeof(PROIZVOD), n, fp);
		
		
	}
	fclose(fp);
	return counter;
}
	
	

	







void IspisProizvoda(PROIZVOD* pokNaPr,int n) {
	
	int i;
	FILE *fp = fopen("Proizvodi.bin", "rb");
	if (fp == NULL) {
		perror("Otvaranje");
	}else {
	
		
		

			fread(pokNaPr , sizeof(PROIZVOD), n, fp);
		
		for (i = 0; i < n; i++) {
		fprintf(stdout,"\nIme %d proizvoda: %s\nCijena %d proizvoda: %f\nKolicina %d proizvoda: %d\nDatum %d unosa:%hu.%hu.%hu\n", i + 1, pokNaPr[i].ime_proizvoda, i + 1, pokNaPr[i].cijena, i + 1, pokNaPr[i].kolicina, i + 1, pokNaPr[i].dan, pokNaPr[i].mjesec, pokNaPr[i].godina);
	}
	
			fclose(fp);
	}
	
	

	
}



void maxCijena(PROIZVOD* pokNaPr,int n) {
	int i;
	float max=0;
	
	FILE *fp = fopen("Proizvodi.bin", "rb");
	if (fp == NULL) {
		perror("Otvaranje");
	}
	else {
	
		fread(pokNaPr, sizeof(PROIZVOD), n, fp);
		max = pokNaPr->cijena;
		
		for (i = 0; i < n; i++) {
			
			
			if (max < pokNaPr[i].cijena) {
				max = pokNaPr[i].cijena;
				
			}
			
		}
		for (i = 0; i < n; i++) {
			if (max == pokNaPr[i].cijena) {
				printf("Proizvod s najvecom cijenom:\t");
				printf("Ime proizvoda: %s\tCijena proizvoda: %f\tKolicina proizvoda: %d\tDatum unosa:%hu.%hu.%hu\n", pokNaPr[i].ime_proizvoda, pokNaPr[i].cijena, pokNaPr[i].kolicina, pokNaPr[i].dan, pokNaPr[i].mjesec, pokNaPr[i].godina);
			}
			}
		fclose(fp);
	}
	
}


void minCijena(PROIZVOD* pokNaPr, int n) {
	int i;
	float min = 0;
	FILE *fp = fopen("Proizvodi.bin", "rb+");
	if (fp == NULL) {
		perror("Otvaranje");
	}
	else {

		fread(pokNaPr, sizeof(PROIZVOD), n, fp);

		for (i = 0; i < n; i++) {
			
			min = pokNaPr[0].cijena;
			if (min > pokNaPr[i].cijena) {
				min = pokNaPr[i].cijena;
				}
		}
		for (i = 0; i < n; i++) {
			if (min == pokNaPr[i].cijena) {
				printf("Proizvod s najmanjom cijenom:\t");
				printf("Ime proizvoda: %s\tCijena proizvoda: %f\tKolicina proizvoda: %d\tDatum unosa:%hu.%hu.%hu\n", pokNaPr[i].ime_proizvoda, pokNaPr[i].cijena, pokNaPr[i].kolicina, pokNaPr[i].dan, pokNaPr[i].mjesec, pokNaPr[i].godina);
			}
		}
		fclose(fp);
	}
	
}


void mjehuricastoSortiranjeMax(PROIZVOD* pokNaPr,int n) {
	int i, j;
	PROIZVOD temp;
	FILE *fp = fopen("Proizvodi.bin", "ab");
	if (fp == NULL) {
		perror("Otvaranje");
	}
	else {
		
			fread(pokNaPr , sizeof(PROIZVOD), n, fp);
		
		for (i = 0; i < n - 1; i++)
		{
			for (j = 0; j < (n - i - 1); j++)
			{
				if (pokNaPr[j].cijena < pokNaPr[j + 1].cijena)
				{
					temp = pokNaPr[j];
					pokNaPr[j] = pokNaPr[j + 1];
					pokNaPr[j + 1] = temp;
				}
			}
		}

		for (i = 0; i < n; i++)
		{

			printf("\nIme: %s\tCijena: %f\tKolicina:%d\tDatum: %hu.%hu.%hu\n", pokNaPr[i].ime_proizvoda, pokNaPr[i].cijena, pokNaPr[i].kolicina, pokNaPr[i].dan, pokNaPr[i].mjesec, pokNaPr[i].godina);
		}printf("\t");
	}
	fclose(fp);
}

void mjehuricastoSortiranjeMin(PROIZVOD* pokNaPr, int n) {
	int i, j;
	PROIZVOD temp;
	FILE *fp = fopen("Proizvodi.bin", "rb");
	if (fp == NULL) {
		perror("Otvaranje");
	}
	else {
		for (i = 0; i < n - 1; i++)
		{
			for (j = 0; j < (n - i - 1); j++)
			{
				if (pokNaPr[j].cijena > pokNaPr[j + 1].cijena)
				{
					temp = pokNaPr[j];
					pokNaPr[j] = pokNaPr[j + 1];
					pokNaPr[j + 1] = temp;
				}
			}
		}

		for (i = 0; i < n; i++)
		{

			printf("\nIme: %s\tCijena: %f\tKolicina:%d\tDatum: %hu.%hu.%hu\n", pokNaPr[i].ime_proizvoda, pokNaPr[i].cijena, pokNaPr[i].kolicina, pokNaPr[i].dan, pokNaPr[i].mjesec, pokNaPr[i].godina);
		}printf("\t");
	}
	fclose(fp);
}


void mjehuricastoSortiranjeMinKol(PROIZVOD* pokNaPr, int n) {
	int i, j;
	PROIZVOD temp;
	FILE *fp = fopen("Proizvodi.bin", "rb");
	if (fp == NULL) {
		perror("Otvaranje");
	}
	else {
		for (i = 0; i < n - 1; i++)
		{
			for (j = 0; j < (n - i - 1); j++)
			{
				if (pokNaPr[j].kolicina > pokNaPr[j + 1].kolicina)
				{
					temp = pokNaPr[j];
					pokNaPr[j] = pokNaPr[j + 1];
					pokNaPr[j + 1] = temp;
				}
			}
		}

		for (i = 0; i < n; i++)
		{

			printf("\nIme: %s\tCijena: %f\tKolicina:%d\tDatum: %hu.%hu.%hu\n", pokNaPr[i].ime_proizvoda, pokNaPr[i].cijena, pokNaPr[i].kolicina, pokNaPr[i].dan, pokNaPr[i].mjesec, pokNaPr[i].godina);
		}printf("\t");
	}
	fclose(fp);
}


void mjehuricastoSortiranjeMaxKol(PROIZVOD* pokNaPr, int n) {
	int i, j;
	PROIZVOD temp;
	FILE *fp = fopen("Proizvodi.bin", "rb");
	if (fp == NULL) {
		perror("Otvaranje");
	}
	else {
		for (i = 0; i < n - 1; i++)
		{
			for (j = 0; j < (n - i - 1); j++)
			{
				if (pokNaPr[j].kolicina < pokNaPr[j + 1].kolicina)
				{
					temp = pokNaPr[j];
					pokNaPr[j] = pokNaPr[j + 1];
					pokNaPr[j + 1] = temp;
				}
			}
		}

		for (i = 0; i < n; i++)
		{

			printf("\nIme: %s\tCijena: %f\tKolicina:%d\tDatum: %hu.%hu.%hu\n", pokNaPr[i].ime_proizvoda, pokNaPr[i].cijena, pokNaPr[i].kolicina, pokNaPr[i].dan, pokNaPr[i].mjesec, pokNaPr[i].godina);
		}printf("\t");
	}
	fclose(fp);
}



void izbornik() {
	PROIZVOD* pokNaPr = NULL;
	int m = 0;
	int n = 0;
	int n1 = 0;
	int a = 0;
	char* exit1 = NULL;
	exit1 = (char*)calloc(2, sizeof(char));

	printf("Dobrodosli...\n");
	


		while (1) {
			printf("Odaberite opciju koju zelite koristiti:\n");
			printf("1)Unos novih proizvoda \t");
			printf("2)Ispis proizvoda\t");
			printf("3)Izlaz iz programa\n");

			do {
				scanf("%d", &n);

				if (n == 1) {
					a = BrojProizvoda();

					pokNaPr = ZauzimanjePr(pokNaPr,a);


					m=UnosProizvoda(pokNaPr, a);
					
					IspisProizvoda(pokNaPr, m);
				}

				if (n == 2) {
					printf("Po kojim kriterijima zelite ispisati proizvode?\n");
					printf("1)Od najvece do najmanje cijene\n");
					printf("2)Od najmanje do najvece cijene\n");
					printf("3)Proizvod s najmanjom cijenom\n");
					printf("4)Proizvod s najvecom cijenom\n");
					printf("5)Od najvece do najmanje kolicine\n");
					printf("6)Od najmanje do najvece kolicine\n");

					do {
						scanf("%d", &n1);
						if (n1 == 1) {

							mjehuricastoSortiranjeMax(pokNaPr, m);
						}
						if (n1 == 2) {
							mjehuricastoSortiranjeMin(pokNaPr, m);
						}
						if (n1 == 3) {

							minCijena(pokNaPr, m);

						}
						if (n1 == 4) {

							maxCijena(pokNaPr, m);


						}
						if (n1 == 5) {

							mjehuricastoSortiranjeMaxKol(pokNaPr, m);


						}
						if (n1 == 6) {

							mjehuricastoSortiranjeMinKol(pokNaPr, m);


						}
					} while (n1 < 1 || n1>6);
				}
				if (n == 3) {
					printf("Jeste li sigurni da zelite izaci iz programa?(Press x)\n");

					int status = -1;

					do {

						scanf("%2s", exit1);
						status = strcmp(exit1, "x");
						if (status)
						{
							printf("\nNetocan unos.Pokusajte ponovno...\n");
						}
						else {
							free(pokNaPr);
							exit(1);
							
						}
					} while (status != 0);
				}


			} while (n < 1 || n>4);
		};
	
}
