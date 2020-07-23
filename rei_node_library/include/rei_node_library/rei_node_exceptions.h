#include <exception>

/// REGION: node initialization exception definitions

namespace rei
{

namespace node
{

class ExceptionPreInitialization: public std::exception
{

};

class ExceptionBehaviorModelInitialization: public std::exception
{

};

class ExceptionBehaviorActionAssignment: public std::exception
{

};

class ExceptionSysGuardInitialization: public std::exception
{

};

class ExceptionMiddlewareInitialization: public std::exception
{

};

class ExceptionPostInitialization: public std::exception
{

};

}

} 

/// ENDREGION: node initialization exception definitions