#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<thread>

static bool s_finshed = false;

void do_work() {

	using namespace std::literals::chrono_literals;
	
	std::cout << "Started thread id = " << std::this_thread::get_id() << std::endl;

	while (!s_finshed) {
		std::cout << "working...\n";
		std::this_thread::sleep_for(1s);
	}
}

int main()
{
	std::thread worker(do_work);

	std::cin.get();
	s_finshed = true;

	worker.join();
	std::cout << "finshed." << std::endl;
	std::cout << "Started thread id = " << std::this_thread::get_id() << std::endl;

	std::cin.get();

	return 0;
}