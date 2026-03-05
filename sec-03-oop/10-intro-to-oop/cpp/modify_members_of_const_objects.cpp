struct Date
{
    int year {}, month {}, day {};

    void increment_day() {
        ++day;
    }
};

int main()
{
    const Date today { 2020, 10, 14 }; // const
    today.day += 1;        // compile error: can't modify member of const object
    today.increment_day();  // compile error: can't call member function that modifies member of const object

    return 0;
}