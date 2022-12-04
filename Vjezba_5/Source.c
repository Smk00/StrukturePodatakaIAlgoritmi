#include<stdio.h>
#include <stdlib.h>
#include<time.h>

int* generiraj(int n) 
{
    int* niz = (int*)malloc(sizeof(int) * n);
    niz[0] = rand() % 5;
    for (int i = 1; i < n; i++) {
        niz[i] = niz[i - 1] + 1 + rand() % 5;
    }
    return niz;
}

void shuffle(int* niz, int n) 
{
    for (int i = 0; i < n; i++) {
        int j = (rand() * rand()) % n;
        int tmp = niz[i];
        niz[i] = niz[j];
        niz[j] = tmp;
    }
}

int compare(const void* a, const void* b)
{

    int va = *((int*)a);
    int vb = *((int*)b);
    return va - vb;
}

void presijek(int* skupA, int n1, int* skupB, int n2)
{
    int counter = 0;
    int i, j;
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            if (skupA[i] == skupB[j])
            {
                counter++;
            }
        }
    }
    //printf("Presijek je %d\n", counter);
}

void presjek_jedan_sortiran(int* skupA, int n1, int* skupB, int n2)
{
    int i;
    int* bsearch_result;
    int counter = 0;

    for (i = 0; i < n1; i++)
    {
        bsearch_result = (int*)bsearch(&skupA[i], skupB, n2, sizeof(int), compare);
        if (bsearch_result)
        {
            counter++;
        }
    }
}
void presjek_oba_sortiran(int* skupA, int n1, int* skupB, int n2)
{
    int counter = 0;

    int i = 0;
    int j = 0;

    while ((i < n1) && (j < n2))
    {
        if (skupA[i] == skupB[j])
        {
            counter++;
            i++;
            j++;
        }
        else if (skupA[i] > skupB[j])
        {
            j++;
        }
        else if(skupB[j]>skupA[i])
        {
            i++;
        }
    }
}
void mjeri_vrijeme_3(void)
{
    int duzina = 100000;
    int korak = 300000;
    int kraj = 3000000;

    long start = 0;
    long stop = 0;
    double konacno = 0;

    for (duzina; duzina < kraj; duzina += korak)
    {
        int* skupA = generiraj(duzina);
        int* skupB = generiraj(duzina);
        shuffle(skupA, duzina);
        shuffle(skupB, duzina);

        start = clock();
        qsort(skupA, duzina, sizeof(int), compare);
        qsort(skupB, duzina, sizeof(int), compare);
        presjek_oba_sortiran(skupA, duzina, skupB, duzina);

        stop = clock();

        konacno = (double)(stop - start) / CLOCKS_PER_SEC;

        printf("Vrijeme: %lf\n", konacno);
        free(skupA);
        free(skupB);
    }
}

void mjeri_vrijeme_2(void)
{
    int duzina = 100000;
    int korak = 300000;
    int kraj = 3000000;

    long start = 0;
    long stop = 0;
    double konacno = 0;

    for (duzina; duzina < kraj; duzina += korak)
    {
        int* skupA = generiraj(duzina);
        int* skupB = generiraj(duzina);
        shuffle(skupA, duzina);
        shuffle(skupB, duzina);

        start = clock();
        qsort(skupB, duzina, sizeof(int), compare);
        presjek_jedan_sortiran(skupA, duzina, skupB, duzina);
        stop = clock();
        konacno = (double)(stop - start) / CLOCKS_PER_SEC;

        printf("Vrijeme: %lf\n", konacno);
        free(skupA);
        free(skupB);
    }

}

void mjeri_vrijeme(void)
{
    int duzina = 10000;
    int korak = 10000;
    int kraj = 100000;

    long start = 0;
    long stop = 0;
    double konacno = 0;

    for (duzina; duzina <= kraj; duzina += korak)
    {
        int* skupA = generiraj(duzina);
        int* skupB = generiraj(duzina);
        shuffle(skupA, duzina);
        shuffle(skupB, duzina);
        
        start = clock();
        presijek(skupA, duzina, skupB, duzina);
        stop = clock();

        konacno = (double)(stop - start) / CLOCKS_PER_SEC;

        printf("Vrijeme: %lf\n", konacno);
        free(skupA);
        free(skupB);
    }

}


int main(void)
{
    srand(time(NULL));

    mjeri_vrijeme();
    //mjeri_vrijeme_2();
    //mjeri_vrijeme_3();
	return 0;
}