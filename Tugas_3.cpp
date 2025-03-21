#include <iostream>
using namespace std;

class User {
private:
    string password;
    string role;
    string email;

public:
    string username;

    User(string uname, string pass, string mail) {
        username = uname;
        password = pass;
        email = mail;
        role = "User";
        cout << "Akun '" << username << "' telah dibuat.\n";
    }

    string getRole() {
        return role;
    }

    void setRole(string newRole) {
        if (newRole == "Admin" || newRole == "User") {
            role = newRole;
            cout << "Role '" << username << "' diubah menjadi '" << newRole << "'.\n";
        } else {
            cout << "Role tidak valid!\n";
        }
    }

    void login(string pass) {
        if (pass == password) {
            cout << "Login berhasil! Selamat datang, " << username << ".\n";
        } else {
            cout << "Login gagal! Password salah.\n";
        }
    }

    ~User() {
        cout << "Akun '" << username << "' telah dihapus.\n";
    }
};

int main() {

    User user1("User", "123", "User@gmail.com");

    cout << "Username: " << user1.username << endl;
    cout << "Role: " << user1.getRole() << endl << endl;

    string role,pw;

    cout << "Masukan Role (Admin/User) : ";
    cin >> role;
    cout << "Masukan Password : ";
    cin >> pw;

    user1.setRole(role);
    user1.login(pw);

}