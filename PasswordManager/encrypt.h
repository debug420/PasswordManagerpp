#pragma once
#include <string>
#include <ctype.h>
#include <vector>

namespace pm
{

	const char ALPHABET[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	std::string genRandomEncryptionKey()
	{
		std::string output;

		for (int i = 0; i < 27; i++)
		{
			char chosenChar;
			do
			{
				chosenChar = ALPHABET[random(0, 26)];
			} while (output.find(chosenChar) != std::string::npos && !isalpha(chosenChar));
			output.push_back(chosenChar);
		}

		return output;
	}

	std::string encrypt(std::string value, std::string key)
	{
		char output[100] = "";
		for (int i = 0, n = value.length(); i < n; i++)
		{
			if (isalpha(value[i]))
			{
				bool alphaState = isupper(value[i]);
				char a = key[(int)tolower(value[i]) - 97];
				output[i] = alphaState ? toupper(a) : tolower(a);
			}
			else if (ispunct(value[i]) || isspace(value[i]) || isdigit(value[i]))
			{
				output[i] = value[i];
			}
		}
		return output;
	}

	std::string decrypt(std::string value, std::string key)
	{
		char output[100] = "";

		for (int ii = 0, nn = value.length(); ii < nn; ii++)
		{
			if (ispunct(value[ii]) || isspace(value[ii]) || isdigit(value[ii]))
			{
				output[ii] = value[ii];
				continue;
			}
			else if (isalpha(value[ii]))
			{
				int indexPos = -1;
				for (int i = 0, n = key.length(); i < n; i++)
				{
					if (isalpha(key[i]) && tolower(value[ii]) == tolower(key[i]))
					{
						indexPos = i;
					}
				}
				if (!(indexPos == -1))
				{
					output[ii] = islower(value[ii])? tolower(ALPHABET[indexPos]) : toupper(ALPHABET[indexPos]);
				}
			}

		}

		return output;
	}

}
