#include "ros/ros.h"
#include "task1/Fibo.h"
 
long int fib(int n)
{
    int a = 0, b = 1, c, i;
    if( n == 0)
        return a;
    for(i = 2; i <= n; i++)
    {
       c = a + b;
       a = b;
       b = c;
    }
    return b;
}
bool add(task1::Fibo::Request  &req,
          task1::Fibo::Response &res)
 {
   res.fibonacci = fib(req.a) ;
   ROS_INFO("request: x=%ld", (long int)req.a);
   ROS_INFO("sending back response: [%ld]", (long int)res.fibonacci);
   return true;
 }
 
 int main(int argc, char **argv)
 {
   ros::init(argc, argv, "fibonacci_server");
   ros::NodeHandle n;
 
   ros::ServiceServer service = n.advertiseService("fibonacci", add);
   ROS_INFO("Ready to give fibonaci.");
   ros::spin();
 
   return 0;
 }

