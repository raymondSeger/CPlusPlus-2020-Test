#include <iostream>
#include <array>
#include <iostream>
#include <fstream>
#include <csignal>
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
    char myGrade    = 'B';
    signed int a    = 2;
    unsigned int b  = 3; // can't store negative
    signed long c   = 20;
    float d         = 20.5;
    bool e          = true;
    auto f          = "string";
    auto g          = false;
    auto h          = 25;
    auto j          = 25.5;

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

void function_by_reference(int &x, int &y) {
    int temp;
    temp    = x; /* save the value at address x */
    x       = y;    /* put y into x */
    y       = temp; /* put x into y */
}

void test_scope(){
    int x = 10;
    int y = 20;
    {
        int x;   // ok, inner scope.
        x = 50;  // sets value to inner x
        y = 50;  // sets value to (outer) y
        cout << "inner block:\n";
        cout << "x: " << x << '\n';
        cout << "y: " << y << '\n';
    }
    cout << "outer block:\n";
    cout << "x: " << x << '\n';
    cout << "y: " << y << '\n';
}

namespace test_namespace
{
    int value() {
        return 5;
    }
    const double pi = 3.1416;
}
namespace new_namespace_name = test_namespace;

void function_array(){
    int foo [5] = { 16, 2, 77, 40, 12071 };
    int bar [5] = { 10, 20, 30 };

    array<int,3> myarray {10,20,30};
    array<int,3> myarray2 {10,20,30};

    for (int elem : bar) {
        cout << elem << '\n';
    }

    for (int elem : myarray) {
        cout << elem << '\n';
    }
}

void function_char(){
    char myword[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
    char myword2[] = "Hello";
    cout << myword << '\n';
    cout << myword2 << '\n';
}

void function_pointer(){
    /*
     * & is the address-of operator, and can be read simply as "address of"
     * * is the dereference operator, and can be read as "value pointed to by"
     */

    int myvar   = 25;
    auto foo    = &myvar;
    int bar     = myvar;

    cout << myvar << '\n';
    cout << foo << '\n';
    cout << *foo << '\n';
    cout << bar << '\n';
}

void function_struct_object(){
    struct product {
        int weight;
        double price;
    } ;

    product apple;

    struct product2 {
        int weight;
        double price;
    } the_item, the_item_2;

    apple.weight = 2;
    cout << apple.weight << '\n';

    struct name{
        char *firstName; // use * means it's dynamic instead of fixed memory size
        char *lastName;
    } name;

    struct address{
        char *street;
        int number;
    } address;

    struct person{
        struct name fullName;
        struct address fullAddress;
        int age;
    } person = {{"John", "Doe"}, {"address", 42}, 18};

    cout << person.fullName.firstName << '\n';
}

void function_type_alias(){
    typedef char C;
    typedef unsigned int WORD;
    typedef char * pChar;
    typedef char field [50];

    using C2 = char;
    using WORD2 = unsigned int;
    using pChar2 = char *;
    using field2 = char [50];

    WORD a  = 20;
    WORD2 b = 25;
    cout << a << '\n';
    cout << b << '\n';
}

void function_enum() {
    enum colors_t {black, blue, green, cyan, red, purple, yellow, white};
    enum months_t { january=1, february=2, march=3, april=4,
        may=5, june=6, july=7, august=8,
        september=9, october=10, november=11, december=12} y2k;

    enum class Colors {black, blue, green, cyan, red, purple, yellow, white};

    Colors mycolor = Colors::blue;
    if (mycolor == Colors::green) {
        cout << "green" << '\n';
    } else {
        cout << "not green" << '\n';
    }

    colors_t mycolor2 = blue;
    if (mycolor2 == green) {
        cout << "green" << '\n';
    } else {
        cout << "not green" << '\n';
    }

}

void function_exception() {
    try {
        throw 20;
    }
    catch (int e) {
        cout << "An exception occurred. Exception Nr. " << e << '\n';
    }
    catch (...) {
        cout << "default exception";
    }
}

void function_macros(){
    // pre-defined macros
    cout << "This is the line number " << __LINE__;
    cout << " of file " << __FILE__ << ".\n";
    cout << "Its compilation began " << __DATE__;
    cout << " at " << __TIME__ << ".\n";
    cout << "The compiler gives a __cplusplus value of " << __cplusplus;
}

void function_define(){
    #define TABLE_SIZE 2
    int a = TABLE_SIZE;
    #undef TABLE_SIZE
    #define TABLE_SIZE 3
    int b =TABLE_SIZE;

    cout << a << std::endl;
    cout << b << std::endl;
}

void function_write_to_file(){
    ofstream myfile;
    myfile.open ("C:/example.txt");
    myfile << "Writing this to a file.\n";
    myfile.close();
}

void function_use_class(){
    class Rectangle {

        int width, height;
    public:

        // static // need to be in it's own file
        // static int objectCount;

        // constructor
        Rectangle(int x,int y) {
            width   = x;
            height  = y;
            // objectCount++;
        }

        // destructor
        ~Rectangle () { }

        // copy
        Rectangle& operator= (const Rectangle& x) {
            return *this;
        }

        void set_values (int x,int y){
            width   = x;
            height  = y;
        };
        int area(){
            return width*height;
        };

        static int getCount() {
            // return objectCount;
        }

    };

    // Initialize static member of class Box
    // need to be in it's own file
    // int Rectangle::objectCount = 0;

    Rectangle rect(2, 4);
    rect.set_values (3,4);
    int myarea      = rect.area();
    Rectangle rect2 = Rectangle(2,2);

    cout << myarea << std::endl;
    cout << rect2.area() << std::endl;
    // cout << Rectangle::getCount() << std::endl;
}

void signalHandler( int signum ) {
    cout << "Interrupt signal (" << signum << ") received.\n";

    // cleanup and close up stuff here
    // terminate program

    exit(signum);
}

void function_signal_programming(){
    signal(SIGINT, signalHandler);

    int i = 0;
    while(++i) {
        cout << "Going to sleep...." << endl;
        if( i == 3 ) {
            raise( SIGINT);
        }
    }
}

int main() {
    // line comment

    /* block comment
     * block comment
     */

    /*
    int a = 1;
    int b = 2;
    function_by_reference(a, b);

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    */

    // test_scope();

    /*
    cout << test_namespace::value() << '\n';
    cout << new_namespace_name::pi << '\n';
    */

    // function_type_alias();

    // function_enum();

    // function_use_class();

    function_signal_programming();

    return 0;
}