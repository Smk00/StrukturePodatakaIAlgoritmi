#include<stdio.h>
#include<stdlib.h>


struct Tocka
{
	float x;
	float y;
};

struct Poligon
{
	int n;
	struct Tocka* point;
};

struct Poligon* novi_poligon(float* x, float* y, int n)
{
	int i;
	struct Poligon* ret = (struct Poligon*)malloc(sizeof(struct Poligon));
	struct Tocka* point = (struct Tocka*)malloc(n * sizeof(struct Tocka));
	ret->n = n;

	for (i = 0; i < n; i++)
	{
		point[i].x = x[i];
		point[i].y = y[i];

	}
	ret->point = point;
	return ret;
}

void print_poligon(struct Poligon* poligon)
{
	int i;
	printf("Broj tocki n = %d\n", poligon->n);
	for (i = 0; i < poligon->n; i++)
	{
		printf("Tocka[%d]	x = %f	y = %f\n", i, poligon->point[i].x, poligon->point[i].y);
	}

}

void free_poligon(struct Poligon* poligon)
{
	free(poligon->point);
	free(poligon);
}

struct Tocka** pozitivni(struct Poligon* p, int* np)
{
	int i, j = 0;
	for (i = 0; i < p->n; i++)
	{
		if (p->point[i].x > 0 && p->point[i].y > 0)
		{
			(*np)++;
		}
	}
	
	struct Tocka** novi = (struct Tocka**)malloc((*np) * sizeof(struct Tocka*));

	for (i = 0; i < p->n; i++)
	{
		if (p->point[i].x > 0 && p->point[i].y > 0)
		{
			novi[j] = p->point+i;
			j++;
		}
	}
	return novi;
}

void print_pozitivni(struct Tocka** p, int* np)
{
	int i;
	for (i = 0; i < (*np); i++)
	{
		printf("x = %f	y = %f\n", p[i]->x, p[i]->y);
	}
}

int main(void)
{
	float niz_x[] = { 0,1,2,3,4,5,6,7,8,9 };
	float niz_y[] = { 0,1,2,3,4,5,6,7,8,9 };
	int n = 10;
	int np = 0;

	struct Poligon* rez = novi_poligon(niz_x, niz_y, n);

	struct Tocka** poz = pozitivni(rez, &np);

	print_pozitivni(poz, &np);

	//print_poligon(rez);

	free_poligon(rez);

	free(poz);

	return 0;
}


//Deklarirati strukturu Tocka koja sadrži dva člana : x i y(oba su float).
//Deklarirati strukturu Poligon koja se sadrži dva člana : 
//niz vrhova(svaki vrh u nizu je Tocka) i broj vrhova n. Napisati funkcije za rad sa poligonima :