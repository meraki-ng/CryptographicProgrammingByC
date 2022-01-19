#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define KEY 3  // 키는 자연수
#define SPACE 26
#define RETURN_TEST 1.0
/*
	***********************CHALLENGE 7**********************
                                            출처 : 암호학 과외
                                    곱셈 암호 (ASCII CODE 127)
	************************************************************
                                                   개선할 점
                                                  inverse 구현
                                              decoding 함수 구현
*/
void encoding_func(char[], char*, int, int);
void decoding_func(char[], char*, int, int);
int key_error(int, int);
void error_check();
void gcd_error();
int inverse_gcd2Euclid(int, int, int, int, int);
int inverse(int, int, int);

int main()
{
	char plainText[] = { "hi, where are you from~?	" };
	const  int input_size = strlen(plainText);
	char decoding[sizeof(plainText)] = { 0, }, encoding[sizeof(plainText)] = { 0, };

	encoding_func(plainText, encoding, KEY, input_size);
	error_check();

	return 0;
}

void decoding_func(char encoding[], char *decoding, int key, int size)
{

}

void encoding_func(char plainText[], char *encoding, int key, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		*(encoding + i) = ((plainText[i] * key) % SPACE);
	}
}

int inverse_gcd2Euclid(int key, int space, int gcd_mid, int space_mid, int gcd_mid2)
{
	if (key < space)
	{
		if ((space % key) > 1)
		{
			space_mid = space; // gcd == 1 경우, 나머지 < 1
			gcd_mid2 = (space - (space % key)) / (space / key);
		}
		if(space % key == 1)
		{
			gcd_mid = (space - (space % key)) / (space / key);
		}
		if ((space % key) == 0 && ((space - (space % key)) / (space / key)) == 1) return  inverse(gcd_mid, space_mid, gcd_mid2, SPACE);
		else if ((space % key) == 0 && (space - (space % key)) / (space / key) > 1) gcd_error();
		else
		{
			int mod = (space % key);
			int div = (space / key);
			int gcd = (space - (mod)) / div;
			space = ((div)* key) + (mod);
			return inverse_gcd2Euclid(mod, gcd, gcd_mid, space_mid, gcd_mid2);
		}
	}
	else	return inverse_gcd2Euclid((key%space), space, gcd_mid, space, gcd_mid2);
}
int key_error(int key, int space)
{
	if (space > key)	return (space % key);
	else return (key % space);
}

int inverse(int gcd_mid, int space_mid, int gcd_mid2, int space)
{
	// space = x + gcd_mid;
	 
	//int res = space % gcd_mid2 + 
	return RETURN_TEST;
}


void error_check()
{
	if (key_error(KEY, SPACE))	inverse_gcd2Euclid(KEY, SPACE, 0, 0, 0);
	else
	{
		fprintf(stderr, "Condition ERROR");
		exit(1);
	}
}

void gcd_error()
{
	fprintf(stderr, "gcd ERROR");
	exit(1);
}