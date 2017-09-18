********************
Network Architecture
********************

Several sensor-hosts are placed within the site to create a self-forming multi-hop mesh network that interfaces with the client users/developers through a TCP/IP network – the WSN. The sensor-hosts within the WSN are AVR-based microcontrollers (DuinoPro) with digital sensors and Dusty modules which provide communication with Linear Technology’s SmartMesh-IP network protocol. The sensor-hosts samples data, and transmits/forward the data to the network-manager – a centralised node that monitors and manages the WSN. The network manager uploads this data using the Node-RED service to the cloud infrastructure hosted by Amazon Web Services (AWS).

The sub-systems in AWS integrate with one another to perform two key tasks:
    - Parse data sent from the WSN and store it in a structured format for later querying, and
    - serve data and controls through a web-application accessible through a HTTP browser

Data storage is achieved using a NoSQL database, DynamoDB. Data sent from the WSN is directed to the DynamoDB for storage which can later be queried for analysis.

The web-application accesses the DynamoDB to process the data for analysis and visualisation. It further exposes interfaces that allow users to configure the WSN remotely. The web-application is designed with Python Django and orchestrated with Elastic Beanstalk. Orchestration in this context refers to the automatic deployment and auto-scaling of infrastructure to serve web-application to clients – this includes virtual servers for hosting the application (EC2), load balancing, and the DynamoDB interface for querying data. Additionally, Elastic Beanstalk provides a simple deployment service that allows developers to rapidly patch the web-application.

Finally, the Amazon API Gateway service provides a means of authentication and interprets and directs in/out-bound streams.

.. figure:: imgs/system_architecture_network.png

   System Architecture

Key Sub-Systems
===============

====================  =====================================================================================================
Sub-System            Function
====================  =====================================================================================================
Sensor Host           Samples data from the site; transmits and forward within the WSN mesh
Access Point (AP)     Radio bridge between WSN and Network Manager
Network Manager       Centralised node that monitors and manages mesh; TCP/IP bridge between WSN and cloud infrastructure
Amazon API Gateway    Provides authentication to the AWS infrastructure; exposes AWS interfacing API
DynamoDB              NoSQL database for storage of data from WSN
Elastic Beanstalk     AWS Orchestration service that auto-deploys and auto-scales the Python Django Web-App
Web-App               Serves data and controls to users through HTTP
====================  =====================================================================================================
