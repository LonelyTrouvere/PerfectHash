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

		static long long EncodeString(std::string st, int p);
		static int HashFunction(std::string, int a, int b, int p, int m);
		void Insert(std::vector<std::string> list);

	private:
		int a_prime;
		int b_prime;
		int p_prime;
		int size;
		bool collisions;
		std::vector<std::string> h2;

		void NewCode();
	};

	std::vector<HashRow> h1;
	std::vector<std::vector<std::string>> rowPointer;
	int size;
	int a_prime;
	int b_prime;
	int p_prime;

	void Mapping(std::vector<std::string> v);

public:
	Hash(std::string* arr);
	Hash(std::vector<std::string> arr);
	~Hash();
};



