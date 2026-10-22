struct Date {
    int year{}, month{}, day{};
    void increment_day(int days) const { // made const...
        day += days; // error: ...so it can't change a member
    }
};

int main() {
    Date today{2026, 2, 26};
    today.increment_day(4);
    return 0;
}
