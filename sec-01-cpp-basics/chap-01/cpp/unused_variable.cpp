int main()
{
    int x { 5 }; // variable x defined

    // but not used anywhere

    return 0;
}
// Use the compiling command to see the warning
// g++ -Wall unused_variable.cpp