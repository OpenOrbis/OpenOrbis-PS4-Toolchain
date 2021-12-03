
#include "../../_common/log.h"
#include <stdexcept>

std::stringstream debugLogStream;

void do_throw_exception() {
	throw std::runtime_error("Catch me if you can. :p");
}

void do_throw_exception_2() {
	throw std::runtime_error("Another one.");
}

void testcase() {
	try {
		do_throw_exception();
	} catch (const std::exception& exc) {
		DEBUGLOG << "Caught! The exception says: " << exc.what();
	}
}

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);

    DEBUGLOG << "Before testcase...";
    try {
    	testcase();
		do_throw_exception_2();
	} catch (const std::exception& exc) {
		DEBUGLOG << ".what() = " << exc.what();
		DEBUGLOG << "Testcase PASS";
	}

    DEBUGLOG << "Infinite looping...";
    for (;;);
}
