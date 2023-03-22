#include "Hash.h"
#include <cmath>
#include<iostream>

Hash::HashRow::HashRow()
{
	size = 1;
	resized = false;

	h2.resize(1);
	am = 47;
}

Hash::HashRow::~HashRow()
{
}

long long Hash::HashRow::HashFunction(std::string st, int p, int m)
{
	long long ans = 0;
	long long p_pow = 1;
	
	for (int i = 0; i < st.size(); i++)
	{
		ans = (long long)(ans + (int)st[i] * p_pow) % m;
		p_pow = (p*p_pow);
	}

	return ans;
}

void Hash::HashRow::Insert(std::string st)
{
	if (h2.size() == 1 && h2[0] == "")
		h2[0] = st;
	else
	{
		int count = sqrt(h2.size());
		h2.resize((count + 1) * (count + 1));

		if (!resized)
		{
			long long pos = HashFunction(h2[0], am, h2.size());
			std::string temp = h2[0];
			h2[0] = "";
			h2[pos] = temp;
			resized = true;
		}

			long long pos = HashFunction(st, am, h2.size());
			if (h2[pos] != "")
				std::cout << "HUI AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"<<"\n";
			else
				h2[pos] = st;
	}

}

Hash::Hash(std::string* arr)
{
	size = sizeof(arr) / sizeof(arr[0]);
	a = 31;
}

Hash::Hash(std::vector<std::string> arr)
{
	size = arr.size();
	h1.resize(size);
	a = 47;

	Mapping(arr);
}

Hash::~Hash()
{

}

void Hash::Mapping(std::vector<std::string> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		long long pos = Hash::HashRow::HashFunction(v[i], a, size);
		h1[pos].Insert(v[i]);
	}
}