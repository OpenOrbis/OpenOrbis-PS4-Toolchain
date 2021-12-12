#include "ootk_Exception.hpp"

#include <cstdarg>
#include <cstdio>
#include <cstring>

ootk::Exception::Exception(const char* fmt, ...) noexcept {
    va_list args;
    va_start(args, fmt);
    std::vsnprintf(reason, sizeof(reason), fmt, args);
    va_end(args);

    // null terminate the string just in case...
    reason[sizeof(reason) - 1] = '\0';
}

const char* ootk::Exception::what() const noexcept {
    return reason;
}

const char* ootk::Exception::What() const noexcept {
    return what();
}
