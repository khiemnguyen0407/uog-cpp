#include <iostream>

int main()
{
    void foo() // Illegal: this function is nested inside function main()
    {
        std::cout << "foo!\n";
    }
    foo(); // function call to foo()
    // "foo" is a meaningless word that is often used 
    // as a placeholder name for a function or variable 
    // when the name is unimportant to the demonstration    
    // of some concept. 
    return 0;
}
// Note: The above code will not compile because C++ 
// does not allow nested functions.