#include<stdio.h>
#include<string.h>

char* mystrstr(char* str, const char* substr)
{
	int i, j = 0;
	int substr_lenght = strlen(substr);
	int counter = 0;
	char* ret = str;

	for (i = 0; str[i] >= '\0'; i++)
	{
		if (substr_lenght == counter)
		{
			return ret + i - j;
		}
		else if (str[i] == substr[j])
		{
			j++;
			counter++;
		}
		else
		{
			i = i - j;
			j = 0;
			counter = 0;
		}
	}
		return NULL;
}

int main(void)
{
	char str1[50] = "abaaaaabaa";
	char str2[50] = "aaab";

	printf("%s\n\n", mystrstr(str1, str2));

	return 0;
}


//•	mystrstr() – funkcija vraća pokazivač(unutar prvog stringa) 
//koji pokazuje na prvo pojavljivanje drugog stringa.Ako ga ne pronađe, funkcija vraća NULL.