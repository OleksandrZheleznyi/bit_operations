/* 
*	Calculating the value of a hash function
*	Input parameters and result
*	string: “1234567891” => 0x6882da66
*	string: “1234567890” => 0x4882da67 
*/
#include <stdio.h>

/* Input parameters */
const char * mas1="1234567891";
const char * mas2="1234567890";
/* hash function */
unsigned hash_func(const char * M);

int main(void)
{
	/* Checking the result */
	printf("%s%x\n", "string \"1234567891\" => 0x", hash_func(mas1));
	printf("%s%x\n", "string \"1234567890\" => 0x", hash_func(mas2));
	return 0;
}

unsigned hash_func(const char * M)
{
	/* Initial conditions: */
	unsigned int A; 
	unsigned int B; 
	A = 0xac92c155;
	B = 0xb4c17c82;
	
	/* Cycle on all bytes (not including 0 at the end of the line) of the input array M: */
	while ( *M )
	{
		A = A ^ (*M++);
		
		if ( (B + A) < 1ULL<<32)//or ((1<<16) + (1<<16)), because: "warning: left shift count >= width of type"	
			B = B + A;
		else
			B = (B + A) - (1ULL<<32);
		/* B = ((B + A) < 1ULL<<32) ? B + A : (B + A) - (1ULL<<32); */
		if ((B & 0x80000000) == 0x80000000)
			B = B ^ 0x2985eb9d;
		else	
			B = B ^ 0x513383b1;	
		/* B = ((B & 0x80000000) == 0x80000000) ? B ^ 0x2985eb9d : B ^ 0x513383b1; */ 

		/* Cyclic shift of a 32-bit number by 3 bits to the right 
		(from senior to junior), result is a 32-bit number */
		A = (A >> 3) | (A << 29);		
	}
	return A ^ B;
}
