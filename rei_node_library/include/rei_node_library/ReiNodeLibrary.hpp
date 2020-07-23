#ifndef REI_NODE_LIBRARY__REINODELIBRARY_HPP_
#define REI_NODE_LIBRARY__REINODELIBRARY_HPP_

#include "rei_node_library/visibility_control.h"
#include "rei_node_exceptions.h"

namespace rei
{

namespace node
{

class Interface_SimpleRosNode
{
private:
public:
  Interface_SimpleRosNode();

  virtual ~Interface_SimpleRosNode() = 0;


  /**
   * DESCRIPTION:
   * Initialize node and attach to middleware in descendant methods.
   * */
  void initialization(bool debug, bool bypass_behavior);


  /**
   * REGION: Abstract initialization functions
   * */
  
  /**
   * Abstract method
   * DESCRIPTION:
   * Initialization steps before the middleware initialization.
   * 
   * RETURNS: initialization success (TRUE/FLASE)
   * */
  virtual bool initPre() = 0;
  
  /**
   * Abstract method
   * DESCRIPTION: 
   * Initialization of the behavior model based on the input specification or in a non-volatile case on a generated specific behavior.
   * 
   * RETURNS: initialization success (TRUE/FALSE)
   * */
  virtual bool initBehaviorModel() = 0;

  /**
   * Abstract method
   * DESCRIPTION:
   * Assignment of behavior actions related to the underlying behavior.
   * 
   * RETURNS: initialization success (TRUE/FALSE)
   * */
  virtual bool assignBehaviorActions() = 0;
  
  /**
   * Abstract method
   * DESCRIPTION:
   * Initialization of system and behavior guards.
   * 
   * RETURNS: initialization success (TRUE/FALSE)
   * */
  virtual bool initSysGuards() = 0;

  /**
   * Abstract method
   * DESCRIPTION: 
   * Initialziation of middleware of choice. Presumably generated based on a network model. 
   * 
   * RETURNS: initialization success (TRUE/FALSE)
   * */
  virtual bool initMiddleware() = 0;

  /**
   * Abstract method
   * DESCRIPTION:
   * Initialization class after middleware initialization.
   * 
   * RETURNS: initialization success (TRUE/FALSE)
   * */
  virtual bool initPost() = 0;

  /**
   * ENDREGION: Abstract initialization functions
   * */
};

}

}

namespace rei_node_library
{

class Reinodelibrary
{
public:
    Reinodelibrary();

    virtual ~Reinodelibrary();
};

}  // namespace rei_node_library

#endif  // REI_NODE_LIBRARY__REINODELIBRARY_HPP_
