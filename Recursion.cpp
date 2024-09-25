#include <iostream>
using namespace std; 

class NumberGenerator {
public:

    NumberGenerator(int digits) : n(digits) {}

    void generate() {

        for (char firstDigit = '1'; firstDigit <= '9'; ++firstDigit) {
            string current(1, firstDigit);
            generateNumbers(current);
        }
    }

private:
    int n;

    void generateNumbers(string current) {
        if (current.length() == n) {
            if (current.front() != current.back()) {
                cout << current << endl;
            }
            return;
        }

        char lastDigit = current.back();

        for (char digit = '0'; digit <= '9'; ++digit) {
            if (digit != lastDigit) {
                generateNumbers(current + digit);
            }
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of digits (n): ";
    cin >> n;
    NumberGenerator generator(n);
    generator.generate();

    return 0;
}
