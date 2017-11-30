/*Output digits of number*/
#include <stdio.h>

void out_digit(int n);

int main(void)
{
	int number;
	printf("Enter an integer: ");
	scanf("%d", &number);
	out_digit(number);
	printf("\n");
	return 0;
}

void out_digit(int n)
{
	if (n / 10 == 0)
		printf("%d ", n);
	else
	{
		out_digit(n / 10);	
		printf("%d ", n % 10);
	}	
}