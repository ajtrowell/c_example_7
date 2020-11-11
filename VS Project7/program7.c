#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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
void populate(float a[][50]);

char displayMenuAndReturnOption(struct MenuOption menuArray[]);
int executeMenuOption(struct MenuOption menuArray[], char employeeArray[][50], char menuOptChar);

void menu_addEmployee(float a[][50]);
void menu_display(float a[][50]);
void menu_totalPayroll(float a[][50]);
void menu_deleteEmployee(float a[][50]);
void menu_debugDisplay(float a[][50]);


// Structure definition to streamline menu creation
struct MenuOption {
    char button;
    char message[100];
    void(*optionFunction)(float[]); // employee array
};

// Main Function
int main (void)
{
    int continueProgram = 1;
    int employeeIndex=0, employeeNumber=0;
    char menuOpt=' ';
    float employeeArray[4][50]={0};

    // Initialize an array of MenuOption structures to build the menu.
    // The third field fun_menu_option is how we will set which function 
    // will get called when an option is selected.
    struct MenuOption menuOptionArray[20] = { // DEBUG: temporarily set size to 20
        {'a',"add employee info",&menu_addEmployee},
        {'d',"display employee info",&menu_display},
        {'t',"to display total payroll",&menu_totalPayroll},
        {'s',"display all employee info",&record},
        {'c',"display total number of employees",&numEmployees},
        {'f',"delete employee",&menu_deleteEmployee},
        {'1',"",&menu_debugDisplay}, // Hidden option, not listed on menu
        {'q',"",&populate}, // Hidden option, not listed on menu
        {'z',"exit",NULL},
        {NULL,NULL,NULL} // Null end of array indicator
    };

    // Menu loop
    do
    {
        menuOpt = displayMenuAndReturnOption(menuOptionArray);
        continueProgram = executeMenuOption(menuOptionArray, employeeArray, menuOpt);
    } while(continueProgram ==1);

    return 0;
} // end of main()


// Display menu and return option selection character
char displayMenuAndReturnOption(struct MenuOption menuArray[]) {
    char menuOpt = NULL;
    char key;     // character array, though I just wanted a character at first.
    char *message; // character array
    int menuIndex = 0;
    // Print until NULL button is found
    while ( menuArray[menuIndex].button != NULL) {
        if (menuArray[menuIndex].message[0] != NULL) {
            key =  menuArray[menuIndex].button;
            message = menuArray[menuIndex].message;
            printf("Select %c or %c to %s\n",toupper(key),tolower(key), message);
        }
        menuIndex++;
    }
    scanf(" %c", &menuOpt);
    return tolower(menuOpt);
}

// Given menu option selection character, execute appropriate function if defined, 
// give message if option not defined.
// return 1 if program should continue executing, 0 if it should halt.
int executeMenuOption(struct MenuOption menuArray[], char employeeArray[][50], char menuOptChar) {
    int continueProgram = 1;
    int optionIndex = 0;
    while (1) {
        if (menuArray[optionIndex].button == NULL) {
            printf("Please enter valid selection\n");
            break;
        }
        else if (tolower(menuOptChar) == tolower(menuArray[optionIndex].button)) {
            //Found matching menuOption.  Execute Accordingly:
            if (menuArray[optionIndex].optionFunction == NULL) {
                continueProgram = 0;
                break;
            }
            else {
                // Run menu option function
                menuArray[optionIndex].optionFunction(employeeArray);
                break;
            }
        }
        // keep searching for matching menu option until we hit button == NULL
        optionIndex++;
    }
    return continueProgram;
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
            continue;
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
    float sum =0;
    for(int j=0; j<50; j++)
    {
        sum = sum + (cat[1][j]*cat[2][j]-cat[1][j]*cat[2][j]*(cat[3][j])/100);
    }
    return sum;
}

// Print one record by array index
void printFormattedRecord(float employeeArray[][50], int i) {
    printf("Employee number                          : %8.0f\n",employeeArray[0][i]);
    printf("Hours worked                             : %8.2f\n",employeeArray[1][i]);
    printf("Employee pay rate                        : %8.2f\n",employeeArray[2][i]);
    printf("Total earned                             : %8.2f\n",employeeArray[1][i]*employeeArray[2][i]);
    printf("Tax deduction of %6.2f%% for a total of  : %8.2f\n",employeeArray[3][i],employeeArray[1][i]*employeeArray[2][i]*(employeeArray[3][i])/100);
    printf("Pay check amount                         : %8.2f\n",employeeArray[1][i]*employeeArray[2][i]-employeeArray[1][i]*employeeArray[2][i]*(employeeArray[3][i])/100);
    printf("---------------------------------------------------\n");
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
            continue;
        printFormattedRecord(cat, j);
    }

}

// Populate 50 fake employees to aid testing
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
        printFormattedRecord(a, iEmployee);
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
