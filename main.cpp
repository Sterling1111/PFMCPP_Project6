/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference and don't change the return type either.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.

 2) revise the 'else' statement in main() that handles when `smaller` is a nullptr. 
 there is only one reason for `compare` to return nullptr. 
 Update this std::cout expression to specify why nullptr was returned.
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    int value;
    std::string name;

    T(int v, const char* n) : value{v}, name{n} {}
};

struct Comparator                                //4
{
    T* compare(T* a, T* b) //5
    {
        if(a == nullptr or b == nullptr or a->value == b->value) return nullptr;
        if( a->value < b->value ) return a;
        return b;
    }
};

struct U
{
    float value1 { 0 }, value2 { 0 };

    float update(float* updatedValue)      //12
    {
        if(updatedValue == nullptr) return 0.0f;
        std::cout << "U's value1 value: " << value1 << std::endl;
        value1 = *updatedValue;
        std::cout << "U's value1 updated value: " << value1 << std::endl;
        while( std::abs(value2 - value1) > 0.001f )
        {
            value2 += (value2 < value1 ? .0005f : -.0005f);
        }
        std::cout << "U's value1 updated value: " << value2 << std::endl;
        return value2 * value1;
    }
};

struct T2
{
    static float update(U* that, float* updatedValue )        //10
    {
        if(that == nullptr or updatedValue == nullptr) return 0.0f;
        std::cout << "U's value1 value: " << that->value1 << std::endl;
        that->value1 = *updatedValue;
        std::cout << "U's value1 updated value: " << that->value1 << std::endl;
        while( std::abs(that->value2 - that->value1) > 0.001f )
        {
            that->value2 += (that->value2 < that->value1 ? .0005f : -.0005f);
        }
        std::cout << "U's value1 updated value: " << that->value2 << std::endl;
        return that->value2 * that->value1;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T t1(1, "t1");                                             //6
    T t2(2, "t2");                                             //6
    
    Comparator f;                                            //7
    auto* smaller = f.compare(&t1, &t2);                              //8
    if(smaller == nullptr)
    {
        std::cout << "f.compare() returned nullptr because values are equal or one of the pointers is nullptr." << std::endl;
    }
    else 
    {
        std::cout << "the smaller one is " << smaller->name << std::endl; //9
    }
    
    
    U u1;
    float updateValue = 5.f;
    std::cout << "update u1's multiplied values: " << T2::update(&u1, &updateValue) << std::endl;                  //11
    
    U u2;
    std::cout << "update u2's multiplied values: " << u2.update( &updateValue ) << std::endl;
}
