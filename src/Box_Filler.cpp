/**
 * @file RWA1Section1RajanPande.cpp
 * @author Rajan Pande (rpande@umd.edu)
 * @brief A programme to fill boxes with parts depending on the given conditions
 * @version 0.1
 * @date 2021-09-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

/**
 * @brief Function split_string() takes input string given by the user.
 * It then splits the string on the basis of whitespace and saves into a vector.
 * 
 * @param user_input 
 * @param output_vector 
 * @return true 
 * @return false 
 */

bool split_string(std::string user_input, std::vector<int> &output_vector) {
   std::string value;
   std::istringstream iss(user_input);
   while (std::getline(iss, value,' ')) {
      output_vector.push_back(std::stoi(value));
   }
   return true;
}

/**
 * @brief The functions check_boxes_input and check_ppb_input take input of the vector created of values for number of boxes
 * and maximum parts per box respectively. It then checks the validity of these inputs.
 * 
 * @param vector 
 * @return true 
 * @return false 
 */

bool check_boxes_input(std::vector<int> vector){
   bool check = true;
   for (int i = 0; i < 4; i++) {
      check = check && vector.at(i) >= 0;
   }
   return check;
}

bool check_ppb_input(std::vector<int> vector){
   bool check = true;
   for (int i = 0; i < 4; i++) {
      check = check && vector.at(i) >= 0;
      if (i < 3) {
         check = check && vector.at(i) <= vector.at(i + 1);
      }
   }
   return check;
}

/**
 * @brief The function box_filling takes input of total number parts, number of each box, maximum parts per box of each size.
 * It then calculates and gives the output of the number of remaining parts, total parts in box of each size,
 * the actual boxes of each size used.
 * 
 * @param net_parts 
 * @param boxes 
 * @param ppb 
 * @param rem_parts 
 * @param parts_in_boxes 
 * @param actual_boxes 
 * @param number_of_boxes 
 * @param z 
 * @return true 
 * @return false 
 */

bool box_filling (
   int net_parts, 
   std::vector <int>& boxes, 
   std::vector <int>& ppb, 
   std::vector<int>& rem_parts, 
   std::vector<int>& parts_in_boxes, 
   std::vector<int>& actual_boxes, 
   std::vector<int>& number_of_boxes, 
   int z
){
   int num;
   if(z == 3){
      num = net_parts;
   }
   else{
      num = rem_parts.at(2-z);
   }
   actual_boxes.push_back (num/ppb.at(z));
   if (actual_boxes.at(3-z)>boxes.at(z)){
      actual_boxes.at(3-z)=boxes.at(z);
   }
   parts_in_boxes.push_back (actual_boxes.at(3-z)*ppb.at(z));
   rem_parts.push_back (num - (parts_in_boxes.at(3-z)));
   number_of_boxes.push_back (parts_in_boxes.at(3-z)/ppb.at(z));
   return true;
}

/**
 * @brief This is a main funcition. The funcition initializes required datatypes, gets user input,
 * checks the validity of the input and implements box_filling() function
 * 
 * @return int 
 */

int main(){
   std::vector<int> rem_parts;
   std::vector<int> parts_in_boxes;
   std::vector<int> actual_boxes;
   std::vector<int> number_of_boxes;
   unsigned int net_parts;
   std::string boxes_input;
   std::string ppb_input;
   std::vector<int> ppb;
   std::vector<int> boxes;

   std::cout<<'\n'<<"Enter total number parts: ";
   std::cin>>net_parts;
   std::cout << std::endl <<"Enter total number boxes of size S/M/L/XL: ";
   std::getline(std::cin>>std::ws, boxes_input);
   std::cout << std::endl <<"Enter total number parts per box of size S/M/L/XL: ";
   std::getline(std::cin>>std::ws, ppb_input);
   
   bool convert_ppb = split_string(ppb_input, ppb);
   bool check_ppb = check_ppb_input(ppb);
   while (!check_ppb){
      ppb.clear();
      ppb_input.clear();
      std::cout << std::endl << "Invalid maximum parts per box input! Please enter again: ";        
      std::getline(std::cin>>std::ws, ppb_input);
      convert_ppb = split_string(ppb_input, ppb);
      check_ppb = check_ppb_input(ppb);
   }
    
   bool convert_boxes = split_string(boxes_input, boxes);
   bool check_boxes = check_boxes_input(boxes);
   while (!check_boxes){
      boxes.clear();
      boxes_input.clear();
      std::cout << std::endl << "Invalid number of boxes input! Please enter again: ";
      std::getline(std::cin>>std::ws, boxes_input);
      convert_boxes = split_string(boxes_input, boxes);
      check_boxes = check_boxes_input(boxes);
   }
   
   box_filling(net_parts, boxes, ppb, rem_parts, parts_in_boxes, actual_boxes, number_of_boxes, 3);
   box_filling(net_parts, boxes, ppb, rem_parts, parts_in_boxes, actual_boxes, number_of_boxes, 2);
   box_filling(net_parts, boxes, ppb, rem_parts, parts_in_boxes, actual_boxes, number_of_boxes, 1);
   box_filling(net_parts, boxes, ppb, rem_parts, parts_in_boxes, actual_boxes, number_of_boxes, 0);
   
   std::cout<<'\n'<<"Boxes that can be built with "<<net_parts<<" pegs"<<'\n';
   std::cout<<"---------------------------------------"<<'\n';
   std::cout<<"XL boxes ("<<boxes.at(3)<<" x "<<ppb.at(3)<<" max): "<<number_of_boxes.at(0)<<" used -> Parts remaining: "
   <<rem_parts.at(0)<<'\n';
   std::cout<<"L boxes ("<<boxes.at(2)<<" x "<<ppb.at(2)<<" max): "<<number_of_boxes.at(1)<<" used -> Parts remaining: "
   <<rem_parts.at(1)<<'\n';
   std::cout<<"M boxes ("<<boxes.at(1)<<" x "<<ppb.at(1)<<" max): "<<number_of_boxes.at(2)<<" used -> Parts remaining: "
   <<rem_parts.at(2)<<'\n';
   std::cout<<"S boxes ("<<boxes.at(0)<<" x "<<ppb.at(0)<<" max): "<<number_of_boxes.at(3)<<" used -> Parts remaining: "
   <<rem_parts.at(3)<<'\n';
   std::cout<<"Parts not in boxes: "<<rem_parts.at(3)<<'\n';
}