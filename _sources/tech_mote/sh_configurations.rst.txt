**************************
Sensor Host Configurations
**************************

Background
==========
Sensor hosts are configurable remotely without the need to recompile/rebuild.
This is a crucial requirement in order to minimize maintenance costs. As these
devices are expected to be on-site for several months, it is unfeasible to
send technicians on site to configure certain settings. As such the need for
configuration parameters that are checked and used at run time was proposed.

Configuration Lookup
====================

The configuration lookup is stored in non-volatile memory on all devices on the
network. It must be the same across all devices for the WSN to be functional.

The lookup informs the devices the:

        - Index (unique ID) for a parameter
        - The allowable range of the parameter value (min and max)
        - The resolution of the parameter value (number of bytes)
        - The default value of the parameter value

.. note::

   The option to introduce/remove configuration parameters is not provided at
   run time and **must** be done on builds.

Device Configuration
====================

Device configuration is stored in volatile memory; functions that require
configurable parameters will only look in the stored state variable (i.e.
volatile memory) for the parameter value.

Device configuration is loaded/updated into volatile memory in two cases:

        - On start-up
        - By network manager command

On Start-Up
-----------
On start-up, the sensor host uses all the default values in the configuration lookup
and stores those values in volatile memory.

Once this is done, the state variable `_config_set_flag` is set to indicate
that configurations are ready

By Network Manager
------------------

The network manager can either:

        - Broadcast a single configuration to all sensor host
        - Individually configure sensor host

In both cases, the sensor host receives this command and internally runs a routine
to update the configuration as specified by the network manager

Parameters
==========

=======================================  =================================================================================================
Parameter                                Description
=======================================  =================================================================================================
``log_level``                            Logging level/granularity
``sampling_period_diagnostic``           The sampling period for diagnostic data
``sampling_period_sensor``               The sampling period for sensor data
``sleep_overhead_time``                  A safety-factor to prevent the system from over-sleeping and missing the required sampling time
``network_join_duty_cycle_init``         The initial duty cycle value when the sensor host joins the WSN
``network_join_wait_time_init``          The initial wait time before the sensor host will reattempt to join the WSN
``network_join_wait_time_increment``     The extra amount of time to wait after every attempt of failed joining
``network_join_wait_max``                The maximum waiting time for attempting to join
``network_join_duty_cycle_decrement``    The amount to decrease the duty cycle for every reattempt
``sensor_comm_type``                     The communication protocol used for communicating with the sensor
``sensor_clk_speed``                     The communication speed for the sensor protocol
=======================================  =================================================================================================

Implementation
==============


