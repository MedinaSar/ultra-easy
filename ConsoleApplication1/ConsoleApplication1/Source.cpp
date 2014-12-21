#include <stdio.h>
void writeORread();
void writing();
void reading();

void main()
{
	writeORread();
	system("pause");
}


void writeORread()
{
	int choice;

	printf("\nWelcome to your diary! Would you like to:\n\n1.write in your diary\n\n2.read from it?\n\n");
	scanf("%d", &choice);

	system("cls");

	if (choice == 1)
	{
		writing();
	}

	else if (choice == 2)
	{
		reading();
	}
}

void enteringDate()
{
	FILE *diary;
	diary = fopen("D:\\diary.txt", "a+");

	int day, month, year;

	printf("Day: ");
	scanf("%d", &day);

	printf("\nMonth: ");
	scanf("%d", &month);

	printf("\nYear: ");
	scanf("%d", &year);

	fprintf(diary, "\n\n%d.%d.%d.", day, month, year);
}

void writing()
{
	FILE *diary;
	diary = fopen("D:\\diary.txt", "a+");	

	enteringDate();
	printf("\n\nHow was your day?\n");

	char content;
	while (1)
	{
		scanf("%c", &content);
		if (content == '0')		//Press 0 and enter to finish writing.
			break;
		fprintf(diary, "%c", content);
	}

	fclose(diary);

	printf("\nSeems like a great day!\n\n");

} //I have some problems here, it prints me first the content and then the date. It should be obrnuto.

void reading()
{
	FILE *diary;
	char *contents;
	int fileSize = 0;

	diary = fopen("D:\\diary.txt", "rb");


	fseek(diary, 0L, SEEK_END);
	fileSize = ftell(diary);
	fseek(diary, 0L, SEEK_SET);

	contents = malloc(fileSize + 1);

	size_t size = fread(contents, 1, fileSize, diary);
	contents[size] = 0; 
	printf("%s\n", contents);

	fclose(diary);
}