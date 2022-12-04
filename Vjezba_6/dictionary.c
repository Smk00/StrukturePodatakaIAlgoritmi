#define _CRT_SECURE_NO_WARNINGS
#include "dictionary.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

Dictionary create()
{
	Dictionary head = (Dictionary)malloc(sizeof(Word));
	head->word = "";
	head->count = 0;
	head->next = NULL;
	return head;
}

void add(Dictionary dict, char* str)
{
	Dictionary tmp = dict;

	for (tmp; tmp != NULL; tmp = tmp->next)
	{
		if (tmp->next == NULL)
		{
			Dictionary novi = (Dictionary)malloc(sizeof(Word));
			char* ric = (char*)malloc((strlen(str) + 1) * sizeof(char));
			novi->word = ric;
			strcpy(novi->word, str);
			novi->count = 1;
			novi->next = NULL;
			tmp->next = novi;
			return;
		}
		else if (strcmp(tmp->next->word, str) == 0)
		{
			tmp->next->count++;
			return;
		}
		else if (strcmp(tmp->next->word, str) > 0)
		{
			Dictionary novi = (Dictionary)malloc(sizeof(Word));
			char* ric = (char*)malloc((strlen(str) + 1) * sizeof(char));
			novi->word = ric;
			strcpy(novi->word, str);
			novi->count = 1;

			novi->next = tmp->next;
			tmp->next = novi;
			return;
		}
		//else
		//{
		//	tmp = tmp->next;
		//}

	}


}

void print(Dictionary dict)
{
	Dictionary tmp = dict->next;

	for (tmp; tmp != NULL; tmp = tmp->next)
	{
		printf("Ric    %s    Broj ponavljanja    %d\n", tmp->word, tmp->count);
	}
}

void destroy(Dictionary dict)
{
	Dictionary tmp = dict;
	dict = dict->next;
	free(tmp);

	while (dict)
	{
		tmp = dict;
		free(tmp->word);
		dict = dict->next;
		free(tmp);
	}

}

int filter(Word* w)
{
	if ((w->count >= 5 && w->count <= 10) && (strlen(w->word) > 3))
	{
		return 1;
	}
	return 0;
}

Dictionary filterDictionary(Dictionary indict, int (*filter)(Word* w))
{
	Dictionary tmp = indict;
	Dictionary dlt_tmp;
	int flag = 0;

	while (tmp)
	{
		if (tmp->next)
		{
			flag = filter(tmp->next);

		}
		else
		{
			return indict;
		}

		if (flag)
		{
			tmp = tmp->next;
		}
		else
		{
			dlt_tmp = tmp->next;
			tmp->next = tmp->next->next;
			free(dlt_tmp->word);
			free(dlt_tmp);
		}
	}
	return indict;
}