class Solution {
public:
    class Complex{ // 复数类
    public:
        int real;
        int vitual;
        Complex(int r, int v):real(r), vitual(v){}
        Complex(){
            real = vitual = 0;
        }
        Complex(string& c){ //构造函数
            int index1 = c.find('+');
            int index2 = c.find('i');
            real = atoi(c.substr(0, index1).c_str());
            vitual = atoi(c.substr(index1+1, index2 - index1 - 1).c_str());
        }
        Complex operator * (Complex& other){ // 重载*
            int r = this->real * other.real - this->vitual * other.vitual;
            int v = this->real * other.vitual + this->vitual * other.real;
            return Complex(r, v);
        }
        string Show(){
            return to_string(real) + '+' + to_string(vitual) + 'i';
        }
    };

    string complexNumberMultiply(string num1, string num2) {
        Complex c1(num1);
        Complex c2(num2);
        Complex c3 = c1 * c2;
        return c3.Show();
    }
};