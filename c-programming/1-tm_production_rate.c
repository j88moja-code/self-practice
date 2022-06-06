#include <stdio.h>
#include <string.h>

/**
*This program calculates the production rate for a tissue machine
*main - Entry point
*scanf - takes in user input
*printf - prints out message
*Return: 0 (Success)
*/

int main(void)
{
	double grammage;
	int deckle;
	int machineSpeed;
	double crepeRatio;
	double crepePercentage;
	char response[3];
	float productionRate;

	printf("Enter grammage in g/m2 : ");
	scanf("%lf", &grammage);
	printf("Enter deckle in mm: ");
	scanf("%d", &deckle);
	printf("Enter machine speed in m/min: ");
	scanf("%d", &machineSpeed);
	/*determines whether the user wants to determine proction rate with crepe ratio or crepe percentage*/
	printf("Do you want to calculate using crepe ratio CR (No = crepe percent (CP))?\n Enter yes or no: ");
	scanf("%s", response);
	/*explicitly check for response*/
	if (!strcmp(response, "yes"))
	{
		printf("Enter crepe ratio: ");
		scanf("%lf", &crepeRatio);
		/*calculates the prodcution rate of a tissue machine from given user input for crepe ratio*/
		productionRate =(float)(((grammage * deckle * (machineSpeed / crepeRatio)) / 1000000000.00)*60);
		printf("Production Rate = %.2f t/h", productionRate);
	} else
	{
		printf("Enter crepe percentage: ");
		scanf("%lf", &crepePercentage);
		/*calculates the prodcution rate of a tissue machine from given user input for crepe percentage*/
		productionRate =(float)(((grammage * deckle * (machineSpeed - (machineSpeed * (crepePercentage / 100.00)))) / 1000000000.00)*60);
		printf("Production Rate = %.2f t/h", productionRate);
	}
	return (0);
}
