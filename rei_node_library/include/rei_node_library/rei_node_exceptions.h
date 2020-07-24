#include <exception>

/// REGION: node initialization exception definitions

namespace rei
{

namespace node
{

class ExceptionPreInitialization: public std::exception
{
public:
    const char* what() const throw();
};

class ExceptionBehaviorModelInitialization: public std::exception
{
    const char* what() const throw();
};

class ExceptionBehaviorActionAssignment: public std::exception
{
    const char* what() const throw();
};

class ExceptionSysGuardInitialization: public std::exception
{
    const char* what() const throw();
};

class ExceptionMiddlewareInitialization: public std::exception
{
    const char* what() const throw();
};

class ExceptionPostInitialization: public std::exception
{
    const char* what() const throw();
};

}

} 

/// ENDREGION: node initialization exception definitions