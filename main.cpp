#include <iostream>
#include <string>
using namespace std;

// #define is similar with constant
#define PI 3.14159

void function1() {
    std::cout << "Hello, World!" << std::endl;
    std::cerr << "Error!" << std::endl;
    std::clog << "Logging!" << std::endl;
}

void function2(){
    int a, b, sum;

    std::cin >> a;
    std::cin >> b;

    sum = a + b;
    std::cout << sum << std::endl;
}

void function_test_variable_type(){
    char myGrade = 'B';
    signed int a = 2;
    unsigned int b = 3; // can't store negative
    signed long c = 20;
    float d = 20.5;
    bool e = true;
    auto f = "string";
    auto g = false;
    auto h = 25;
    auto j = 25.5;

    int number1 = 75;         // decimal
    int number2 = 0113;        // octal
    int number3 = 0x4b;        // hexadecimal

    string mystring;
    mystring = "This is a string";

    float float1 = 3.14159; // 3.14159
    float float2 = 6.02e23; // 6.02 x 10^23
    float float3 = 1.6e-19; // 1.6 x 10^-19
    float float4 = 3.0; // 3.0

    const double pi = 3.14159; // value can't change

    std::cout << number2 << std::endl;
}

void function_test(int a, int b){
    std::cout << "int and int" << std::endl;
}

int function_test(float a, int b){
    std::cout << "int and int" << std::endl;
}

void function_by_reference(int &x, int &y) {
    int temp;
    temp = x; /* save the value at address x */
    x = y;    /* put y into x */
    y = temp; /* put x into y */

    return;
}

int main() {
    // line comment

    /* block comment
     * block comment
     */

    int a = 1;
    int b = 2;
    function_by_reference(a, b);

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    function_test(1.5, 2);

    return 0;
}