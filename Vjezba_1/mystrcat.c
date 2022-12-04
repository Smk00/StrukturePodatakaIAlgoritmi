#include<stdio.h>
#include<string.h>

char* mystrcat(char* strDest, const char* strSou)
{
	int i = 0;
	int destiontion_lenght = strlen(strDest);
	
	while (strSou[i] != '\0')
	{
		strDest[destiontion_lenght] = strSou[i];
		i++;
		destiontion_lenght++;
	}

	return strDest;

}


int main(void)
{
	char str1[50] = "Hello";
	char str2[50] = "World";

	//printf("%d\n\n", strlen(str2));

	mystrcat(str2, str1);

	printf("%s\n\n", str2);

	return 0;
}



//•	mystrcat() – funkcija „dodaje“ drugi string na kraj prvog stringa.