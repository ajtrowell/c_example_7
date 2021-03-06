#include <stdio.h>
#include <stdlib.h>
/*
Paul Ruth
program 7
10/27/2020
*/

#pragma warning(disable : 4996)

int possible(float cat[][50], int n);
void add(float cat[][50], int m, int n);
int search(float cat[][50],int n, int mouse);
int Numemployees (float cat[][50], int n);
void wipe (float cat[][50], int n);
void Delete (float cat[][50],int n, int x);
float paycheck (float cat[][50],int n, int mouse);
void record (float cat[][50],int n, int mouse);
char menu (void);
void populate(float a[][50]);
void printfp(char text[], int padLength);

int main (void)
{
int N=0, M=0, i=0, j=0, k=0, mouse = 0, x = 0, exitCmd = 1;
int employeeIndex=0, employeeNumber=0;
char menuOpt=' ';
float sum = 0;
float a[4][50]={0};


do
{

    menuOpt = tolower(menu());

    switch (menuOpt)
    {
        case 'a': // Add
            employeeIndex = (possible(a,4));
            if (employeeIndex <50)
            {	
                add(a,4,employeeIndex);
                for (i=0;i<4;i++)
                {
                    for (j = 0; j < 50; j++) {
                        printf("%2.2f  ", a[i][j]);
                    }
                    printf("\n\n");
                }
            } else {
                printf("No more employees can be entered");
            }
            break;
        case 'd': // Display
            printf("Please enter employee number:");
            scanf("%d", &mouse);

            mouse = search(a,4,mouse);

            if (mouse != 1000)
            {
                printf("Employee number                        : %.2f\n",a[0][mouse]);
                printf("Hours worked                           : %.2f\n",a[1][mouse]);
                printf("Employee pay rate                      : %.2f\n",a[2][mouse]);
                printf("Total earned                           : %.2f\n",a[1][mouse]*a[2][mouse]);
                printf("Tax deduction of %.2f%% for a total of : %.2f\n",a[3][mouse],a[1][mouse]*a[2][mouse]*(a[3][mouse])/100);
                printf("Pay check amount                      : %.2f\n",a[1][mouse]*a[2][mouse]-a[1][mouse]*a[2][mouse]*(a[3][mouse])/100);
            }else
                printf("No such employee");
        break;
        case 't':
            printf("the total payroll is %.2f\n", paycheck(a,4,mouse));
        break;
        case 's':
            record(a,4,mouse);
        break;
        case 'c':
            Numemployees(a,4);
        break;
        case 'f':
            printf("Please enter employee to delete:");
            scanf("%d",&employeeNumber);
            employeeIndex = search(a,4,employeeNumber);

            if (employeeIndex < 50)
            {
                Delete(a,4,employeeIndex);
            }else
            {
                printf("No such employee.");
            }
        break;

        case 'z':
            printf("Better cut those checks have a nice day!");
            exitCmd = 0;
        break;
        case '1':
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 50; j++) {
                    printf("%6.2f  ",a[i][j]);
                }
                    printf("\n\n");
            }
            break;
        case 'q': // Hidden option, fill in the employee table
            populate(a);
        break;
    default:
        printf("Please enter valid selection\n");
        }

}while(exitCmd ==1);


return 0;
}
char menu (void)
{
char menuOpt;

    printf("Select A or a to add employee info\n");
    printf("Select D or d to display employee info\n");
    printf("Select T or t to display total payroll\n");
    printf("Select S or s to display all employee info\n");
    printf("Select C or c to display total number of employees\n");
    printf("Select F or f to delete employee\n");
    printf("Select Z or z to exit\n");
    scanf(" %c", &menuOpt);

return menuOpt;
}

int possible(float cat[][50], int n)
{
int j=0;
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

// Search
// function returns the index where employee number stored
// in mouse is located.
// Returns 1000 if there is no such employee
int search(float cat[][50],int n, int mouse)
{
int employeeNumber = mouse; // input employeeNumber
int employeeIndex = 1000; // output employeeIndex
int j=0;
    for (j = 0; j < 50; j++)
        {
            if ((int)cat[0][j] ==  employeeNumber)
            {
                employeeIndex = j;
                break;
            }
        }
    return employeeIndex;
}
int Numemployees (float cat[][50], int n)
{
    int j=0, k=0;
    for(j=0; j<50; j++)
    {
        if (cat[0][j] == 0)
            break;
        else
            k++;
    }
    printf("The number of employees is: %d\n", k);
}

// Erase 
void wipe (float cat[][50], int n)
{
    for (int iRow = 0; iRow < 4; iRow++) {
        for (int iEmp = 0; iEmp < 50; iEmp++) {
            cat[iRow][iEmp] = 0;
        }
    }
}
//// function deletes the employee record (by setting all the values
//in that column to zero) present in the column index passed to it.
// x= employee index n is unused
void Delete(float cat[][50], int n, int x)
{
    int employeeIndex = x;
    int i = 0;
    for (i = 0; i < 4; i++)
    {
        cat[0][employeeIndex] = 0;
    }
}
float paycheck (float cat[][50],int n, int mouse)
{
    int j=0;
    float sum =0;
for(j=0; j<50; j++)
            {
                sum = sum + (cat[1][j]*cat[2][j]-cat[1][j]*cat[2][j]*(cat[3][j])/100);
            }
    return sum;
}
// Show all records
// cat is input array
// n and mouse do nothing
void record (float cat[][50],int n, int mouse)
{
int j=0;
    for (j=0;j<50;j++)
        {
            if((int)cat[0][j] == 0)
                break;
                    printf("Employee number                          : %8.0f\n",cat[0][j]);
                    printf("Hours worked                             : %8.2f\n",cat[1][j]);
                    printf("Employee pay rate                        : %8.2f\n",cat[2][j]);
                    printf("Total earned                             : %8.2f\n",cat[1][j]*cat[2][j]);
                    printf("Tax deduction of %6.2f%% for a total of  : %8.2f\n",cat[3][j],cat[1][j]*cat[2][j]*(cat[3][j])/100);
                    printf("Pay check amount                         : %8.2f\n",cat[1][j]*cat[2][j]-cat[1][j]*cat[2][j]*(cat[3][j])/100);
                    printf("---------------------------------------------------\n");
        }

}
//http://www.cplusplus.com/reference/cstdio/sscanf/
//https://stackoverflow.com/questions/10820377/c-format-char-array-like-printf
void printfp(char text[], int padLength) {
    printf(text);
    int len = strlen(text);
    while (len < padLength) {
        printf(" ");
        len++;
    }
    printf("string length:  %d", len);

}

void populate(float a[][50]) {
    for (int i = 0; i < 50; i++) {
        a[0][i] = i + 1; // Employee number
        a[1][i] = 30.0 + i/2.0; // Employee hours worked
        a[2][i] = 8.0 + i; // Employee hourly wage
        a[3][i] = a[2][i]*(0.04 + (float) i / 100.0); // Employee tax deduction
    }
}










