#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <cassert>

std::condition_variable g_cv;
std::mutex g_mtx;
unsigned count;
bool ready;

void test()
{
	count++;

	std::thread thd = std::thread([]() {
		count++;

		assert(count == 2);

		std::unique_lock lk(g_mtx);
		ready = true;
		lk.unlock();
		g_cv.notify_one();

		lk.lock();
		g_cv.wait(lk, []() { return !ready; });
		assert(count == 1);
	});

	std::unique_lock lk(g_mtx);
	g_cv.wait(lk, []() { return ready; });
	count--;	
	ready = false;	
	lk.unlock();
	g_cv.notify_one();

	assert(count == 1);

	thd.join();
}

int main()
{
	test();
	return 0;
}
