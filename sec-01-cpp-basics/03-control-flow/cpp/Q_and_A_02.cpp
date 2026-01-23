#include <iostream>
int main()
{
    int count{ 0 }; // count how many times the loop iterates
    bool keep_looping { true }; // controls whether the loop ends or not
    while (keep_looping)
    {
        std::cout << "Enter 'e' to exit this loop or any other character to continue: ";
        char ch{};
        std::cin >> ch;

        if (ch == 'e')
            keep_looping = false;
        else {
            ++count;
            std::cout << "We've iterated " << count << " times\n";
        }
    }
    return 0;
}