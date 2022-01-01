#include<stdio.h>

void swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

int main(void)
{
	int a = 10;
	int b = 10;

	printf("swap before a is %d\tb is %d\n", a, b);
	
	swap(&a, &b);

	printf("swap after a is %d\tb is %d\n", a, b);
	
	return 0;
}
