#include<stdio.h>
#include<string.h>

char* reverse(char* strSou, char* strDest)
{
	int i = 0, j = 0;

	while (strSou[i] != '\0')
	{
		i++;
	}
	i--;

	while (i >= 0)
	{
		strDest[j] = strSou[i];
		j++;
		i--;
	}
	strDest[j] = '\0';

	return strDest;
}

int main(void)
{
	char str1[50] = "ovan";
	char str2[50];

	printf("%s\n\n", reverse(str1, str2));

	return 0;
}



//•	reverse() – prima dva stringa i kopira 
//prvi string u drugi string naopako(funkcija ne postoji u string.h)