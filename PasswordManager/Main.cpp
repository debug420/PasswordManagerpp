// Main header files
#include <iostream>
#include <string>
#include <ctype.h>

// User defined header files
#include  "misc.h"
#include "encrypt.h"
#include "fileSystem.h"
#include "accountClass.h"
#include "string.h"
#include "accountList.h"
#include "handler.h"
#include "picosha2.h"

// Define preprocessor statements
#define say(x) std::cout << x << std::endl;
#define sayn(x) std::cout << x;
#define div() say("================================");
#define newline() std::cout << std::endl;

// Test Entry Point
//int main()
//{
//}

// Main Entry Point
int main(int argc, char* argv[])
{

	// First time login
	if (pm::isFirstLogin())
	{
		say("This is your first time using PasswordManager++");
		std::string tempPass;
		do
		{
			sayn("Please set up a valid password to use to edit account profiles: ");
			std::cin >> tempPass;
		} while (tempPass.empty());
		pm::makeFile("pass.txt", pm::hash(tempPass));
	}
	else
	{
		bool passedLogin = false;
		do
		{
			sayn("Please enter your password: ");
			std::string userPassInput;
			std::string userPassHash;
			std::cin >> userPassInput;
			std::ifstream passFile("pass.txt");
			passFile >> userPassHash;
			if (userPassHash == pm::hash(userPassInput))
			{
				div();
				say("Successfully logged in!");
				div();
				passedLogin = true;
			}
		} while (!passedLogin);
	}

	say("Booting up PasswordManager++ ...");
	div();

	pm::clearCinCache();

	//Get encryption/decryption key from user
	std::string encryptKey;
	if (argc > 1)
	{
		encryptKey = argv[1];
	}
	else if (!pm::isKeyValid(encryptKey))
	{
		do
		{

			sayn("Encrypt Key (TIP: say \"genrandom\" to generate a random key): ");
			getline(std::cin, encryptKey);
			if (encryptKey == "genrandom")
			{
				encryptKey = pm::genRandomEncryptionKey();
				std::cout << "Encryption key set to: " << encryptKey << std::endl;
				say("Make sure to save the encryption key above as it will be used to encrypt and decrypt your passwords.");
				break;
			}

		} while (!pm::isKeyValid(encryptKey) || encryptKey.empty());

	}

	pm::loadAccounts(encryptKey);

	//Init intro message
	pm::sayIntro();

	// Start Handling Events
	pm::startHandling(encryptKey);

	return 0;
}
