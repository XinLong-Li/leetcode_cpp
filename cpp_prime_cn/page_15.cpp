#include <iostream>
int main(){
    int sum = 0;
    int value = 0;
    std::cout << "Please input a series of integers:" << std::endl;
    while (std::cin >> value)
    {
        sum += value;
    }
    std::cout << "Sum is: " << sum << std::endl;
    return 0;
}