#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "login_functions.c"

int main(void)
{
    int opt, usrFound = 0;
    FILE *fp;
    person info, info_store;
    person *point_info = &info;
    system("cls");
    system("color 0b");
    printf("\n\t\t\t------------Welcome to authentication system----------------");
    printf("\nPlease choose your operation");
    printf("\n1.Signup");
    printf("\n2.Login");
    printf("\n3.Exit");

    printf("\nYour choice:\t");
    scanf("%d", &opt);
    fgetc(stdin);

    switch (opt)
    {
    case 1:
        take_input(point_info, 'n');
        take_input(point_info, 'e');
        take_input(point_info, 'p');
        take_password(point_info, 1);
        take_password(point_info, 2);

        if (!(compare_str(point_info->pword, point_info->pword2)))
        {
            generate_username(point_info);
            printf("\nYour username is %s", point_info->username);
            fp = fopen("Users2.txt", "a+");
            if ((fp == NULL))
            {
                fprintf(stderr, "%s", "Failed to open file ");
                break;
            }
            else
            {
                if (!(fwrite(&info, sizeof(person), 1, fp)))
                {
                    fprintf(stderr, "%s", "Registration unsuccessfull");
                    break;
                }
                else
                {
                    printf("Registration Successfull");
                }
            }
        }
        fclose(fp);
        break;
    case 2:
        take_input(point_info, 'u');
        take_password(point_info, 1);
        fp = fopen("Users2.txt", "r");
        if (fp == NULL)
        {
            fprintf(stderr, "Error opening file for reading");
            exit(1);
        }
        printf("\nYour password is %s\n\n", info.pword);
        while (fread(&info_store, sizeof(person), 1, fp))
        {
            if (!compare_str(info_store.username, info.username))
            {

                system("cls");
                if (!compare_str(info.pword, info_store.pword))
                {
                    system("cls");
                    printf("\n\t\t\t\t\t\t\t\t\tWelcome %s", info_store.fname);
                    printf("\n\n|Full Name:\t%s", info_store.fname);
                    printf("\n|Email:\t\t%s", info_store.email);
                    printf("\n|Username:\t%s", info_store.username);
                    printf("\n|Contact no.:\t%s", info_store.phone_num);
                }

                else
                {
                    printf("\n\nInvalid Password!");
                    Beep(800, 300);
                }
                usrFound = 1;
            }
        }
        if (!usrFound)
        {
            printf("\n\nUser is not registered!");
            Beep(800, 300);
        }
        fclose(fp);
        break;
    case 3:
        printf("\t\t\t Bye Bye :)");
        break;
    }
    return 0;
}
