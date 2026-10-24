#include <iostream>
#include <string>

class DatabaseHelper {
  private:
    std::string* connection{};

  public:
    DatabaseHelper(const std::string& path)
        : connection{new std::string{path}} {
        std::cout << "Connected to " << *connection << '\n';
    }

    ~DatabaseHelper() { // called automatically: nothing to remember
        std::cout << "Disconnecting from " << *connection << '\n';
        delete connection;
    }
};

int main() {
    {
        DatabaseHelper db{"127.0.0.1:5432/my_database"};
    } // the destructor runs right here
    std::cout << "db is gone, and so is its memory\n";
    return 0;
}
