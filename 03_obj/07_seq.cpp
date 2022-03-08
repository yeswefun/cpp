#include <iostream>

using namespace std;

class Game {
public:
    Game() {
        cout << "Game: construct" << endl;
    }
    Game(string name) {
        cout << "Game: construct@name" << endl;
        m_name = name;
    }
    ~Game() {
        cout << "~Game: destruct" << endl;
    }
    string m_name;
};

class Phone {
public:
    Phone() {
        cout << "Phone: construct" << endl;
    }
    Phone(string name) {
        cout << "Phone: construct@name" << endl;
        m_name = name;
    }
    ~Phone() {
        cout << "~Phone: destruct" << endl;
    }
    string m_name;
};

class User {
public:
    User() {
        cout << "User: construct" << endl;
    }
    User(string name) {
        m_name = name;
    }
    User(string name, string pname, string gname): 
    	m_name(name), m_phone(pname), m_game(gname) {
        cout << "User# param-list" << endl;
    }
    ~User() {
        cout << "~User: destruct" << endl;
    }
    void show() {
        cout << m_name << '-' << m_phone.m_name << '-' << m_game.m_name << endl;
    }
    string m_name;
    Phone m_phone;
    Game m_game;
};
/*
    Phone: construct
    Game: construct
    User: construct
    Jerry-mi-cs
    ~User: destruct
    ~Game: destruct
    ~Phone: destruct
*/
void test00() {
    User u;
    u.m_name = "Jerry";
    u.m_phone.m_name = "mi";
    u.m_game.m_name = "cs";
    u.show();
}

/*
    User# param-list
    Jerry-mi-cs
    ~User: destruct
    ~Game: destruct
    ~Phone: destruct
*/
void test01() {
    User u("Jerry", "mi", "cs");
    u.show();
}

/*

*/
int main() {
    test00();
    cout << "*********************" << endl;
    test01();
    return 0;
}
