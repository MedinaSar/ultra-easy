#include <stdio.h>
#include <string.h>
#define SIZE 50

void newUsername();
void newPassword();
void newAccount();
int checkUser();
int checkPass();
void checkUserAndPass();
void writeORread();
void writing();
void enteringDate();
void dateDay();
void dateMonth();
void dateYear();
void reading();

void main()
{
	char choice;

	printf("Is it your first time here? (Y/N)\n");
	scanf("%c", &choice);

	if (choice == 'Y' || choice == 'y')
	{
		system("cls");
		newAccount();
	}

	else if (choice == 'N' || choice == 'n')
	{
		system("cls");
		checkUserAndPass();
	}
	system("pause");
}

void newUsername()
{
	char username[SIZE];
	FILE *usernamef = fopen("D://username.txt", "w");

	printf("Enter your username: ");
	scanf("%s", &username);

	fprintf(usernamef, "%s", username);
	fclose(usernamef);
}
void newPassword()
{
	char password[SIZE];
	FILE *passwordf = fopen("D://password.txt", "w");

	printf("Enter your password: ");
	scanf("%s", &password);

	fprintf(passwordf, "%s", password);
	fclose(passwordf);
}
void newAccount()
{
	newUsername();
	newPassword();

	printf("\n\nCongratulations! You just created an account!\n\nFeel free to write in your diary whatever pops-up in your mind:\nit won't tell anyone! ;)\n\n");
	_sleep(6500);
	system("cls");
	writeORread();
}

int checkUser()
{
	char username[SIZE], checkUser[SIZE];
	FILE *usernamef = fopen("D://username.txt", "r");

	printf("Enter your username: ");
	scanf("%s", &username);
	fscanf(usernamef, "%s", &checkUser);
	fclose(usernamef);

	if (strcmp(username, checkUser) == 0)
		return 0;
	else
		return 1;
}
int checkPass()
{
	char password[SIZE], checkPass[SIZE];
	FILE *passwordf = fopen("D://password.txt", "r");

	printf("Enter your password: ");
	scanf("%s", &password);
	fscanf(passwordf, "%s", &checkPass);
	fclose(passwordf);

	if (strcmp(password, checkPass) == 0)
		return 0;
	else
		return 1;
}
void checkUserAndPass()
{
	while (checkUser() != 0 || checkPass() != 0)
			printf("\nYour username/password is incorrect. Please check them.\n\n");
	system("cls");
	writeORread();
}

void writeORread()
{
	int choice;

	printf("\nHello, there! Welcome to your diary! Would you like to:\n\n1.write in your diary\n2.read from it?\n3.Exit\n\n");
	scanf("%d", &choice);
	system("cls");

	switch (choice)
	{
	case 1: writing();
		writeORread();
	case 2: reading();
		writeORread();
	case 3: break;
	}
}
void dateDay()
{
	int day;
	FILE *diary = fopen("D:\\diary.txt", "a+");
	while (1)
	{
		printf("Day: ");
		scanf("%d", &day);
		if (day < 1 || day > 31)
			printf("\nWrong input. Try again.\n\n");
		else
			break;
	}
	fprintf(diary,"%d.", day);
	fclose(diary);
}
void dateMonth()
{
	int month;
	FILE *diary= fopen("D:\\diary.txt", "a+");
	while (1)
	{
		printf("Month: ");
		scanf("%d", &month);
		if (month < 1 || month > 31)
			printf("\nWrong input. Try again.\n\n");
		else
			break;
	}
	fprintf(diary,"%d.", month);
	fclose(diary);
}
void dateYear()
{
	int year;
	FILE *diary = fopen("D:\\diary.txt", "a+");
	while (1)
	{
		printf("Year: ");
		scanf("%d", &year);
		if (year < 2015 || year > 2100)
			printf("\nWrong input. Try again.\n\n");
		else
			break;
	}
	fprintf(diary, "%d.", year);
	fclose(diary);
}
void enteringDate()
{
	dateDay();
	dateMonth();
	dateYear();
}
void writing()
{
	char content;
	FILE *diary = fopen("D:\\diary.txt", "a+");	

	enteringDate();
	printf("\n\nHow was your day?\n");
	while (1)
	{
		scanf("%c", &content);
		if (content == '0')		//Press 0 and enter to finish writing.
			break;
		fprintf(diary, "%c", content);
	}
	fclose(diary);
	printf("\nSeems like a great day!\n\n");
	_sleep(2500);
	system("cls");
} 
void reading()
{
	char content;
	FILE *diary = fopen("D:\\diary.txt", "r");
	fseek(diary, 0, SEEK_SET);

	while (!feof(diary))
	{
		fscanf(diary, "%c", &content);
		printf("%c", content);
	}

	fclose(diary);
	system("pause");
	system("cls");
}