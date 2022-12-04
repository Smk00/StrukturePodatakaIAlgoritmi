#ifndef OBJEKT3D_H
#define OBJEKT3D_H

typedef struct Vrh {

	float x;
	float y;
	float z;
}Vrh;

typedef struct Normala {
	float ni;
	float nj;
	float nk;
}Normala;

typedef struct Trokut {
	Normala normala;
	Vrh vrh[3];
	unsigned short boja;
}Trokut;

typedef struct Objekt3D {
	unsigned int n;
	Trokut* trokut;
}Objekt3D;

Objekt3D* make_3D_object(char* ime);
void show_stl_struct(Objekt3D* objekt);
void make_bin_stl(Objekt3D* objekt);
void make_txt_stl(Objekt3D* objekt);
void delete_stl(Objekt3D* objekt);


#endif // !OBJEKT3D_H
