#include <stdio.h>
/*
Paul Ruth
program 7
10/27/2020
*/

#pragma warning(disable : 4996)

int possible(float cat[][50], int n);
void add(float cat[][50], int m, int n);
int search(float cat[][50], int n, int mouse);
int count(float cat[][50], int n);
void wipe(float cat[][50], int n);
void Delete(float cat[][50], int n, int x);
float paycheck(float cat[][50], int n, int mouse);
float record(float cat[][50], int n, int mouse);
char menu(void);

int main(void)
{
	int N = 0, M = 0, i = 0, j = 0, k = 0, mouse = 0, x = 0, exitCmd = 1;
	char menuOpt = ' ';
	float sum = 0;
	float a[4][50] = { 0 };


	do
	{

		menuOpt = menu();

		switch (menuOpt)
		{
		case 'A': case 'a':
			mouse = (possible(a, 4));
			if (mouse < 50)
			{
				add(a, 4, mouse);
				for (i = 0; i < 4; i++)
				{
					for (j = 0; j < 50; j++)
						printf("%2.2f  ", a[i][j]);
					printf("\n\n");
				}
			}
			else
				printf("No more employees can be entered");

			break;

		case 'D': case 'd':
			printf("Please enter employee number:");
			scanf("%d", &k);

			for (j = 0; j < N; j++)
				if ((int)a[0][j] == k)
					break;
			if ((int)a[0][j] == k)
			{
				printf("Employee number                        : %.2f\n", a[0][j]);
				printf("Hours worked                           : %.2f\n", a[1][j]);
				printf("Employee pay rate                      : %.2f\n", a[2][j]);
				printf("Total earned                           : %.2f\n", a[1][j] * a[2][j]);
				printf("Tax deduction of %.2f%% for a total of : %.2f\n", a[3][j], a[1][j] * a[2][j] * (a[3][j]) / 100);
				printf("Pay check ammount                      : %.2f\n", a[1][j] * a[2][j] - a[1][j] * a[2][j] * (a[3][j]) / 100);

			}
			else printf("No such employee\n");

			break;


		case 'T': case 't':
			for (j = 0; j < N; j++)
			{
				sum = sum + (a[1][j] * a[2][j] - a[1][j] * a[2][j] * (a[3][j]) / 100);
			}
			printf("The total payroll is: %.2f  \n", sum);

			break;

		case 'S': case 's':

			for (j = 0; j < N; j++)
			{
				if ((int)a[0][j] == 0)
					break;
				printf("Employee number                        : %.2f\n", a[0][j]);
				printf("Hours worked                           : %.2f\n", a[1][j]);
				printf("Employee pay rate                      : %.2f\n", a[2][j]);
				printf("Total earned                           : %.2f\n", a[1][j] * a[2][j]);
				printf("Tax deduction of %.2f%% for a total of : %.2f\n", a[3][j], a[1][j] * a[2][j] * (a[3][j]) / 100);
				printf("Pay check ammount                      : %.2f\n", a[1][j] * a[2][j] - a[1][j] * a[2][j] * (a[3][j]) / 100);
				printf("-------------------------------------------------\n");
			}

			break;

		case 'C': case 'c':
			k = 0;
			for (j = 0; j < N; j++)
			{
				if (a[0][j] == 0)
					break;
				k++;
			}
			printf("The number of employees is: %d\n", k);

			break;

		case 'Z': case 'z':
			printf("Better cut those checks have a nice day!");
			exitCmd = 0;
			break;
		case '1':
			for (i = 0; i < 4; i++)
			{
				for (j = 0; j < N; j++)
					printf("%d", a[i][j]);
				printf("\n\n");
			}
			break;


		default:
			printf("Please enter valid selection\n");
		}

	} while (exitCmd == 1);


	return 0;
}
char menu(void)
{
	char menuOpt;
	printf("Select A or a to add employee info\n");
	printf("Select D or d to display employee info\n");
	printf("Select T or t to display total payroll\n");
	printf("Select S or s to display all employee info\n");
	printf("Select C or c to display total number of employees\n");
	printf("Select Z or z to exit\n");
	scanf("%c", &menuOpt);

	return menuOpt;
}

int possible(float cat[][50], int n)
{
	int j = 0;
	for (j = 0; j < 50; j++)
		if ((int)cat[0][j] == 0)
			break;

	return j;

}
void add(float cat[][50], int n, int m)

{


	printf("Please enter employee number:");
	scanf("%f", &cat[0][m]);
	printf("Please enter hours employee worked:");
	scanf("%f", &cat[1][m]);
	printf("Please enter employee pay rate:");
	scanf("%f", &cat[2][m]);
	printf("Please enter employee tax deduction:");
	scanf("%f", &cat[3][m]);




}
int search(float cat[][50], int n, int mouse)
{

}
int count(float cat[][50], int n)
{

}
void wipe(float cat[][50], int n)
{

}
void Delete(float cat[][50], int n, int x)
{

}
float paycheck(float cat[][50], int n, int mouse)
{

}
float record(float cat[][50], int n, int mouse)
{

}









