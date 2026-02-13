#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <cassert>

#define RST  "\x1B[0m"
#define BOLD(x)	"\x1B[1m" x RST
#define UNDL(x)	"\x1B[4m" x RST

size_t t = 1;

int main()
{
	char s[50] = "hello, t! ";
	s[10] = t;
	std::cout << UNDL("hello, t!\n");

	return 0;
}
