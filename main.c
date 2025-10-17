#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>

void wspolczynniki(float* dane, int * ilosc_probek) {
	printf("Podaj wspolczynnik A: ");
	scanf("%f", &dane[0]);
	printf("Podaj wspolczynnik B: ");
	scanf("%f", &dane[1]);
	printf("Podaj wspolczynnik C: ");
	scanf("%f", &dane[2]);
	printf("Podaj ilosc probek: ");
	scanf("%d", ilosc_probek);

}

void granice(float* xmin, float* xmax) {
	printf("Podaj lewa granice: ");
	scanf("%f", xmin);
	printf("Podaj prawa granice: ");
	scanf("%f", xmax);
}

void generator(float* sygnal, float* dane, float xmin, float xmax, int ilosc_probek) {
	float deltax;
	deltax = (xmax - xmin) / ilosc_probek;

	for (int i = 0; i < ilosc_probek; i++) {
		sygnal[i] = dane[0] * sin((xmin + i * deltax) / dane[0]) + dane[1] * cos((xmin + i * deltax) / dane[1]) + dane[2];
	}

}

void zapis(float* sygnal, int ilosc_probek) {
	FILE* plik;
	plik = fopen("sygnal.csv", "w");
	for (int i = 0; i < ilosc_probek; i++) {
		fprintf(plik, "%f\n", sygnal[i]);
	}
	fclose(plik);
}

int main() {
	setlocale(LC_ALL, "polish_poland");
	float dane[3];
	float xmin, xmax;
	float* sygnal;
	int n;

	wspolczynniki(dane, &n);
	sygnal = malloc(n * sizeof(float));
	granice(&xmin, &xmax);
	generator(sygnal, dane, xmin, xmax, n);
	zapis(sygnal, n);
	free(sygnal);
	return 0;
}