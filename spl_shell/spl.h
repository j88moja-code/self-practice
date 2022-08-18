#ifndef _SPL_H_
#define _SPL_H_

/* libraries */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* global var */
FILE *fp;

/* macros */

#define PRINT(c) (write(STDOUT_FILENO, c, _strlen(c)))
#define PROMPT "j88-spl_shell "
#define SUCCESS (1)
#define FAIL (-1)
#define NEUTRAL (0)

/* struct */
/**
 * struct vars_data - global data structure.
 * @production: current production rate
 * @downtime: current downtime
 * @prod_rate: running production rate
 * @break_percent: running prod rate
 * @yield: running yield.
 * @hd_level: running hd level
 * @created_at: the time an entry was created.
 * @comment: comment regarding production figures
 */

struct vars_data
{
  char production[50];
  char downtime[50];
  char prod_rate[50];
  char projected_tons[50];
  char break_percent[50];
  char yield[50];
  char hd_level[50];
  char comment[250];
  char created_at[50];
} vars_t[1000];

/*-----PROTOTYPES-----*/

/*--------builtins-----------*/
void save_to_file(void);
void get_file_size(void);
void read_from_file(void);
void add_entry(void);
void print_all_entries(void);
void delete_entry(void);
void show_options(void);
void firstTime(void);

#endif /* _SPL_H */
