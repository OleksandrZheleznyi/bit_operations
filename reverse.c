/*Reverse of number bit*/
#include <stdio.h>

unsigned long long reverse_bit(unsigned long long x);

int main(void)
{
	unsigned long long number = 1;
	printf("%lld\n", 2147483648LL * 2147483648LL * 2 - 1);
	printf("%lld\n", reverse_bit(number));
	return 0;
}

unsigned long long reverse_bit(unsigned long long x)
{
	//For the reverse of a 64 bit word
	//x = (x << 32) | (x >> 32); //Exchange half the register
	x = (x & 0x5555555555555555LL) <<  1 | (x & 0xAAAAAAAAAAAAAAAALL) >>  1;//Can be used for a 2-bit word
	x = (x & 0x3333333333333333LL) <<  2 | (x & 0xCCCCCCCCCCCCCCCCLL) >>  2;//4 bit
	x = (x & 0x0F0F0F0F0F0F0F0FLL) <<  4 | (x & 0xF0F0F0F0F0F0F0F0LL) >>  4;//8 bit
	x = (x & 0x00FF00FF00FF00FFLL) <<  8 | (x & 0xFF00FF00FF00FF00LL) >>  8;//16 bit
	x = (x & 0x0000FFFF0000FFFFLL) << 16 | (x & 0xFFFF0000FFFF0000LL) >> 16;//32 bit
	x = (x & 0x00000000FFFFFFFFLL) << 32 | (x & 0xFFFFFFFF00000000LL) >> 32;//64 bit
	return x ;
}