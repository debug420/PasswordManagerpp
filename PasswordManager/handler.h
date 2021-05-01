#pragma once
// Main header files
#include <iostream>
#include <string>
#include <ctype.h>

// User defined header files
#include "misc.h"
#include "encrypt.h"
#include "fileSystem.h"
#include "accountClass.h"
#include "string.h"
#include "accountList.h"

// SHA 256 LIBS
#include "picosha2.h"

// Define preprocessor statements
#define say(x) std::cout << x << std::endl;
#define sayn(x) std::cout << x;
#define div() say("================================");
#define newline() std::cout << std::endl;

namespace pm
{

	void startHandling(std::string encryptKey)
	{
		// Start handling user input commands
		do
		{
			std::string userInput;
			pm::clearCinCache();
			sayn("Enter Command: ");
			std::cin >> userInput;
			userInput = pm::lowerString(userInput);

			// Main Handle
			if (userInput == "listaccs")
			{

				pm::clearCinCache();
				div();
				say("Account List:");
				std::vector<pm::Account> list = pm::getAccounts();
				for (int i = 0, n = list.size(); i < n; i++)
				{
					div();
					say(list[i].accountName + ":");
					say("Username: " + list[i].getUser());
					say("Password: " + list[i].getPass());
				}
				div();
				say("End of list.");
				div();
				newline();

			}
			else if (userInput == "makeaccount")
			{

				pm::clearCinCache();
				div();
				say("Creating account class...");
				div();
				std::string accountName;
				std::string accountUser;
				std::string accountPass;
				pm::Account myAccount;

				do
				{
					sayn("Enter account name: ");
					getline(std::cin, accountName);
				} while (doesAccountExist(accountName));

				sayn("Enter account user: ");
				getline(std::cin, accountUser);

				sayn("Enter account pass: ");
				getline(std::cin, accountPass);

				myAccount.setPass(accountPass);
				myAccount.setUser(accountUser);
				myAccount.accountName = accountName;

				pm::saveAccount(myAccount);
				newline();

			}
			else if (userInput == "removeaccount")
			{

				pm::clearCinCache();
				div();
				sayn("Enter account name: ");
				std::string accName;
				getline(std::cin, accName);

				if (pm::doesAccountExist(accName))
				{
					pm::Account requestedAcc = getAccount(accName);
					say("Are you sure you want to remove " + requestedAcc.accountName + "? (y/n)");
					char input;
					std::cin >> input;
					if (input == 'y')
					{
						removeAccount(requestedAcc.accountName);
						say("Removed account...");
					}
					else
					{
						say("Operation cancelled.");
					}
				}
				else
				{
					say("Account doesn't exist.");
				}
				newline();

			}
			else if (userInput == "getinfo")
			{

				pm::clearCinCache();
				div();
				sayn("Enter account name to get info of: ");
				std::string accName;
				getline(std::cin, accName);

				if (pm::doesAccountExist(accName))
				{
					pm::Account requestedAcc = pm::getAccount(accName);
					say("Account Name: " + requestedAcc.accountName);
					say("Account User: " + requestedAcc.getUser());
					say("Account Pass: " + requestedAcc.getPass());
				}
				else
				{
					say("Account doesn't exist.");
				}
				newline();

			}
			else if (userInput == "editinfo")
			{

				pm::clearCinCache();
				div();
				sayn("Enter account name to edit: ");
				std::string accName;
				getline(std::cin, accName);

				if (pm::doesAccountExist(accName))
				{
					pm::Account &requestedAcc = pm::getAccountRef(accName);
					char tempInput;
					std::string tempInput2;
					say("What property of " + requestedAcc.accountName + " would you like to edit?");
					sayn("account name: n | user: u | password: p? ");
					std::cin >> tempInput;
					if (tempInput == 'n')
					{
						pm::clearCinCache();
						sayn("What would you like to change account name to? ");
						getline(std::cin, tempInput2);
						if (!tempInput2.empty())
						{
							requestedAcc.accountName = tempInput2;
							say("Applied changes.");
						}
						else
						{
							say("Invalid response. Process terminated.");
						}
					}
					else if (tempInput == 'u')
					{
						sayn("What would you like to change account user to? ");
						pm::clearCinCache();
						getline(std::cin, tempInput2);
						if (!tempInput2.empty())
						{
							requestedAcc.setUser(tempInput2);
							say("Applied changes.");
						}
						else
						{
							say("Invalid response. Process terminated.");
						}
					}
					else if (tempInput == 'p')
					{
						sayn("What would you like to change account password to? ");
						pm::clearCinCache();
						getline(std::cin, tempInput2);
						if (!tempInput2.empty())
						{
							requestedAcc.setPass(tempInput2);
							say("Applied changes.");
						}
						else
						{
							say("Invalid response. Process terminated.");
						}
					}
					else
					{
						say("Process terminated.");
					}
				}
				else
				{
					say("Account doesn't exist.");
				}
				newline();

			}
			else
			{

				pm::clearCinCache();
				say("Invalid Command.");
				newline();

			}

			pm::saveAccounts(encryptKey);

		} while (true);
	}
}
