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
    // Now, the data on the memory pointed by the pointer connection_string got lost of track.
    // Memory leaked.
    

    // You may have TON OF CODE below this.
    return 0;
}