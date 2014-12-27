#include <stdio.h>
#include <string.h>
#define SIZE 10
void newUsernameAndPass();
void checkUserAndPass();
void writeORread();
void writing();
void reading();

void main()
{
	char choice;

	printf("Is it your first time here? (Y/N)\n");
	scanf("%c", &choice);

	if (choice == 'Y')
		newUsernameAndPass();

	else if (choice == 'N')
		checkUserAndPass();

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
		writing();
	else if (choice == 2)
		reading();
}
void newUsernameAndPass()
{
	char *username[SIZE];
	FILE *usernamef = fopen("D://username.txt", "w");

	printf("Enter your username (up to 10 characteres): ");
	scanf("%s", &username);

	fprintf(usernamef, "%s", username);
	fclose(usernamef);

	char password[SIZE];

	FILE *passwordf = fopen("D://password.txt", "w");

	printf("\nEnter your password (up to 10 characteres): ");
	scanf("%s", &password);

	fprintf(passwordf, "%s", password);
	fclose(passwordf);
}
void checkUserAndPass()
{
	char usernam[SIZE], password[SIZE], checku[SIZE], checkp[SIZE];

	FILE *username = fopen("D://username.txt", "r");
	FILE *pasword = fopen("D://password.txt", "r");

	printf("\nEnter your username:");
	scanf("%s", &usernam);

	printf("\nEnter your password:");
	scanf("%s", &password);

	fscanf(username, "%s", &checku);
	fclose(username);

	fscanf(pasword, "%s", &checkp);
	fclose(pasword);

	if (strcmp(usernam, checku) == 0 && strcmp(password, checkp) == 0) 
	{
		printf("\n\n\t\tHello, %s!\n\n", usernam);
	}

	else //keep asking for the user and pass until it's correct!
		printf("\n\nYour username or password is incorrect.Please check them again.\n\n");

void enteringDate()
{
	FILE *diary;
	diary= fopen("D:\\diary.txt", "a+");

	int day, month, year;

	printf("Day: ");
	scanf("%d", &day);

	printf("\nMonth: ");
	scanf("%d", &month);

	printf("\nYear: ");
	scanf("%d", &year);

	fprintf(diary, "\n\n%d.%d.%d.\n", day, month, year);

	fclose(diary);
}
void writing()
{
	FILE *diary = fopen("D:\\diary.txt", "a+");	

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

	_sleep(3000);
	system("cls");
} 
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
	
	/*_sleep(5000);
	system("cls");*/
}