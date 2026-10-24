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

    void cleanup() { // the user must remember to call this
        delete connection;
        connection = nullptr;
        std::cout << "Cleaned up\n";
    }
};

int main() {
    {
        DatabaseHelper db{"127.0.0.1:5432/my_database"};
        db.cleanup(); // forget this line, and memory leaks
    }
    return 0;
}
