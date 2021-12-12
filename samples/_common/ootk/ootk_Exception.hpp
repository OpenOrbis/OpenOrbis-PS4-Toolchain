
#pragma once
#include <stdexcept>

namespace ootk {
    class Exception : public std::exception {
    private:
        char reason[512]{'\0'};

    public:
        Exception(const char* fmt, ...) noexcept;
        Exception(const Exception& other) noexcept = default;
        virtual const char* what() const noexcept override;
        virtual const char* What() const noexcept;
    };
}
