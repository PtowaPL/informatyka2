#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void wspolczynniki(float* dane, float* rozdzielczosc) {
	printf("Podaj wspolczynnik A: ");
	scanf("%f", &dane[0]);
	printf("Podaj wspolczynnik B: ");
	scanf("%f", &dane[1]);
	printf("Podaj wspolczynnik C: ");
	scanf("%f", &dane[2]);
	printf("Podaj rozdzielczosc: ");
	scanf("%f", rozdzielczosc);


}

void granice(float* xmin, float* xmax) {
	printf("Podaj lewa granice: ");
	scanf("%f", xmin);
	printf("Podaj prawa granice: ");
	scanf("%f", xmax);
}

void generator(float* sygnal, float* dane, float xmin, float xmax, float rozdzielczosc, int probki) {

	for (int i = 0; i < probki; i++) {
		sygnal[i] = dane[0] * sin((xmin + i * rozdzielczosc) / dane[0]) + dane[1] * cos((xmin + i * rozdzielczosc) / dane[1]) + dane[2];
	}

}


void naprawa(float xmin, float xmax, float rozdzielczosc, int* probki) {
	*probki = (xmax - xmin) / rozdzielczosc;
}

void szum(float* sygnal, float* sygnal_szum, int probki, float* wspolczynniki) {
	float amplituda_szum;
	int zmienna;
	printf("Podaj amplitude szumu: ");
	scanf("%f", &amplituda_szum);

	for (int i = 0; i < probki; i++) {
		zmienna = rand() % 10 + 1;
		if (zmienna < 4) {
			sygnal_szum[i] = sygnal[i] + amplituda_szum;
		}
		else
			sygnal_szum[i] = sygnal[i];

	}
}


void zapis(float* sygnal, float* sygnal_szum, int ilosc_probek) {
	if (sygnal_szum == NULL) {
		FILE* plik;
		plik = fopen("sygnal.csv", "w");
		if (plik == NULL)
		{
			printf("blad");
			return;
		}
		for (int i = 0; i < ilosc_probek; i++) {
			fprintf(plik, "%f\n", sygnal[i]);
		}
		fclose(plik);
	}
	else {
		FILE* plik;
		plik = fopen("sygnal.csv", "w");
		if (plik == NULL)
		{
			printf("blad");
			return;
		}
		for (int i = 0; i < ilosc_probek; i++) {
			fprintf(plik, "%f;%f\n", sygnal[i], sygnal_szum[i]);
		}
		fclose(plik);
	}
}

int main() {
	setlocale(LC_ALL, "polish_poland");
	srand(time(NULL));
	float dane[3];
	float xmin, xmax;
	float* sygnal = NULL;
	float* sygnal_szum = NULL;
	float n;
	int probki = 0;
	int menu = -1;
	while (menu != 4) {
		printf("Wybierz opcje:\n 1. Generowanie sygna³u podstawowego\n 2. Wprowadzanie szumu do sygna³u\n 3. Zapis do pliku\n 4.Zakoñczenie programu\n");
		scanf("%d", &menu);
		switch (menu) {
		case 1:
			wspolczynniki(dane, &n);
			granice(&xmin, &xmax);
			naprawa(xmin, xmax, n, &probki);
			sygnal = malloc(probki * sizeof(float));
			generator(sygnal, dane, xmin, xmax, n, probki);
			printf("Wygenerowano sygnal\n");
			break;
		case 2:
			sygnal_szum = malloc(probki * sizeof(float));
			szum(sygnal, sygnal_szum, probki, dane);
			printf("Wprowadzono szum do sygnalu\n");
			break;
		case 3:
			zapis(sygnal, sygnal_szum, probki);
			printf("Zapisano do pliku\n");
			break;
		case 4:
			printf("Zakoñczenie programu\n");
			break;
		default:
			printf("Nieprawid³owa opcja, spróbuj ponownie.\n");
		}
	}

	
	
	free(sygnal);
	free(sygnal_szum);
	return 0;
}
