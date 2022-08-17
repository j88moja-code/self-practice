#include "spl.h"

/**
 * add_entry - adds entry to the spl_shell file.
 *
 * Return: nothing.
 */

void add_entry(void)
{
  /*production*/
  float user_input[50];

  printf("Enter current production (t) \n>>> ");
  scanf("%f\n", user_input);
  strncpy(vars_t[tLength].production, user_input, 50);

  /*capture downtime*/
  float user_input3[50];

  printf("Enter current dt (mins) \n>>> ");
  scanf("%f\n", user_input3);
  strncpy(vars_t[tLength].downtime, user_input3, 50);

  /*production rate*/
  float pope_speed, gsm, result;
  float deckle;

  printf("Enter pope speed (m/min) \n>>>>>> ");
  scanf("%f\n", pope_speed);
  printf("Enter grammage (gsm) \n>>>>>> ");
  scanf("%f\n", gsm);
  printf("Enter deckle (m) \n>>>>>> ");
  scanf("%f\n", deckle);

  result = ((pope_speed * gsm * deckle * 60) / (1000000));
  strncpy(vars_t[tLength].prod_rate, result, 50);

  /* projected tons */
  float remain_time, result2;

  printf("Enter remaining time till shift ends (hours) \n>>>>>>");
  scanf("%f\n", remain_time);

  result2 = (user_input + (result * remain_time));
  strncpy(vars_t[tLength].projected_tons, result2, 50);

  /*projected tons*/
  int joints, reels;
  int result3;

  printf("Enter number of joints \n>>>>>>");
  scanf("%d\n", joints);

  printf("Enter number of reels \n>>>>>> ");
  scanf("%d\n", reels);

  result3 = ((joints / reels) * 100);
  strncpy(vars_t[tLength].break_percent, result3, 50);

  /*yeild capture */
  float ds_weight, result4;

  printf("Enter current weight input at daystore (t) \n>>>>>>");
  scanf("%f\n", ds_weight);

  result4 = ((user_input / ds_weight) * 100);
  strncpy(vars_t[tLength].yield, result4, 50);

  /*capture hd*/
  float user_input4[50];

  printf("Enter current hd level (%) \n>>> ");
  scanf("%f\n", user_input4);
  strncpy(vars_t[tLength].hd_level, user_input4, 50);
  /*add comment*/
  char comnt[250];

  printf("Comment(s) \n>>> ");
  scanf("%[^\n]s"; comnt);
  strncpy(vars_t[tLength].comment, comnt, 250);

  /* add time */
  char user_input2[50];

  struct tm cTime;
  time_t timeS = time(NULL);
  localtime_r(&timeS, &cTime);
  snprintf(user_input2, 50, "%i/%i %i:%i", cTime.tm_mday, cTime.tm_mon + 1,
           cTime.tm_hour, cTime.tm_min);
  strcpy(vars_t[tLength].created_at, user_input2);
}

/**
 * print_all_entries - prints out all entries in a particular format.
 *
 * Return: nothing.
 */

void print_all_entries(void)
{
  int i;

  printf("+----+----------+--------+--------+--------+--------+-----+-----+------+-------------------------+\n");
  printf("| ID |Created at| tons   |   mins | t/hr   | tons   |  b% | y%  | hd%  |        Comments         |\n");
  printf("+----+----------+--------+--------+--------+--------+-----+-----+------+-------------------------+\n");

  for (i = 0; i < tLength; i++)
  {
    printf("|%3d |%-13s|%3.f |%2.f |%3.f  |%3.f  |%3d |%3.f  |%3d  |  %-35s |\n",
           vars_t[i].created_at, vars_t[i].production, vars_t[i].downtime,
           vars_t[i].prod_rate, vars_t[i].projected_tons, vars_t[i].break_percent,
           vars_t[i].yield, vars_t[i].hd_level, vars_t[i].comment);
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

  printf("Enter the ID of the entry \n");
  scanf("%d", &entry_id);

  if (entry_id < 0 || entry_id > tLength)
  {
    printf("Invalid entry ID \n");
  }
  else
  {
    entry_id--;
    memmove(vars_t + entry_id, vars_t + entry_id + 1, (tLength - entry_id - 1) * sizeof(*vars_t));
    tLength--;
    printf("Entry has been deleted \n");
  }
}
