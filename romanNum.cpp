#include <iostream>
//#include <romanImp.cpp>

using namespace std;

class romanType {
    public:
        string romanNum;
        int sum = 0;

        string getValue() { //Store the number as a Roman numeral
            string romanNum;
            cout << "Enter your number: ";
            cin >> romanNum;
            return romanNum;
        }

        romanType() {
            romanNum = getValue();

            //Convert and store the number as a positive integer
            int values[romanNum.length()] = {};
            for (int i = 0; i < romanNum.length(); i++) {
                if (toupper(romanNum[i]) == 'M') {
                    values[i] = 1000;
                }
                if (toupper(romanNum[i]) == 'D') {
                    values[i] = 500;
                }
                if (toupper(romanNum[i]) == 'C') {
                    values[i] = 100;
                }
                if (toupper(romanNum[i]) == 'L') {
                    values[i] = 50;
                }
                if (toupper(romanNum[i]) == 'X') {
                    values[i] = 10;
                }
                if (toupper(romanNum[i]) == 'V') {
                    values[i] = 5;
                }
                if (toupper(romanNum[i]) == 'I') {
                    values[i] = 1;
                }
            }

            //Print as an integer
            for (int i = 1; i < romanNum.length(); ++i) {
                if (values[i-1] >= values[i]) {
                    sum = sum + values[i-1];
                    if (i == romanNum.length()-1) {
                        sum = sum + values[i];
                    } 
                }
                if (values[i-1] < values[i]) {
                    sum = sum + (values[i] - values[i-1]);
                    i++;
                }
            }
            cout << sum;
        }
};

int main() {
    romanType myObj;
    //Test values: MCXIV, CCCLIX, MDCLXVI
    return 0;
}
