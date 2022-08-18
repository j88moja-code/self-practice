#include "spl.h"

/**
 * add_entry - adds entry to the spl_shell file.
 *
 * Return: nothing.
 */

void add_entry(void)
{
  /*production*/
  double user_input;
  char prod[50];
  int j = 0;

  printf("Enter current production (t) \n>>> ");
  scanf("%lf\n", &user_input);
  snprintf(prod, 50, "%lf", user_input);
  strcpy(vars_t[j].production, prod);
  
  /*capture downtime*/
  char dt[50];
  double user_input3;

  printf("Enter current dt (mins) \n>>> ");
  scanf("%lf\n", &user_input3);
  snprintf(dt, 50, "%lf", user_input3);
  strcpy(vars_t[j].downtime, dt);

  /*production rate*/
  char pdr[50];
  double pope_speed, gsm, result;
  double deckle;

  printf("Enter pope speed (m/min) \n>>>>>> ");
  scanf("%lf\n", &pope_speed);
  printf("Enter grammage (gsm) \n>>>>>> ");
  scanf("%lf\n", &gsm);
  printf("Enter deckle (m) \n>>>>>> ");
  scanf("%lf\n", &deckle);

  result = ((pope_speed * gsm * deckle * 60) / (1000000));
  snprintf(pdr, 50, "%lf", result);
  strcpy(vars_t[j].prod_rate, pdr);

  /* projected tons */
  char proj_t[50];
  double remain_time, result2;

  printf("Enter remaining time till shift ends (hours) \n>>>>>>");
  scanf("%lf\n", &remain_time);

  result2 = (user_input + (result * remain_time));
  snprintf(proj_t, 50, "%lf", result2);
  strcpy(vars_t[j].projected_tons, proj_t);

  /*break percentage*/
  char brkp[50];
  int joints, reels;
  double result3;

  printf("Enter number of joints \n>>>>>>");
  scanf("%d\n", &joints);

  printf("Enter number of reels \n>>>>>> ");
  scanf("%d\n", &reels);

  result3 = ((joints / reels) * 100);
  snprintf(brkp, 50, "%lf", result3); 
  strcpy(vars_t[j].break_percent, brkp);

  /*yeild capture */
  char yiel[50];
  double ds_weight, result4;

  printf("Enter current weight input at daystore (t) \n>>>>>>");
  scanf("%lf\n", &ds_weight);

  result4 = ((user_input / ds_weight) * 100);
  snprintf(yiel, 50, "%lf", result4);
  strcpy(vars_t[j].yield, yiel);

  /*capture hd*/
  char hd[50];
  double user_input4;

  printf("Enter current hd level (perc.) \n>>> ");
  scanf("%lf\n", &user_input4);
  snprintf(hd, 50, "%lf", user_input4);
  strcpy(vars_t[j].hd_level, hd);

  /*add comment*/
  char comnt[100];

  printf("Comment(s) \n>>> ");
  scanf("%[^\n]s", comnt);
  strncpy(vars_t[j].comment, comnt, 250);

  /* add time */
  char user_input2[50];

  struct tm cTime;
  time_t timeS = time(NULL);
  localtime_r(&timeS, &cTime);
  snprintf(user_input2, 50, "%i/%i %i:%i", cTime.tm_mday, cTime.tm_mon + 1,
           cTime.tm_hour, cTime.tm_min);
  strcpy(vars_t[j].created_at, user_input2);
}

/**
 * print_all_entries - prints out all entries in a particular format.
 *
 * Return: nothing.
 */

void print_all_entries(void)
{
  int i;
  int j = 0;

  printf("+----+----------+--------+--------+--------+--------+-----+-----+------+-------------------------+\n");
  printf("|ID | tons | mins | t/hr | tons/p| brkp | yld |  hdl |        Comments      |	Created at     	  |\n");
  printf("+----+----------+--------+--------+--------+--------+-----+-----+------+-------------------------+\n");

  for (i = 0; i < j; i++)
  {
    printf("|%3d |%3s |%-4s |%-2s |%6s  |%8s  |%-5s |%3s  |%-35s  |  %-13s |\n", i + 1,	
           vars_t[i].production, vars_t[i].downtime, vars_t[i].prod_rate,
	   vars_t[i].projected_tons, vars_t[i].break_percent, vars_t[i].yield,
           vars_t[i].hd_level, vars_t[i].comment, vars_t[i].created_at);
    printf("+----+----------+--------+--------+--------+--------+-----+-----+------+-------------------------+\n");
  }
}

/**
 * delete_entry - deletes shell entry from the list.
 *
 * Return: nothing.
 */

void delete_entry(void)
{
  int entry_id;
  int j = 0;

  printf("Enter the ID of the entry \n");
  scanf("%d", &entry_id);

  if (entry_id < 0 || entry_id > j)
  {
    printf("Invalid entry ID \n");
  }
  else
  {
    entry_id--;
    memmove(vars_t + entry_id, vars_t + entry_id + 1, (j - entry_id - 1) * sizeof(*vars_t));
    j--;
    printf("Entry has been deleted \n");
  }
}
