//============================================================================
// Name        : Final.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 * final ile bir fonksiyonun daha fazla override edilemeyeceğini
 * söylemiş oluruz. Eğer finaldan sonra alt klaslardan birinde tekrar
 * override edilmek istendiğinde compile error verir.
 * Ya da base classta virtual yapılmamışsa derived classta final kullanamayız!*/

/*
 * Base classtaki virtual metgodu override ettiğimizi belirtmek için
 * override ı kullanırız*/

#include <iostream>
using namespace std;

class A{
	virtual void func1();
	void func2();
};

class B: A{
	void func1() override; // OK: B::func1 overrides A::func1
	void func1() const override;// Error: B::func1 does not override A::func1
    							// (signature mismatch)
	void func2() override; // Error: A::func2 is not virtual
};


struct Base
{
    virtual void foo();
};

struct C : Base
{
    void foo() final; // Base::foo is overridden and C::foo is the final override
    void bar() final; // Error: bar cannot be final as it is non-virtual
};

struct D final : C // struct D is final
{
    void foo() override; // Error: foo cannot be overridden as it is final in C
};

struct E : D // Error: D is final
{
};

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
