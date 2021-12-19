#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
struct database
{
    char name[250], status[3], issuer[20];
    int idate[3], ddate[3];
} stud, stud1;
char x[20];
void display()
{
    FILE *fp = fopen("db1.txt", "r");
    printf("\nNAME OF THE BOOK\t\t\t\t ISSUE-DATE(IF)   STATUS(A/NA)   DUE-DATE(IF)\tISSUER\n\n");
    do
    {
        if (fgetc(fp) == EOF)
            break;
        fscanf(fp, "%[^*]s", stud.name);
        fseek(fp, 2, SEEK_CUR);
        fscanf(fp, "%d/%d/%d", &stud.idate[0], &stud.idate[1], &stud.idate[2]);
        fseek(fp, 1, SEEK_CUR);
        fscanf(fp, "%s", stud.status);
        fseek(fp, 1, SEEK_CUR);
        fscanf(fp, "%d/%d/%d", &stud.ddate[0], &stud.ddate[1], &stud.ddate[2]);
        fseek(fp, 1, SEEK_CUR);
        fscanf(fp, "%[^.]s", stud.issuer);
        fseek(fp, 1, SEEK_CUR);
        printf("%-47s\t %02d/%02d/%02d\t  %-2s\t\t %02d/%02d/%02d\t%s\n", stud.name, stud.idate[0], stud.idate[1], stud.idate[2], stud.status, stud.ddate[0], stud.ddate[1], stud.ddate[2], stud.issuer);
    } while (fgetc(fp) != EOF);
    fclose(fp);
}
void deleteline(char *book)
{
    char old[10] = "db1.txt";
    char new[10] = "temp.txt";
    FILE *fp1 = fopen("db1.txt", "r");
    FILE *fp2 = fopen("temp.txt", "w");
    if (!fp1 || !fp2)
        printf("\nError opening!\n");
    else
    {
        do
        {
            if (fgetc(fp1) == EOF)
                break;
            fscanf(fp1, "%[^*]s", stud.name);
            fseek(fp1, 2, SEEK_CUR);
            fscanf(fp1, "%d/%d/%d", &stud.idate[0], &stud.idate[1], &stud.idate[2]);
            fseek(fp1, 1, SEEK_CUR);
            fscanf(fp1, "%s", stud.status);
            fseek(fp1, 1, SEEK_CUR);
            fscanf(fp1, "%d/%d/%d", &stud.ddate[0], &stud.ddate[1], &stud.ddate[2]);
            fseek(fp1, 1, SEEK_CUR);
            fscanf(fp1, "%[^.]s", stud.issuer);
            fseek(fp1, 1, SEEK_CUR);
            if (strcmp(stud.name, stud1.name) == 0)
            {}
            else
                fprintf(fp2, " %s* %d/%d/%d %s %d/%d/%d %s.\n", stud.name, stud.idate[0], stud.idate[1], stud.idate[2], stud.status, stud.ddate[0], stud.ddate[1], stud.ddate[2], stud.issuer);
        } while (fgetc(fp1) != EOF);
        fclose(fp1);
        fclose(fp2);
        remove(old);
        rename(new, old);
    }
}
void edit(char *bname)
{
    char old[10] = "db1.txt";
    char new[10] = "temp.txt";
    FILE *fp3 = fopen("db1.txt", "r");
    FILE *fp4 = fopen("temp.txt", "w");
    if (!fp3 || !fp4)
        printf("\nError opening!\n");
    else
    {
        do
        {
            if (fgetc(fp3) == EOF)
                break;
            fscanf(fp3, "%[^*]s", stud.name);
            fseek(fp3, 2, SEEK_CUR);
            if (strcmp(stud.name, stud1.name) == 0)
            {
                fscanf(fp3, "%d/%d/%d", &stud.idate[0], &stud.idate[1], &stud.idate[2]);
                fseek(fp3, 1, SEEK_CUR);
                fscanf(fp3, "%s", stud.status);
                fseek(fp3, 1, SEEK_CUR);
                fscanf(fp3, "%d/%d/%d", &stud.ddate[0], &stud.ddate[1], &stud.ddate[2]);
                fseek(fp3, 1, SEEK_CUR);
                fscanf(fp3, "%[^.]s", stud.issuer);
                fseek(fp3, 1, SEEK_CUR);
                strcpy(x, stud.issuer); //CHECK LATER
               // printf("%s\n", stud1.issuer);
                fprintf(fp4, " %s* %d/%d/%d %s %d/%d/%d %s.\n", stud.name, stud1.idate[0], stud1.idate[1], stud1.idate[2], stud1.status, stud1.ddate[0], stud1.ddate[1], stud1.ddate[2], stud1.issuer);
            }
            else
            {
                fscanf(fp3, "%d/%d/%d", &stud.idate[0], &stud.idate[1], &stud.idate[2]);
                fseek(fp3, 1, SEEK_CUR);
                fscanf(fp3, "%s", stud.status);
                fseek(fp3, 1, SEEK_CUR);
                fscanf(fp3, "%d/%d/%d", &stud.ddate[0], &stud.ddate[1], &stud.ddate[2]);
                fseek(fp3, 1, SEEK_CUR);
                fscanf(fp3, "%[^.]s", stud.issuer);
                fseek(fp3, 1, SEEK_CUR);
                fprintf(fp4, " %s* %d/%d/%d %s %d/%d/%d %s.\n", stud.name, stud.idate[0], stud.idate[1], stud.idate[2], stud.status, stud.ddate[0], stud.ddate[1], stud.ddate[2], stud.issuer);
            }
        } while (fgetc(fp3) != EOF);
        fclose(fp3);
        fclose(fp4);
        remove(old);
        rename(new, old);
    }
}
int main()
{
    int choice, found = 0, found1 = 0;
    char av[3] = "A", nav[3] = "NA", iss[2] = "-";
    do
    {
        printf("\n***************WELCOME TO NIT DELHI'S LIBRARY!****************\n");
        printf("\n--------------------------MENU--------------------------\n");
        printf("1-DISPLAY all the records in the database-----\n");
        printf("2-ADD a book in the database------------------\n");
        printf("3-DELETE a book from the database-------------\n");
        printf("4-ISSUE a book from the library---------------\n");
        printf("5-RE-ISSUE a book-----------------------------\n");
        printf("6-RETURN a book to the library----------------\n");
        printf("7-SEARCH a book-------------------------------\n");
        printf("8-FINE CALCULATION incase of late return------\n");
        printf("0-EXIT----------------------------------------\n\n");
        printf("ENTER YOUR CHOICE:- ");
        scanf("%d", &choice);

        if (choice == 1) //display CHECK
        {
            printf("\nBelow is the detailed record of the books: \n");
            display();
        }
        else if (choice == 2) //add CHECK
        {
            FILE *fp = fopen("db1.txt", "a+");
            printf("\nEnter the book name(IN CAPITALS): ");
            scanf(" %[^\n]s", stud.name);
            strcpy(stud.status, av);
            strcpy(stud.issuer, iss);
            stud.idate[0] = 0, stud.idate[1] = 0, stud.idate[2] = 0;
            stud.ddate[0] = 0, stud.ddate[1] = 0, stud.ddate[2] = 0;
            fprintf(fp, " %s* %d/%d/%d %s %d/%d/%d %s.\n", stud.name, stud.idate[0], stud.idate[1], stud.idate[2], stud.status, stud.ddate[0], stud.ddate[1], stud.ddate[2], stud.issuer);
            fclose(fp);
            display();
            printf("\nBook added successfully!\n");
        }
        else if (choice == 3) //delete CHECK
        {
            printf("\nEnter the name of the book(IN CAPITALS) you want to delete: ");
            scanf(" %[^\n]s", stud1.name);
            deleteline(stud1.name);
            display();
            printf("\nBook deleted successfully!\n");
        }
        else if (choice == 4) //issue CHECK
        {
            printf("Enter name of the student: ");
            scanf(" %[^\n]s", stud1.issuer);
            printf("\nEnter the issue date(dd/mm/yy): ");
            scanf("%d/%d/%d", &stud1.idate[0], &stud1.idate[1], &stud1.idate[2]);
            printf("\nEnter the due date[2 months from issue date(dd/mm/yy)]: ");
            scanf("%d/%d/%d", &stud1.ddate[0], &stud1.ddate[1], &stud1.ddate[2]);
            printf("\nEnter the name of the book you want to issue(IN CAPITALS): ");
            scanf(" %[^\n]s", stud1.name);
            strcpy(stud1.status, nav);
            edit(stud1.name);
            display();
            printf("\nBook issued successfully!\n");
        }
        else if (choice == 5) //re-issue CHECK
        {
            printf("Enter name of the student: ");
            scanf(" %[^\n]s", stud1.issuer);
            printf("\nEnter the current date(dd/mm/yy): ");
            scanf("%d/%d/%d", &stud1.idate[0], &stud1.idate[1], &stud1.idate[2]);
            printf("\nEnter the new due date[2 months from current date(dd/mm/yy)]: ");
            scanf("%d/%d/%d", &stud1.ddate[0], &stud1.ddate[1], &stud1.ddate[2]);
            printf("\nEnter the name of the book you want to re-issue(IN CAPITALS): ");
            scanf(" %[^\n]s", stud1.name);
            strcpy(stud1.status, nav);
            edit(stud1.name);
            display();
            printf("\nBook re-issued successfully!\n");
        }
        else if (choice == 6) //return CHECK
        {
            printf("\nEnter the name of the book you want to return(IN CAPITALS): ");
            scanf(" %[^\n]s", stud1.name);
            strcpy(stud1.status, av);
            strcpy(stud1.issuer, iss);
            stud1.idate[0] = 0, stud1.idate[1] = 0, stud1.idate[2] = 0;
            stud1.ddate[0] = 0, stud1.ddate[1] = 0, stud1.ddate[2] = 0;
            edit(stud1.name);
            display();
            printf("\nBook returned successfully!\n");
        }
        else if (choice == 7) //search CHECK
        {
            printf("\nEnter the name of the book you want to search(IN CAPITALS): ");
            scanf(" %[^\n]s", stud1.name);
            FILE *fp = fopen("db1.txt", "r");
            do
            {
                if (fgetc(fp) == EOF)
                    break;
                fscanf(fp, "%[^*]s", stud.name);
                fseek(fp, 2, SEEK_CUR);
                fscanf(fp, "%d/%d/%d", &stud.idate[0], &stud.idate[1], &stud.idate[2]);
                fseek(fp, 1, SEEK_CUR);
                fscanf(fp, "%s", stud.status);
                fseek(fp, 1, SEEK_CUR);
                fscanf(fp, "%d/%d/%d", &stud.ddate[0], &stud.ddate[1], &stud.ddate[2]);
                fseek(fp, 1, SEEK_CUR);
                fscanf(fp, "%[^.]s", stud.issuer);
                fseek(fp, 1, SEEK_CUR);
                if (strstr(stud.name, stud1.name) != NULL)
                {
                    found = 1;
                    printf("\nNAME OF THE BOOK\t\t\t\t ISSUE-DATE(IF)   STATUS(A/NA)   DUE-DATE(IF)\tISSUER\n\n");
                    printf("%-47s\t %02d/%02d/%02d\t  %-2s\t\t %02d/%02d/%02d\t%s\n", stud.name, stud.idate[0], stud.idate[1], stud.idate[2], stud.status, stud.ddate[0], stud.ddate[1], stud.ddate[2], stud.issuer);
                }
                else
                {
                }
            } while (fgetc(fp) != EOF);
            if (found != 1)
                printf("\nBook not found!\n");
        }
        else if (choice == 8) //fine calculation
        {
            printf("\nEnter the name of the book you want to know the fine of(IN CAPITALS): ");
            scanf(" %[^\n]s", stud1.name);
            printf("\nEnter current date: ");
            scanf("%d/%d/%d", &stud1.ddate[0], &stud1.ddate[1], &stud1.ddate[2]);
            FILE *fp = fopen("db1.txt", "r");
            int monthgap = stud1.ddate[1] - stud.ddate[1];
            int fine;
            do
            {
                if (fgetc(fp) == EOF)
                    break;
                fscanf(fp, "%[^*]s", stud.name);
                fseek(fp, 2, SEEK_CUR);
                fscanf(fp, "%d/%d/%d", &stud.idate[0], &stud.idate[1], &stud.idate[2]);
                fseek(fp, 1, SEEK_CUR);
                fscanf(fp, "%s", stud.status);
                fseek(fp, 1, SEEK_CUR);
                fscanf(fp, "%d/%d/%d", &stud.ddate[0], &stud.ddate[1], &stud.ddate[2]);
                fseek(fp, 1, SEEK_CUR);
                fscanf(fp, "%[^.]s", stud.issuer);
                fseek(fp, 1, SEEK_CUR);

                if (strcmp(stud.name, stud1.name) == 0)//same name
                {
                    found1 = 1;
                    if (stud1.ddate[2] - stud.ddate[2] < 0) //less year
                        printf("\nNO FINE!\n");
                    else if (stud1.ddate[2] - stud.ddate[2] == 0) //same year
                    {
                        if (stud1.ddate[1] - stud.ddate[1] < 0) //less month
                            printf("\nNO FINE!\n");
                        else if (stud1.ddate[1] - stud.ddate[1] == 0) //same month
                        {
                            if (stud1.ddate[0] - stud.ddate[0] <= 0) //less or same day
                                printf("\nNO FINE!\n");
                            else //more day
                            {
                                fine = (stud1.ddate[0] - stud.ddate[0]) * 2;
                                printf("\nFine for this book is : Rs %d\n", fine);
                            }
                        }
                        else //more month
                        {
                            fine = (30 * (monthgap - 1) + stud1.ddate[0] + 30 - stud.ddate[0]) * 2;
                            printf("\nFine for this book is : Rs %d\n", fine);
                        }
                    }
                    else //more year
                    {
                        int yeargap = stud1.ddate[2] - stud.ddate[2];
                        fine = (30 * 12 * (yeargap - 1) + (stud1.ddate[1] - 1) * 30 + stud1.ddate[0] + 30 * (12 - stud.ddate[1]) + 30 - stud.ddate[0]) * 2;
                        printf("\nFine for this book is : Rs %d\n", fine);
                    }
                }
                else//diff name
                {
                }

            } while (fgetc(fp) != EOF);
            if (found1 != 1)
                printf("\nBook not found!\n");
        }
        else if (choice == 0)
            printf("THANK YOU!\n");
        else
            printf("INVALID CHOICE ENTER AGAIN!\n");
    } while (choice != 0);
}
