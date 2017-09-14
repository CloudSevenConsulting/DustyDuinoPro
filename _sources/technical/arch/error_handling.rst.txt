**************
Error Handling
**************

=================  =============================================================================================  ==========================================================
Level              System Usability                                                                               Response
=================  =============================================================================================  ==========================================================
``CRITICAL``       System can no longer operate; attempts of recovery will cause meta-stability                   Report to Network Manager and go to sleep
``ERROR_MAJOR``    Intermittent critical-error, or bug in code; caused a system reset, but working after reset    Report to Network Manager and Continue from system reset
``ERROR_MINOR``    Issue in code causing data to be collected to be incorrect                                     Report to NM and revert to default if possible
``WARNING``        Potential Flags                                                                                Log
``INFO``           System Events (Business-as-Usual)                                                              Log if requested to
``DEBUG``          Verbose output                                                                                 Log if requested to
=================  =============================================================================================  ==========================================================
