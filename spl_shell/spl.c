#include "spl.h"

/**
 * first_time_use - checks if the file for saving entries is available.
 *
 * Return: void.
 */

void first_time_use(void)
{
    if (access("spl_shell.bin", F_OK) != -1)
    {
        read_from_file();
        print_all_entries();
        show_options();
    }
    else
    {
        printf("SPL PAPH");
        add_entry();
        save_to_file();
        print_all_entries();
        show_options();
    }
}

int main(void)
{
    system("clear||@cls");
    printf("\033[32;1m");
    first_time_use();
}