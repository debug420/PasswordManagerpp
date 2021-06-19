#pragma once
#include <iostream>
#include <ctype.h>
#include <string>
#include <random>

#include "picosha2.h"

#define say(x) std::cout << x << std::endl;
#define sayn(x) std::cout << x;
#define div() say("================================");
#define newline() std::cout << std::endl;

namespace pm
{

	std::string hash(const std::string& src) {
		return picosha2::hash256_hex_string(src);
	}

	void clearCinCache()
	{
		// Clear CIN Buffer
		std::cin.seekg(0, std::ios::end);
		std::cin.clear();
	};

	bool isKeyValid(std::string key)
	{
		bool doesPass = true;

		int charAmount = 0;

		// Check if all keys are part of the alphabet and if there is 26
		for (int i = 0, n = key.length(); i < n && doesPass; i++)
		{
			if (!isalpha(key[i]))
			{
				doesPass = false;
			}
			else
			{
				charAmount++;
			}
		}

		if (!(charAmount == 26))
		{
			doesPass = false;
		}


		// Check if there is any duplicate chars
		for (char c = 'a'; c < 'z' && doesPass; c++)
		{
			int matches = 0;
			for (int i = 0, n = key.length(); i < n && doesPass; i++)
			{
				if (static_cast<char>(key[i]) == static_cast<char>(c))
				{
					matches++;
					doesPass = false;
				}
			}
			if (matches > 1)
			{
				doesPass = false;
			}
		}

		return doesPass;
	}

	void sayIntro()
	{
		newline();
		div();
		say("Loaded PasswordManager++");
		div();
		say("Commands: ");
		say("- makeAccount <Makes account information class>")
		say("- removeAccount <Removes already existing account>")
		say("- getInfo  <Gets account information of accout>");
		say("- editInfo <Edit account information of account>");
		say("- listAccs <Lists all saved accounts>");
		div();
		newline();
	}

	int random(int min, int max)
	{
		std::default_random_engine gen(std::random_device{}());
		std::uniform_int_distribution<int> dist(min, max);
		return dist(gen);
	}

}