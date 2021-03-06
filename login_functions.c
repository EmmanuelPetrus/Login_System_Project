#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "login.h"

typedef struct Detail person;
struct Detail
{
    char fname[BUFFER];
    char email[BUFFER];
    char username[BUFFER];
    char phone_num[BUFFER];
    char pword[BUFFER];
    char pword2[BUFFER];
};

// function to take input
void take_input(person *user, char n)
{
    if ((n == 'n') || (n == 'e'))
    {
        char *info = (n != 'n') ? "email" : "name";
        if (!strcmp(info, "name"))
        {
            printf("\nEnter your fullname: ");
            fgets(user->fname, BUFFER, stdin);
            fflush(stdin);
        }
        if (!strcmp(info, "email"))
        {
            printf("\nEnter your email: ");
            fgets(user->email, BUFFER, stdin);
            fflush(stdin);
        }
    }
    else if (n == 'p')
    {
        printf("\nEnter your phone number: ");
        fgets(user->phone_num, BUFFER, stdin);
        fflush(stdin);
    }
    else
    {
        printf("\nEnter your username: ");
        fgets(user->username, BUFFER, stdin);
    }
}

// function to generate username
void generate_username(person *user)
{
    int i = 0;
    for (i = 0; i < strlen(user->email); i++)
    {
        if (*(user->email + i) == '@')
        {
            break;
        }
        else
        {
            *(user->username + i) = *(user->email + i);
        }
    }
    user->username[i] = '\0';
}

// function to take password
void take_password(person *p_word, int n)
{
    int k = 1;
    char *message = (n == k) ? "Enter" : "Confirm";
    if (!(strcmp(message, "Enter")))
    {
        char password[15] = {0};
        char ch;
        printf("\nYour Passwsord must not be more than 14 characters long\n");
        printf("%s your password: ", message);

        int i = 0;
        while (((ch = getch()) != '\r') && (i < 10))
        {
            if (ch == BACKSPACE)
            {
                if (i > 0)
                {
                    i--;
                    printf("\b \b");
                }
            }
            else
            {
                password[i++] = ch;
                printf("*");
            }
        }
        password[i] = '\0';
        strcpy(p_word->pword, password);
    }
    else
    {
        char ch;
        char password[15] = {0};
        printf("\n%s your password: ", message);

        int i = 0;
        while (((ch = getch()) != '\r') && (i < 10))
        {
            if (ch == BACKSPACE)
            {
                if (i > 0)
                {
                    i--;
                    printf("\b \b");
                }
            }
            else
            {
                password[i++] = ch;
                printf("*");
            }
        }
        password[i] = '\0';
        strcpy(p_word->pword2, password);
    }
}

// function to compare strings
int compare_str(char a[], char b[])
{
    int flag = 0, i = 0;                                                 // integer variables declaration
    while (a[i] != '\0' && b[i] != '\0' && a[i] != '\n' && b[i] != '\n') // while loop
    {
        if (a[i] != b[i])
        {
            flag = 1;
            break;
        }
        i++;
    }
    if (flag == 0)
        return 0;
    else
        return 1;
}