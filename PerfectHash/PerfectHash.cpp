#include <iostream>
#include"Hash.h"

std::string gen_random(const int len) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return tmp_s;
}

int main()
{
	std::vector<std::string> v;

    for (int i = 0; i < 10; i++)
        v.push_back(gen_random(10));

	Hash h = Hash::Hash(v);

	system("pause");
}
