#include "rei_node_library/ReiNodeLibrary.hpp"

namespace rei
{

namespace node
{

/**
 * Method implementation 
 * CLASS: Interface_SimpleRosNode
 * */

Interface_SimpleRosNode::Interface_SimpleRosNode()
{

}

// Abstract class, define virtual destructor
Interface_SimpleRosNode::~Interface_SimpleRosNode()
{}

void Interface_SimpleRosNode::initialization(bool debug, bool bypass_behavior)
{
    if (!initPre())
    {
        throw ExceptionPreInitialization();
    }
    if (!initBehaviorModel())
    {
        throw ExceptionBehaviorModelInitialization();
    }
    if (!assignBehaviorActions())
    {
        throw ExceptionBehaviorActionAssignment();
    }
    if (!initSysGuards())
    {
        throw ExceptionSysGuardInitialization();
    }
    if (!initMiddleware())
    {
        throw ExceptionMiddlewareInitialization();
    }
    if (!initPost())
    {
        throw ExceptionPostInitialization();
    }
}

/**
 * END of method implementation CLASS: Interface_SImpleRosNode
 * */


}

}