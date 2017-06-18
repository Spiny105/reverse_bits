// reverseBits.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <stdint.h>
#include <bitset> 

//Переворот битов в цикле с возможностью задания длинны числа в битах
uint32_t ReverseBitsInCycle(uint32_t input, uint32_t bits = sizeof(int) * 8)
{
	int leftMask = 0x1 << bits - 1;
	int rigthMask = 0x1;
    int output = 0;

    for (uint32_t i = 0; i < bits / 2; i++)
    {
        output |= ((input <<  bits - i*2 - 1) & leftMask) | ((input <<  bits - i*2 - 1) & leftMask);
		leftMask >>= 1;
		rigthMask <<= 1;
    }

    return output;
}

//Переворот числа без цикла, который честно гуглится за 5 минут :)
uint32_t ReverseBits(uint32_t n)
{
		n = (n >> 1) & 0x55555555 | (n << 1) & 0xaaaaaaaa;
        n = (n >> 2) & 0x33333333 | (n << 2) & 0xcccccccc;
        n = (n >> 4) & 0x0f0f0f0f | (n << 4) & 0xf0f0f0f0;
        n = (n >> 8) & 0x00ff00ff | (n << 8) & 0xff00ff00;
        n = (n >> 16) & 0x0000ffff | (n << 16) & 0xffff0000;
        return n;
}

int _tmain(int argc, _TCHAR* argv[])
{
	const uint32_t value = 0x5;
	uint32_t result = 0;

	//Проверка функции ReverseBitsInCycle
	int sizeInBits = 8;
	std::cout << "Source number = " << std::bitset<sizeof(value) * 8>(value) << std::endl;
	std::cout << "Length of the number in bits = " << sizeInBits << std::endl;
	result = ReverseBitsInCycle(value, sizeInBits);
	std::cout << "ReverseBitsInCycle result = " << std::bitset<sizeof(result) * 8>(result) << std::endl << std::endl;

	sizeInBits = 9;
	std::cout << "Length of the number in bits = " << sizeInBits << std::endl;
	result = ReverseBitsInCycle(value, sizeInBits);
	std::cout << "ReverseBitsInCycle result = " << std::bitset<sizeof(result) * 8>(result) << std::endl << std::endl;

	//Проверка функции ReverseBits
	result = 0;
	result = ReverseBits(value);
	std::cout << "ReverseBits result = " << std::bitset<sizeof(result) * 8>(result) << std::endl;

	system("pause");
	return 0;
}

