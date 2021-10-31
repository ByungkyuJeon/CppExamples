

#include <iostream>

#include "ClassMemorysize.cpp"

int main()
{
    SizeExampleClass_2 stackCharacter;
     
    std::cout << stackCharacter.GetSize() << std::endl;
}