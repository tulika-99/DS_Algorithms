/******************************************************************************

Title: Character Pyramid 
Author: Anthony Tipton

The program combines user input, string manipulation, and nested loops to 
create a visual representation of a pyramid using the entered characters. 
The pattern is determined by the order in which characters are printed in each row.

*******************************************************************************/

#include <string>
#include <iostream>


void print_pryamid(const std::string& new_string){
    std::string spacing(new_string.length(), ' ');// set spacing for first line
    std::size_t print_number{0};
    
    // Start loop based on length of the string entered
    // Initialize i for how many characters to print and spaces
    for (std::size_t i=0; i < new_string.length(); ++i){
        std::cout << spacing;
        spacing.erase(0,1);
        
        // print beginning of row of characters counting up
        for (print_number=0; print_number<=i; ++print_number){
            std::cout << new_string.at(print_number);
        }
        --print_number; // reduce character position to prior to printing reverse order
        
        // print characters in reverse order
        while(print_number>0){
            --print_number;
            std::cout << new_string.at(print_number);
        }
        std::cout << std::endl;
    }
}

int main()
{
    //obtain a string from user
    std::cout << "Please enter a series of letters or numbers for your pyramid: ";
    std::string new_string{};
    std::getline(std::cin, new_string);
    std::cout << std::endl;

    //call function to print pryamid
    print_pryamid(new_string);

    return 0;
}