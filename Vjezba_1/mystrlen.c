#include<stdio.h>
#include<string.h>

int mystrlen(char* pstr)
{
	int i = 0;
	while(pstr[i] != '\0')
    {
        i++;
    }
	return i;
}

int main(void)
{
	char string[] = "This is a test";

	printf("Duzina my_strlen = %d\n", mystrlen(string));
	printf("Duzina strlen = %d\n", strlen(string));
	return 0;
}
