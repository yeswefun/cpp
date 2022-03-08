#include <iostream>

using namespace std;

class Cubic {
public:
    void setL(int l) {
        m_l = l;
    }
    int getL() {
        return m_l;
    }
    void setW(int w) {
        m_w = w;
    }
    int getW() {
        return m_w;
    }
    void setH(int h) {
        m_h = h;
    }
    int getH() {
        return m_h;
    }
    void showCubicS() {
        cout << "S: " << 2 * (m_l * m_w + m_l * m_h + m_w * m_h) << endl;
    }
	void showCubicV() {
        cout << "V: " << m_l * m_w * m_h << endl;
    }

    bool compare(const Cubic &o) {
        return m_l == o.m_l && m_w == o.m_w && m_h == o.m_h;
    }
    // const 限制对成员属性进行修改
    string ping() const {
        //不允许调用其它方法
        return "pong";
    }
private:
    int m_l;
    int m_w;
    int m_h;
};

// const -> public field -> 可以读取对象属性
/*bool compare2(const Cubic &c1, const Cubic &c2) {
    return c1.m_l == c2.m_l && c1.m_w == c2.m_w && c1.m_h == c2.m_h;
}*/

// const -> public method -> 方法中可能会有修改对象属性的行为
bool compare(Cubic &c1, Cubic &c2) {
    return c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH();
}

int main() {
    Cubic c1;
    c1.setL(10);
    c1.setW(20);
    c1.setH(30);
    c1.showCubicS();
    c1.showCubicV();

    Cubic c2;
    c2.setL(10);
    c2.setW(20);
    c2.setH(30);
    c2.showCubicS();
    c2.showCubicV();
    
    // 1 - true, 0 - false
    cout << compare(c1, c2) << endl;
    cout << c1.compare(c2) << endl;

    // test const
    cout << c1.ping() << endl;

    return 0;
}
