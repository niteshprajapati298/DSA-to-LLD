#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// DIP: Dependency Inversion Principle
// High-level code depends on an abstraction, not a concrete database class.
//
// Bad example idea:
// A UserRepository directly creates a FileDatabase or MySQLDatabase inside it.
// That makes the class tightly coupled to one implementation.
//
// Example:
// class UserRepository {
// public:
//     void saveUser() {
//         FileDatabase db;
//         db.save("user", "active");
//     }
// };

class IDatabase {
public:
    virtual ~IDatabase() = default;
    virtual void save(const string& key, const string& value) = 0;
    virtual string load(const string& key) = 0;
};

class FileDatabase : public IDatabase {
public:
    void save(const string& key, const string& value) override {
        cout << "Saved to file: " << key << " -> " << value << endl;
    }

    string load(const string& key) override {
        return "Loaded from file: " + key;
    }
};

class InMemoryDatabase : public IDatabase {
private:
    unordered_map<string, string> storage;

public:
    void save(const string& key, const string& value) override {
        storage[key] = value;
        cout << "Saved to memory: " << key << " -> " << value << endl;
    }

    string load(const string& key) override {
        return storage.count(key) ? storage[key] : "Not found";
    }
};

class UserRepository {
private:
    IDatabase& database;

public:
    explicit UserRepository(IDatabase& db) : database(db) {}

    void storeUser(const string& name) {
        database.save(name, "active");
    }

    string getUser(const string& name) {
        return database.load(name);
    }
};

int main() {
    InMemoryDatabase memoryDb;
    UserRepository repository(memoryDb);

    repository.storeUser("Nitesh");
    cout << repository.getUser("Nitesh") << endl;

    return 0;
}
