#include <stdio.h>
#include <string.h>
#include <sstream>

int testLibraryFunction(char *buf, size_t buf_size, int num)
{
    std::ostringstream os;
    os << "Hi I'm from the library! You passed: " << num;
    std::string s = os.str();
    strncpy(buf, s.c_str(), buf_size);

    return 0;
}
