#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "accountClass.h"
#include "fileSystem.h"
#include "encrypt.h"
#include "string.h"

const std::string DIVIDER = "sch0kpw1i38";

std::vector<pm::Account> accountList;

namespace pm
{
	void saveAccount(pm::Account acc)
	{
		accountList.push_back(acc);
	}

	std::vector<pm::Account> getAccounts()
	{
		return accountList;
	}

	void loadAccounts(std::string key)
	{
		if (pm::fileExists("accountList.txt"))
		{
			std::string tempString;	// Dummy string to get each line
			std::ifstream AccountFile("accountList.txt");

			while (getline(AccountFile, tempString)) {
				pm::Account acc;
				std::vector<std::string> formattedData = pm::split(tempString, DIVIDER);
				acc.accountName = pm::decrypt(formattedData[0], key);
				acc.setUser(pm::decrypt(formattedData[1], key));
				acc.setPass(pm::decrypt(formattedData[2], key));
				accountList.push_back(acc);
			}

			AccountFile.close();
		}
	}

	void saveAccounts(std::string key)
	{
		pm::makeFile("accountList.txt");

		for (int i = 0, n = accountList.size(); i < n; i++)
		{
			std::string encryptName = pm::encrypt(accountList[i].accountName, key);
			std::string encryptUser = pm::encrypt(accountList[i].getUser(), key);
			std::string encryptPass = pm::encrypt(accountList[i].getPass(), key);
			pm::appendFile("accountList.txt", encryptName + DIVIDER);
			pm::appendFile("accountList.txt", encryptUser + DIVIDER);
			pm::appendFile("accountList.txt", encryptPass + DIVIDER + "\n");
		}
	}

	pm::Account getAccount(std::string name)
	{
		for (int i = 0, n = accountList.size(); i < n; i++)
		{
			if (name == accountList[i].accountName)
				return accountList[i];
		}
	}

	bool doesAccountExist(std::string name)
	{
		for (int i = 0, n = accountList.size(); i < n; i++)
		{
			if (name == accountList[i].accountName)
				return true;
		}
		return false;
	}

	void removeAccount(std::string name)
	{
		for (int i = 0, n = accountList.size(); i < n; i++)
		{
			if (name == accountList[i].accountName)
				accountList.erase(accountList.begin() + (i));
		}
	}
}