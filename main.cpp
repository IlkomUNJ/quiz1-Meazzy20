#include <iostream>
#include <string>
#include <map>

using namespace std;

// Simple user struct
struct User {
    string username;
    string password;
    string name;
    string email;
};

// Global storage for users (simulation only)
map<string, User> users;

// Function to handle registration
void handleRegister() {
    string username, password, name, email;

    cout << "=== Registration ===" << endl;
    cout << "Enter username: ";
    cin >> username;

    if (users.find(username) != users.end()) {
        cout << "❌ Username already exists. Try logging in." << endl;
        return;
    }

    cout << "Enter password: ";
    cin >> password;
    cout << "Enter full name: ";
    cin.ignore(); // clear newline
    getline(cin, name);
    cout << "Enter email: ";
    cin >> email;

    // Save user
    users[username] = {username, password, name, email};
    cout << "✅ Registration successful! You can now log in." << endl;
}

// Function to handle login
bool handleLogin(User &loggedInUser) {
    string username, password;
    cout << "=== Login ===" << endl;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    auto it = users.find(username);
    if (it != users.end() && it->second.password == password) {
        cout << "✅ Login successful! Welcome " << it->second.name << "." << endl;
        loggedInUser = it->second;
        return true;
    } else {
        cout << "❌ Invalid username or password." << endl;
        return false;
    }
}

enum PrimaryPrompt { LOGIN, REGISTER, EXIT };

int main() {
    PrimaryPrompt prompt = LOGIN;
    User currentUser;

    while (prompt != EXIT) {
        cout << "Select an option: " << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
        int choice;
        cin >> choice;
        prompt = static_cast<PrimaryPrompt>(choice - 1);

        switch (prompt) {
            case LOGIN:
                if (handleLogin(currentUser)) {
                    // Here you can later expand Buyer/Seller functionalities
                    cout << "You are now logged in as: " << currentUser.username << endl;
                }
                break;
            case REGISTER:
                handleRegister();
                break;
            case EXIT:
                cout << "Exiting." << endl;
                break;
            default:
                cout << "Invalid option." << endl;
                break;
        }
        cout << endl;
    }
    return 0;
}
