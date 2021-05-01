#pragma once
#include <iostream>
#include <fstream>
#include <string>

namespace pm
{

	bool fileExists(std::string fileName)
	{
		std::ifstream infile(fileName);
		return infile.good();
	}

	void makeFile(std::string name, std::string content = "")
	{
		std::ofstream MyFile(name);
		MyFile << content;
		MyFile.close();
	}

	void appendFile(std::string name, std::string content = "")
	{
		std::fstream outfile;

		outfile.open(name, std::fstream::app | std::fstream::out);  

		outfile << content;

		outfile.close();
	}

	bool isFirstLogin()
	{
		return !fileExists("pass.txt");
	}

}