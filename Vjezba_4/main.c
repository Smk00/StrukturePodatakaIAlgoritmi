#include<stdio.h>
#include"Objekt3D.h"


int main(void)
{
	char ime[] = "C:\\Users\\simek\\OneDrive\\Desktop\\Vjezba_2\\Luka_0\\Debug\\primjerbin.stl";

	char imeTxt[] = "C:\\Users\\Šime\\Desktop\\Luka_0\\Debug\\primjertxt.stl";

	char test[] = "C:\\Users\\Šime\\Desktop\\Luka_0\\Debug\\test.txt";

	int i, j;

	Objekt3D* novi = make_3D_object(ime);
	//make_bin_stl(novi);
	make_txt_stl(novi);

	//show_stl_struct(novi);

	delete_stl(novi);

	return 0;
}