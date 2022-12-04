#include<stdio.h>
#include<string.h>

int mystrcmp(const char* str1, const char* str2)
{
	int i = 0;

	while (str1[i] != '\0')
	{
		if (str1[i] == str2[i])
			i++;
		else if (str1[i] > str2[i])
			return 1;
		else
			return -1;
	}

	if (strlen(str1) > strlen(str2))
	{
		return 1;
	}
	else if(strlen(str2) > strlen(str1))
	{
		return -1;
	}
	return 0;
}


int main(void)
{
	char str_1[50] = "apple"; //;{ 'a','b','\0', 'c' }
	char str_2[50] = "applee";//{ 'a','b','\0', 'd' }


	printf("Value returned by mystrcmp: %d", mystrcmp(str_1, str_2));

	return 0;
}

//•	mystrcmp() – funkcija prima dva stringa i uspoređuje ih.
//Funkcija vraća : broj manji od nula ako je prvi string manji od drugog stringa(po leksikografskom poretku),
//broj veći od nula ako je drugi string manji od prvog i nula ako su stringovi jednaki.