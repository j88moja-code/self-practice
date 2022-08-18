#include "spl.h"

/**
 * save_to_file - creates new file.
 *
 * Return: nothing.
 */

void save_to_file(void)
{

	size_t i = 0;
	int j = 0;

	fp = fopen("spl_shell.bin", "w");
	if (!fp)
	{
		printf("Can't save entry\n");
	}
	else
	{
		for (i = 0; i < j; i++)
		{
			fwrite(&vars_t[i], sizeof(struct vars_data), 1, fp);
		}
		fclose(fp);
	}
}

/**
 * get_file_size - checks the size of the file.
 *
 * Return: nothing.
 */

void get_file_size(void)
{
	int j = 0;

	fseek(fp, 0L, SEEK_END);
	unsigned int long size = ftell(fp);
	fseek(fp, 0L, SEEK_SET);
	j = size / sizeof(struct vars_data);
}

/**
 * read_from_file - reads contents of the file.
 *
 * Return: nothing.
 */

void read_from_file(void)
{
	size_t i;
	int j = 0;

	fp = fopen("spl_shell.bin", "r");
	if (!fp)
		printf("Cannot find any spl_shell file\n");
	else
	{
		get_file_size();
		for (i = 0; i < j; i++)
		{
			fread(&vars_t[i], sizeof(struct vars_data), 1, fp);
		}
		fclose(fp);
	}
}
