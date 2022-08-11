
#include "CMakeProject1.h"

#pragma comment(lib, "ws2_32.lib")



int main() {
	buf.clear();

	thread thread1([&]() {
		while (true) {
			func1();
		}
		});

	thread thread2([&]() {
		while (true) {
			func2();
		}
		});

	thread1.join();
	thread2.join();

	return 0;
}