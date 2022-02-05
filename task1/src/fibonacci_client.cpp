#include "ros/ros.h"
#include "task1/Fibo.h"
#include <cstdlib>
 
int main(int argc, char **argv)
 {
  ros::init(argc, argv, "fibonacci_client");
   if (argc != 2)
   {
     ROS_INFO("usage: fibonacci_client X");
     return 1;
   }
 
   ros::NodeHandle n;
   ros::ServiceClient client = n.serviceClient<task1::Fibo>("fibonacci");
   task1::Fibo srv;
   srv.request.a = atoll(argv[1]);
   if (client.call(srv))
   {
     ROS_INFO("Fibonacci: %ld", (long int)srv.response.fibonacci);
   }
   else
   {
     ROS_ERROR("Failed to call service Fibo");
     return 1;
   }
  
   return 0;
  }
