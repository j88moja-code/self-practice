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

/* global var */
int tLength = 0;
FILE *fp;

/* macros */

#define BUFSIZE 1024
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
  * @isDelkoOn: delko running.
  * @comment: comment regarding production figures
  */

typedef struct vars_data
{
	float production;
	float downtime;
	float prod_rate;
	float projected_tons;
	int break_percent;
	float yield;
	int hd_level;
	_Bool isDelkoOn;
	char createdAt[50];
} vars_t;

/**
  * struct builtins - manage the builtin functions.
  * @name: name of builtin function
  * @f: function for corresponding builtin
  */

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
