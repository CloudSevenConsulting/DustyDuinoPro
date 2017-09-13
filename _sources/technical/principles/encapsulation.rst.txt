*********************************
Encapsulation and State Variables
*********************************

Whilst the ``C``-Programming language is not an Object-Oriented language, we
will borrow key concepts from object-orientation to ensure well controlled
state variables.

Our state variables will be global in scope (preface with the keyword ``static``).
This ensures that across all scopes (i.e. all files) every function can access
the state variables

However, to ensure we keep tight control over the state variables we will **encapsulate**
this and only expose interfaces to use them (see wikipedia_).

.. _wikipedia: https://en.wikipedia.org/wiki/Encapsulation_(computer_programming)

Key to this is our ``SystemState`` global

.. note::
   The team should consider exposing the ``SystemState`` variable to the files that
   need them, and instead require that other functions that should only have read-only rights
   to use exposing functions

In the core header:

.. code-block:: c

   /*******************************************************************************
    * STATE CONTROL
    ******************************************************************************/
   typedef struct {
       int _config_set_flag = 0;
       int *_config;
       int _sys_sleepguard = 0;
       int _sys_ready_flag = 0;
   } sys_state;

   static sys_state SystemState;

All variables that are prefaced with are underscore character are considered **private**.
Because C is not OOP, we can't strictly enforce this at compile time. We require that
developers be aware that every time they are using a variable/function with a underscore
character in-front, and that they must check they have the **rights** to the variable.

A preliminary example of exposing/encapsulating these state variables may be in the
sleep management module

.. code-block:: c

   /*******************************************************************************
    * sleep.c
    ******************************************************************************/
   #include "main.h"

   int sys_sleep(int time_milliseconds)
   {

       //Put micro-controller to sleep
       // ...
       // ...

       //System is not ready for operation
       SystemState._sys_ready_flag = 0;
       return 1
   }

   int sys_reboot(void)
   {
       //Wake the micro-controller
       // ...
       // ...

       return 1
   }

   void is_sys_ready(void)
   {
       return SystemState._sys_ready_flag;
   }

Notice that the ``is_sys_ready()`` function seems rather pointless.
However this is the function that 'exposes' the private ``_sys_ready_flag`` to
outside users. This ensures they never need to use the variable ``_sys_ready_flag``
and can determine the value of this through the **public** function ``is_sys_ready()``.

So a caller routine may look like this

.. code-block:: c

   /*******************************************************************************
    * Someone using our API
    * test.c
    ******************************************************************************/

   #include "main.h"
   #include "sleep.h"

   int main(void)
   {

       sys_sleep(1000);

       //... Wait for interrupt
       //...
       sys_reboot();
       while (is_sys_ready() != 1){} //Hold until system is ready
   }
