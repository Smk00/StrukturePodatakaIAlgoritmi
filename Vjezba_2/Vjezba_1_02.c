#include<stdio.h>
#include<stdlib.h>


int* filtriranje(int* niz, int n, int th, int* nth)
{
    *nth = 0;
	int i, j = 0;
	for (i = 0; i < n; i++)
	{
		if (niz[i] < th)
		{
			(*nth)++;
		}
	}

	int* sub_arr = (int*)malloc( (*nth) * sizeof(int));

	for (i = 0; i < n; i++)
	{
		if (niz[i] < th)
		{
			sub_arr[j] = niz[i];
			j++;
		}
	}

	return sub_arr;
}

void print_niz(int* niz, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("niz[%d] = %d\n", i, niz[i]);
	}
}

int main(void)
{
	int th = 5, i, n = 10, nth = -888;

	int* niz = (int*)malloc(n * sizeof(int));
	int* rez;

	for (i = 0; i < n; i++)
	{
		niz[i] = i;
	}

	rez = filtriranje(niz, n, th, &nth);
	print_niz(rez, nth);
	free(niz);
	free(rez);



	return 0;
}


//int* filtriraj(int* niz, int n, int th, int* nth) – vraća novi niz koji sadrži brojeve iz originalnog niza
//koji su manji od th.Originalni niz ima dužinu n.
//Dužinu novog niza sa brojevima koji su prošli filter treba spremiti u nth.
