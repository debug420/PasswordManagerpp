#pragma once
#include <string>
#include <ctype.h>

namespace pm
{

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
		std::string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

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
					output[ii] = islower(value[ii])? tolower(abc[indexPos]) : toupper(abc[indexPos]);
				}
			}

		}

		return output;
	}

}