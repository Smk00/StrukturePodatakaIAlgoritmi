#include<stdio.h>
#include<stdlib.h>


int* podniz(int* niz, int start, int stop)
{

	int i,j;

	int* niz_2 = (int*)malloc((stop-start)*sizeof(int));

		
	for (i = start, j =0 ; i < stop; i++, j++)
	{
		niz_2[j] = niz[i];
	}

	return niz_2;

}

void print_niz(int* niz, int duljina)
{
	int i;
	for (i = 0; i < duljina; i++)
	{
		printf("niz[%d] = %d\n", i, niz[i]);
	}
}

int main(void)
{
	int niz[10] = {0,1,2,3,4,5,6,7,8,9};
	int start = 3;
	int stop = 7;

	int* rez = podniz(niz, start, stop);

	print_niz(rez,stop-start);
	free(rez);

	return 0;
}



//int* podniz(int* niz, int start, int stop) – 
//vraća novi niz koji je kopija dijela niza od indeksa start do indeksa stop.