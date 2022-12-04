#include<stdio.h>
#include<string.h>



char* mystrcpy(char* strDest, const char* strSou)
{
	int i = 0;

	while (strSou[i] != '\0')
	{
		strDest[i] = strSou[i];
		i++;
	}
	strDest[i] = '\0';

	return strDest;
}

int main(void)
{

	char str_1[50] = "This is a long string";
	char str_2[50] = "tHIS IS A LONGER STRING";

	mystrcpy(str_2, str_1);

	printf("%s\n\n", str_2);

	return 0;
}

//•	mystrcpy() – funkcija prima dva stringa i kopira drugi string u prvi string.