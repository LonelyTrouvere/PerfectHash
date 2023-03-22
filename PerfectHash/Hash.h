#pragma once
#include<string>
#include<cstdlib>
#include<vector>
#include <cmath>
#include<iostream>

class Hash
{
private:
	class HashRow
	{
	public:
		HashRow();
		~HashRow();

		static long long HashFunction(std::string st, int p, int m);
		void Insert(std::string st);

	private:
		int am;
		int size;
		bool resized;
		std::vector<std::string> h2;
	};

	std::vector<HashRow> h1;
	int size;
	int a;

	void Mapping(std::vector<std::string> v);

public:
	Hash(std::string* arr);
	Hash(std::vector<std::string> arr);
	~Hash();
};



