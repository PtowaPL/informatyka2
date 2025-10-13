#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


void generator(float* sygnal, float* dane, float xmin, float xmax) {
	float deltax;
	deltax = (xmax - xmin) / 300.0;

	for (int i = 0; i < 300; i++) {
		sygnal[i] = dane[0] * sin(xmin + i * deltax) + dane[1];
	}

}

void wspolczynniki(float* dane, float* x1, float* x2) {
	printf("Podaj wspolczynnik A: ");
	scanf("%f", &dane[0]);
	printf("Podaj wspolczynnik B: ");
	scanf("%f", &dane[1]);
	printf("Podaj lewa granice przedzialu: ");
	scanf("%f", &*x1);
	printf("Podaj prawa granice przedzialu: ");
	scanf("%f", &*x2);

}

int main() 
{
	float dane[2];
	float xmin, xmax;
	float sygnal[300];

	
	wspolczynniki(dane, &xmin, &xmax);
	generator(sygnal, dane, xmin, xmax);
	printf("Wartosc sygnalu dla x = %f wynosi: %f\n", xmin, sygnal[0]);

	return 0;
}