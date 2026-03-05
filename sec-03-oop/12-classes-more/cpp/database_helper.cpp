#include <iostream>
#include <string>

class DatabaseHelper {
private:
    std::string* connection_string;

public:
    // Constructor: Allocates memory and "opens" the connection
    DatabaseHelper(std::string path) {
        connection_string = new std::string(path);
        std::cout << "CONNECTED to: " << *connection_string << std::endl;
    }

    // Destructor: Deallocates memory and "closes" the connection
    // Identified by the tilde (~) prefix
    ~DatabaseHelper() {
        std::cout << "DISCONNECTING from: " << *connection_string << std::endl;
        delete connection_string; 
        std::cout << "Memory cleaned up successfully." << std::endl;
    }

    void query(std::string sql) {
        std::cout << "Executing: " << sql << " on " << *connection_string << std::endl;
    }
};

int main() {
    {
        // Object created inside a block (scope starts)
        DatabaseHelper db("127.0.0.1:5432/my_database");
        db.query("SELECT * FROM users;");
        
    } // <--- SCOPE ENDS HERE. 
      // The destructor is called automatically right now.

    std::cout << "The object is gone, and the connection is closed." << std::endl;
    return 0;
}