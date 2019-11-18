#ifndef HEADER_H
#define HEADER_H


typedef struct proizvod {
	char ime_proizvoda[35];
	float cijena;
	int kolicina;
	unsigned short dan;
	unsigned short mjesec;
	unsigned short godina;
}PROIZVOD;


PROIZVOD* ZauzimanjePr(PROIZVOD* ,int );
int BrojProizvoda();
int UnosProizvoda(PROIZVOD* , int );
void IspisProizvoda(PROIZVOD* ,int);
void maxCijena(PROIZVOD* ,int);
void minCijena(PROIZVOD* , int );
void mjehuricastoSortiranjeMax(PROIZVOD* , int );
void mjehuricastoSortiranjeMin(PROIZVOD*, int);
void mjehuricastoSortiranjeMinKol(PROIZVOD* pokNaPr, int n);
void mjehuricastoSortiranjeMaxKol(PROIZVOD* pokNaPr, int n);
void izbornik();

#endif // !HEADER_H

