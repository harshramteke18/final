#include <iostream>
using namespace std;
 
class fps;
 
class Comparator {
public:
    void compare(const fps& a, const fps& b);
};
 
class fps {
private:
    int inch;
    int feet;
 
    friend class Comparator;
 
public:
    void intake(int inch, int feet) {
        this->inch = inch;
        this->feet = feet;
    }
 
    void display() const {
        cout << "Inches: " << inch << endl;
        cout << "Feet: " << feet << endl;
    }
};
 
void Comparator::compare(const fps& a, const fps& b) {
    if (a.feet == b.feet && a.inch == b.inch) {
        cout << "Both objects are equal." << endl;
    } else {
        cout << "Objects are not equal." << endl;
        if (a.feet != b.feet) {
            cout << "Feet differ: " << a.feet << " vs " << b.feet << endl;
        }
        if (a.inch != b.inch) {
            cout << "Inches differ: " << a.inch << " vs " << b.inch << endl;
        }
    }
}
 
int main() {
    fps obj1, obj2;
    obj1.intake(10, 5);
    obj2.intake(10, 5);
 
    Comparator comp;
    comp.compare(obj1, obj2);
 
    return 0;
}