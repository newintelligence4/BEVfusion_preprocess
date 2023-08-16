#include "back_lidar/back_lidar_node.hpp"
#include <time.h>
int main(int argc, char * argv[])
{
  const rclcpp::NodeOptions options;
  clock_t start = clock();
  rclcpp::init(argc, argv);
 // clock_t start = clock();
  rclcpp::spin(std::make_shared<BACK_PREPROCESSING>());
  clock_t end = clock();
  std::cerr << "Time: "<< (double)(end-start)/ CLOCKS_PER_SEC << std::endl; 
  rclcpp::shutdown();
  return 0;
}