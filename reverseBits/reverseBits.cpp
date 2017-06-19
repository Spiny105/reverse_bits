
#include "stdafx.h"
#include <iostream>
#include <stdint.h>
#include <bitset> 

/// Reverse bits in cycle.
/// input - source number
/// bits - length of the number in bits
uint32_t ReverseBitsInCycle(uint32_t input, uint32_t bits = sizeof(int)* 8)
{
	int leftMask = 0x1 << bits - 1;
	int rigthMask = 0x1;
	int output = 0;

	for (uint32_t i = 0; i < bits / 2; i++)
	{
		output |= ((input << bits - i * 2 - 1) & leftMask) | ((input << bits - i * 2 - 1) & leftMask);
		leftMask >>= 1;
		rigthMask <<= 1;
	}

	if (bits % 2 == 1)
	{
		output |= input & (0x1 << (bits / 2));
	}

	return output;
}

/// Reverse bits without cycle
/// input - source number
uint32_t ReverseBits(uint32_t input)
{
	input = (input >> 1) & 0x55555555 | (input << 1) & 0xaaaaaaaa;
	input = (input >> 2) & 0x33333333 | (input << 2) & 0xcccccccc;
	input = (input >> 4) & 0x0f0f0f0f | (input << 4) & 0xf0f0f0f0;
	input = (input >> 8) & 0x00ff00ff | (input << 8) & 0xff00ff00;
	input = (input >> 16) & 0x0000ffff | (input << 16) & 0xffff0000;
	return input;
}

int _tmain(int argc, _TCHAR* argv[])
{
	const uint32_t value = 0xA;
	uint32_t result = 0;

	//Check function ReverseBitsInCycle
	int sizeInBits = 8;
	std::cout << "Source number = " << std::bitset<sizeof(value)* 8>(value) << std::endl;
	std::cout << "Length of the number in bits = " << sizeInBits << std::endl;
	result = ReverseBitsInCycle(value, sizeInBits);
	std::cout << "ReverseBitsInCycle result = " << std::bitset<sizeof(result)* 8>(result) << std::endl << std::endl;

	sizeInBits = 7;
	std::cout << "Length of the number in bits = " << sizeInBits << std::endl;
	result = ReverseBitsInCycle(value, sizeInBits);
	std::cout << "ReverseBitsInCycle result = " << std::bitset<sizeof(result)* 8>(result) << std::endl << std::endl;

	//Check function ReverseBits
	result = 0;
	result = ReverseBits(value);
	std::cout << "ReverseBits result = " << std::bitset<sizeof(result)* 8>(result) << std::endl;

	system("pause");
	return 0;
}

