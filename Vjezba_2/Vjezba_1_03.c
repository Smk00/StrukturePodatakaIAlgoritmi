#include<stdio.h>
#include<stdlib.h>


int** podijeli(int* niz, int n)
{
	int i, n_pola = n/2;
	int* p1 = (int*)malloc(n_pola * sizeof(int));
	int* p2 = (int*)malloc(n_pola * sizeof(int));
	int** p3 = (int**)malloc(2 * sizeof(int*));


	for (i = 0; i < n_pola; i++)
	{
		p1[i] = niz[i];
		p2[i] = niz[i + n_pola];
	}
	p3[0] = p1;
	p3[1] = p2;

	return p3;
}

void print_niz(int** niz, int n)
{
	int i;
	int pola = n / 2;
	for (i = 0; i < pola; i++)
	{
		printf("%d	",niz[0][i]);
	}

	for (i = 0; i < pola; i++)
	{
		printf("%d	", niz[1][i]);
	}
}

int main(void)
{
	int niz[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int n = sizeof(niz) / sizeof(niz[0]);
	

	int** niz_2 = podijeli(niz, n);
	print_niz(niz_2, n);

	free(niz_2[0]);
	free(niz_2[1]);
	free(niz_2);

	return 0;
}

//int** podijeli(int* niz, int n) – dijeli niz dužine n na dva jednaka dijela i stvara kopije prvog i drugog dijela.
//Funkcija vraća dva pokazivača koji pokazuju na prvi i na drugi dio.