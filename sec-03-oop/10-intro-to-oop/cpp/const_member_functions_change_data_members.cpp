struct Date
{
    int year {}, month {}, day {};

    void increment_day(int val) const // made const
    {
        // day += val; // compile error: const function can't modify member
    }
};

int main()
{
    const Date today { 2020, 10, 14 }; // const

    today.increment_day(4);

    return 0;
}