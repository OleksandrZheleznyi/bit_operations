/* 
*	Counting units(1) in a 32-bit number
*	The input has a 32 bit number. Required:
*  	1. Count the number of continuous bits set to the 1 most high-order bits
*   2. Count the number of continuous bits set to 1 least significant bits
*   3. Number of bits set in 1 bit
*   4. The sum modulo 2 of all bits of a number
*	5. Reverse bits
*/

#include <stdio.h>

#define DATA 0xe000000f 
//#define DATA 0xe0f /* Another input parameter */ 

/* number of continuous bits set to the 1 most high-order bits */
unsigned sum_high_bits(unsigned x);
/* number of continuous bits set to 1 least significant bits */
unsigned sum_low_bits(unsigned x);
/* population count */
int pop1(unsigned x);
int pop4(unsigned x);//To count single bits in low-filled words
int pop5(unsigned x);
/* Based on the counting of single bits, parity represents
the low-order bit of the value returned by the function pop(),
but if there is no function pop() it is necessary to use specialized methods */
/* A specialized method for calculating parity */
unsigned parity1(unsigned x);

int main(void)
{
	unsigned high, low, set, par;
	high = sum_high_bits(DATA);
	low = sum_low_gbits(DATA);
	set = pop1(DATA);
	par = parity1(DATA);
	printf("data: 0x%x => begin: %d end: %d bits set: %d bits xor: %d\n", DATA, high, low, set, par);
	unsigned test1 = 7;
	printf("%d\n", pop4(test1));
	return 0; 
}

int pop1(unsigned x)
{
	x = (x & 0x55555555) + ((x>>1) & 0x55555555);
	x = (x & 0x33333333) + ((x>>2) & 0x33333333);
	x = (x & 0x0f0f0f0f) + ((x>>4) & 0x0f0f0f0f);
	x = (x & 0x00ff00ff) + ((x>>8) & 0x0f0f0f0f);
	x = (x & 0x0000ffff) + ((x>>16) & 0x0000ffff);
	return x;
}

int pop4(unsigned x)
{
	int n = 0;
	while (x != 0)
	{
		n = n + 1;
		x = x & (x - 1);/* the rightmost one bit make zero */
	}
	return n;
}

int pop5(unsigned x)
{
	unsigned sum = x;
	while (x != 0)
	{
		x = x >> 1;
		sum = sum - x;
	}
	return sum;
}

unsigned sum_high_bits(unsigned x)
{
	unsigned count = 0;
	unsigned mask = 0x80000000;
	while ( (x & mask) == mask )
	{
		mask >>= 1;
		count++;	
	}
	return count;
}
unsigned sum_low_bits(unsigned x)
{
	unsigned count = 0;
	unsigned mask = x & (-x);
	while ( (x & mask) == mask )
	{
		mask <<= 1;
		count++;	
	}
	return count;
}

unsigned parity1(unsigned x)
{
	unsigned y;
	y = x ^ (x >> 1);
	y = y ^ (y >> 2);
	y = y ^ (y >> 4);
	y = y ^ (y >> 8);
	y = y ^ (y >> 16);
	return y & 1;
}
