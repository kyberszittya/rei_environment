#include <rei_node_library/rei_node_exceptions.h>



namespace rei
{
namespace node
{
/// REGION: exception return messages
const char* ExceptionPreInitialization::what() const throw()
{
    return "Pre-middleware initialization failed";
}

const char* ExceptionBehaviorModelInitialization::what() const throw()
{
    return "Behavior model initialization failed";
}

const char* ExceptionBehaviorActionAssignment::what() const throw()
{
    return "Behavior action assignments failed";
}

const char* ExceptionSysGuardInitialization::what() const throw()
{
    return "System guard initialization failed";
}

const char* ExceptionMiddlewareInitialization::what() const throw()
{
    return "Middleware initialization failed";
}

const char* ExceptionPostInitialization::what() const throw()
{
    return "Post-middleware initialization failed";
}
/// ENDREGION: exception return messages
}
}