#include "Hash.h"
#include <cmath>
#include<iostream>

Hash::HashRow::HashRow()
{
	size = 4;
	collisions = false;

	h2.resize(size);
	p_prime = 47;
	a_prime = rand() % p_prime + 10;
	b_prime = rand() % (p_prime-1) + 11;
}

Hash::HashRow::~HashRow()
{
}

long long Hash::HashRow::EncodeString(std::string st, int p)
{
	long long ans = 0;
	long long p_pow = 1;
	
	for (int i = 0; i < st.size(); i++)
	{
		ans = (long long)(ans + (int)st[i] * p_pow) % (int)(1e6+7);
		p_pow = p*p_pow;
	}

	return ans;
}

int Hash::HashRow::HashFunction(std::string st, int a, int b, int p, int m)
{
	long long key = EncodeString(st, 29);

	int hash = (((a * key + b)) % p) % m;

	return hash;
}

void Hash::HashRow::NewCode()
{
	a_prime = rand() % p_prime + 10;
	b_prime = rand() % (p_prime - 1) + 11;
}

void Hash::HashRow::Insert(std::vector<std::string> list)
{
	if (list.size() == 0) {
		std::cout << "This list is empty" << '\n' << '\n';
		return;
	}

	h2.resize(list.size() * list.size());

	while (!collisions)
	{
		std::cout << a_prime << ' ' << b_prime << '\n';
		h2.assign(h2.size(), "");

		for (int i = 0; i < list.size(); i++)
		{
			int hash = HashFunction(list[i], a_prime, b_prime, p_prime, h2.size());
			if (h2[hash] == "")
			{
				h2[hash] = list[i];
				std::cout << i << ". " << list[i] << "with hash " << hash << '\n';
			}
			else
			{
				std::cout << i << ". Collision occured, new iterration" << '\n';
				NewCode();
				collisions = true;
				break;
			}
		}

		collisions = !collisions;
	}
	std::cout << '\n' << '\n';
}

Hash::Hash(std::string* arr)
{
	size = sizeof(arr) / sizeof(arr[0]);
	p_prime = 31;
	a_prime = rand() % p_prime + 10;
	b_prime = rand() % (p_prime - 1) + 11;
}

Hash::Hash(std::vector<std::string> arr)
{
	size = arr.size();
	h1.resize(size);
	rowPointer.resize(arr.size());
	p_prime = 31;
	a_prime = rand() % p_prime + 10;
	b_prime = rand() % (p_prime - 1) + 11;

	Mapping(arr);
}

Hash::~Hash()
{

}

void Hash::Mapping(std::vector<std::string> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		int hash = Hash::HashRow::HashFunction(v[i], a_prime, b_prime, p_prime, size);
		rowPointer[hash].push_back(v[i]);
	}

	for (int i = 0; i < h1.size(); i++)
		h1[i].Insert(rowPointer[i]);
}