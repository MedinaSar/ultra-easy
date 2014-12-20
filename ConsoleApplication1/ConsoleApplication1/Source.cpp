#include <stdio.h>
void writing();
void reading();

void main()
{
	int n;

	printf("Would you like to:\n 1.write in your diary\n 2.read from it?\n");
	scanf("%d", &n);

	if (n == 1)
	{
		writing();
	}

	else if (n == 2)
	{
		reading();
	}

	system("pause");
}

void writing()
{
	char month, a;
	int day, year;

	FILE *diary;
	diary = fopen("D:\\diary.txt", "a+");

	printf("Day (ex.12): ");
	scanf("%d", &day);

	printf("\nMonth (ex. December): ");
	scanf(" %c", &month);

	printf("\nYear: ");
	scanf("%d", &year);

	printf("\n\nHow was your day? (Press w and enter to finish writing.)\n");

	while (1)
	{
		scanf(" %c", &a);
		if (a == 'w')
			break;
		fprintf(diary, "%c", a);
	}

	fclose(diary);

	printf("\nSeems like a great day!\n\n");

}

void reading()
{
	char a;

	FILE *diary;
	diary = fopen("D:\\diary.txt", "r");
	fscanf(diary, " %c", &a);
	printf("%c\n\n", a);

	fclose(diary);
}