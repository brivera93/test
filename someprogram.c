//Bryan Rivera
//CSC 251
//11/01/2019

#include <stdlib.h>
#include <stdio.h>
#include<ctype.h>
#define SIZE 31

int promptUser(void);

int main(int argc, char* argv[])
{
	FILE* rptr;
	FILE* wptr;
	int choice;
	char arr[SIZE] = {0};
	int i;

	rptr = fopen(argv[1], "r");
	wptr = fopen(argv[2], "w");

	choice = promptUser();
	switch(choice)
	{
		case 1:
			while(!feof(rptr))
			{
				fscanf(rptr, "%s", arr);
				if(feof(rptr)) break;
				arr[0] = toupper(arr[0]);
				printf("%s\n", arr);
				fprintf(wptr, "%s\n", arr);
			}
			break;
		case 2:
			while(!feof(rptr))
			{
				fscanf(rptr, "%s", arr);
				if(feof(rptr)) break;
				for(i = 0; i < SIZE; i++)
				{
					if(arr[i] == '\0') break;
					arr[i] = tolower(arr[i]);
				}
				printf("%s\n", arr);
				fprintf(wptr, "%s\n", arr);
			}
			break;
		case 3:
			while(!feof(rptr))
			{
				fscanf(rptr, "%s", arr);
				if(feof(rptr)) break;
				for(i = 0; i < SIZE; i++)
				{
					if(arr[i] == '\0') break;
					arr[i] = toupper(arr[i]);
				}
				printf("%s\n", arr);
				fprintf(wptr, "%s\n", arr);
			}
			break;
		case 4:
			while(!feof(rptr))
			{
				fscanf(rptr, "%s", arr);
				if(feof(rptr)) break;
				for(i = 0; i < 10; i++)
				{
					printf("#%d %s\n", (i + 1), arr);
					fprintf(wptr, "#%d %s\n", (i + 1), arr);
				}
			}
			break;
		default:
			puts("Invalid input");
			break;
	}
	puts("End of program");
	fclose(rptr);
	fclose(wptr);

	return EXIT_SUCCESS;
}

int promptUser(void)
{
	int choice;

	puts("Choose an option below to modify your wordlist");
	puts("1. Change the first letter to a capital letter");
	puts("2. Make each word lowercase");
	puts("3. Make each word uppercase");
	puts("4. Duplicate each word 10 times and display the word with its duplicate# after it");
	scanf("%d", &choice);

	return choice;
}

