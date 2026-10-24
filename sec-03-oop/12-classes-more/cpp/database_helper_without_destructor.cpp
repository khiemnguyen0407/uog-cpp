#include <iostream>
#include <string>

class DatabaseHelper {
  private:
    std::string* connection{}; // allocated on the heap

  public:
    DatabaseHelper(const std::string& path)
        : connection{new std::string{path}} {
        std::cout << "Connected to " << *connection << '\n';
    }
};

int main() {
    {
        DatabaseHelper db{"127.0.0.1:5432/my_database"};
    } // db is destroyed here... but nobody deletes *connection
    return 0;
}
