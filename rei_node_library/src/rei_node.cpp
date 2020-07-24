#include <rei_node_library/ReiNodeLibrary.hpp>

namespace rei
{

namespace node
{

/**
 * Method implementation 
 * CLASS: Interface_SimpleRosNode
 * */

InterfaceBehaviorNode::InterfaceBehaviorNode(): 
    control_mode(NodeControlMode::INITIALIZING)
{
    
}

// Abstract class, define virtual destructor
InterfaceBehaviorNode::~InterfaceBehaviorNode()
{}

void InterfaceBehaviorNode::initialization(bool debug, bool bypass_behavior)
{
    if (!initPre())
    {
        throw ExceptionPreInitialization();
    }
    if (!bypass_behavior)
    {
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
        control_mode = NodeControlMode::BEHAVIOR_ON;
    }
    else
    {
        control_mode = NodeControlMode::BEHAVIOR_BYPASSED;       
    }
    
    if (!initMiddleware(debug, bypass_behavior))
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