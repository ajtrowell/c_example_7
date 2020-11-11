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
int numEmployees (float cat[][50]);
void wipe (float cat[][50], int n);
void Delete (float cat[][50],int n, int x);
float paycheck (float cat[][50],int n, int mouse);
void record (float cat[][50]);
char menu (void);
void populate(float a[][50]);
void printfp(char text[], int padLength);
void menu_addEmployee(float a[][50]);
void menu_display(float a[][50]);
void menu_totalPayroll(float a[][50]);
void menu_deleteEmployee(float a[][50]);
void menu_debugDisplay(float a[][50]);

int main (void)
{
int exitCmd = 1;
int employeeIndex=0, employeeNumber=0;
char menuOpt=' ';
float a[4][50]={0};


struct MenuOption {
    char key[1];
    char message[100];
    void(*fun_menu_option)(float[]); // employee array
};
struct MenuOption menuOptionArray[] = {
    {'a',"add employee info\n",&menu_addEmployee},
    {'d',"display employee info\n",&menu_display},
    {'t',"to display total payroll\n",&menu_totalPayroll},
    {'s',"display all employee info\n",&record},
    {'c',"display total number of employees\n",&numEmployees},
    {'f',"delete employee\n",&menu_deleteEmployee},
    {'1',NULL,&menu_debugDisplay}, // Hidden option, not listed on menu
    {'q',NULL,&populate}, // Hidden option, not listed on menu
    {'z',"exit\n",NULL},
    {NULL,NULL,NULL} // Null end of array indicator
};


do
{
    menuOpt = tolower(menu());
    switch (menuOpt)
    {
        case 'a': // Add
            menu_addEmployee(a);
        break;
        case 'd': // Display
            menu_display(a);
        break;
        case 't': // Show total payroll
            menu_totalPayroll(a);
        break;
        case 's':
            record(a);
        break;
        case 'c':
            numEmployees(a);
        break;
        case 'f':
            menu_deleteEmployee(a);
        break;
        case 'z':
            printf("Better cut those checks have a nice day!");
            exitCmd = 0;
        break;
        case '1':
            menu_debugDisplay(a);
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
int numEmployees (float cat[][50])
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
// cat is employeeArray
// n and mouse are unused
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
void record (float cat[][50])
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

void populate(float a[][50]) {
    for (int i = 0; i < 50; i++) {
        a[0][i] = i + 1; // Employee number
        a[1][i] = 30.0 + i/2.0; // Employee hours worked
        a[2][i] = 8.0 + i; // Employee hourly wage
        a[3][i] = a[2][i]*(0.04 + (float) i / 100.0); // Employee tax deduction
    }
}




void menu_addEmployee(float a[][50]) {
    int employeeIndex = (possible(a,4));
    if (employeeIndex <50)
    {	
        add(a,4,employeeIndex);
        for (int i=0;i<4;i++)
        {
            for (int j = 0; j < 50; j++) {
                printf("%2.2f  ", a[i][j]);
            }
            printf("\n\n");
        }
    } else {
        printf("No more employees can be entered");
    }
}


void menu_display(float a[][50]) {
    int employeeNum;
    printf("Please enter employee number:");
    scanf("%d", &employeeNum);
    int iEmployee = search(a,4,employeeNum);
    if (iEmployee != 1000)
    {
        printf("Employee number                        : %.2f\n",a[0][iEmployee]);
        printf("Hours worked                           : %.2f\n",a[1][iEmployee]);
        printf("Employee pay rate                      : %.2f\n",a[2][iEmployee]);
        printf("Total earned                           : %.2f\n",a[1][iEmployee]*a[2][iEmployee]);
        printf("Tax deduction of %.2f%% for a total of : %.2f\n",a[3][iEmployee],a[1][iEmployee]*a[2][iEmployee]*(a[3][iEmployee])/100);
        printf("Pay check amount                      : %.2f\n",a[1][iEmployee]*a[2][iEmployee]-a[1][iEmployee]*a[2][iEmployee]*(a[3][iEmployee])/100);
    }else
        printf("No such employee");
}


void menu_totalPayroll(float a[][50]) {
    printf("the total payroll is %.2f\n", paycheck(a,4,0));
}

void menu_deleteEmployee(float a[][50]) {
    int employeeNumber = 0; 
    int employeeIndex = 0;
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
}

void menu_debugDisplay(float a[][50]) {
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 50; j++) {
            printf("%6.2f  ",a[i][j]);
        }
        printf("\n\n");
    }
}
