#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"Objekt3D.h"


Objekt3D* make_3D_object(char* ime)
{
	int i;

	unsigned int br_tokuta = 0;

	FILE* fh = fopen(ime, "rb");

	fseek(fh, 80, SEEK_SET);

	fread(&br_tokuta, sizeof(unsigned int), 1, fh);

	Objekt3D* objekt = (Objekt3D*)malloc(sizeof(Objekt3D));
	Trokut* nizTrokuta = (Trokut*)malloc(br_tokuta * sizeof(Trokut));

	for (i = 0; i < br_tokuta; i++)
	{
		fread(nizTrokuta + i, 50, 1, fh);
	}

	objekt->n = br_tokuta;
	objekt->trokut = nizTrokuta;

	return objekt;
}

void show_stl_struct(Objekt3D* objekt)
{
	unsigned int i;
	unsigned int j;


	printf("Broj trokuta = %u\n", objekt->n);

	for (i = 0; i < objekt->n; i++)
	{
		printf("OVO JE [%d] TROKUT\n", i);

		printf("ni = %f    nj = %f    nk = %f\n\n\n", objekt->trokut[i].normala.ni, objekt->trokut[i].normala.nj, objekt->trokut[i].normala.nk);

		for (j = 0; j < 3; j++)
		{
			printf("x = %f    y = %f    z = %f\n", objekt->trokut[i].vrh->x, objekt->trokut[i].vrh->y, objekt->trokut[i].vrh->z);
		}
		printf("\n");
	}

}

void make_bin_stl(Objekt3D* objekt)
{
	char c = '\0';

	unsigned int i;

	FILE* fh = fopen("Objekt3D_bin.stl", "wb");

	fwrite(&c, 80, 1, fh);

	fwrite(&objekt->n, sizeof(unsigned int), 1, fh);

	for (i = 0; i < objekt->n; i++)
	{
		fwrite(objekt->trokut + i, 50, 1, fh);

	}

}

void make_txt_stl(Objekt3D* objekt)
{
	unsigned int i, j;
	FILE* fh = fopen("Objekt3D_txt.stl", "w");

	fprintf(fh, "%s\n", "solid This_is_a_copy");
	for (i = 0; i < objekt->n; i++)
	{
		fprintf(fh, "  %s %f %f %f\n", "facet normal", objekt->trokut[i].normala.ni, objekt->trokut[i].normala.nj, objekt->trokut[i].normala.nk);
		fprintf(fh, "    %s\n", "outer loop");
		for (j = 0; j < 3; j++)
		{
			fprintf(fh, "      %s %f %f %f\n", "vertex", objekt->trokut[i].vrh[j].x, objekt->trokut[i].vrh[j].y, objekt->trokut[i].vrh[j].z);
		}
		fprintf(fh, "    %s\n", "endloop");
		fprintf(fh, "  %s\n", "endfacet");
	}

	fprintf(fh,"%s","endsolid");


}

void delete_stl(Objekt3D* objekt)

{
	free(objekt->trokut);
	free(objekt);
}