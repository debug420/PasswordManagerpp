#pragma once
#include <iostream>
#include <string>
#include <vector>

namespace pm
{

	class Account {
	
	private:

		std::string accountUsername;
		std::string accountPassword;

	public:

		std::string accountName;

		std::string getUser() 
		{
			return accountUsername;
		}

		std::string getPass()
		{
			return accountPassword;
		}

		void setUser(std::string user = "username")
		{
			accountUsername = user;
		}

		void setPass(std::string pass = "password")
		{
			accountPassword = pass;
		}

		Account(std::string name = "account", std::string user = "username", std::string pass = "password")
		{
			accountName = name;
			setUser(user);
			setPass(pass);
		}

	};

}