struct Date {
    int year{}, month{}, day{};
    void increment_day() { ++day; }
};

int main() {
    const Date today{2026, 2, 26}; // a const object

    today.day += 1;        // error: can't modify a member of a const object
    today.increment_day(); // error: this function would modify it too
    return 0;
}
