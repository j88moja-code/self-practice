#include "spl.h"

/**
 * show_options - prints out the options available in the program
 *
 * Return: void.
 */

void show_options(void)
{
    char user_choice;
    printf("Type 'A' to add, &'D' to delete or 'Q' to quit\n>>");
    user_choice = getchar();
    user_choice = toupper(user_choice);
    getchar();
    switch (user_choice)
    {
    case 'A':
        add_entry();
        break;
    case 'D':
        delete_entry();
        break;
    case 'Q':
        exit(0);
        break;
    default:
        printf("Command not found \n");
        show_options();
        break;
    }
}