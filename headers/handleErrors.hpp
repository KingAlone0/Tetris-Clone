#ifndef handleErrors_HPP
#define handleErrors_HPP

#include <string>
#include "renderWindow.hpp"
#include <thread>

enum class ErrorType
{
    NotLoad,
    None
};

class Errors
{
    public:
    Errors(const &Errors) = delete;

    static ErrorType getError();

    private:
    Error() {};
    static bool hasErr;
    static std::vector<ErrorType> errors;
};

void handleErrors(ErrorType err, std::string str);

// HERE!! 
void thread_test();



#endif

