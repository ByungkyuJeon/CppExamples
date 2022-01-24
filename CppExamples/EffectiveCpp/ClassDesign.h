#pragma once

// Considerations when writing class
// 
// first, class design should be treated just like type design.
// class or struct is an custom type object
// 
// well made interface is hard to mass up with, and easy to use well.
// To prevent users' fault, 
// 1) prefer new custom types then primitives.
// 2) restrict unintended operators
// 3) design invarient and error checking routine
// 4) don't yield memory management to users
//
// 
// 1. How does the class constructs and destructs?
//
// this affects design of constructor and destructor
// if overriding memory allocating operation, also affects to them
//
// 
// 2. How are construction and assignment different for this class?
//
// affects two kinds of operators design
//
// 
// 3. When passed by value, what can be the meaning of that operation to users?
// 
// passing by value is going to implemented in copy constructor
// consider copy constructor role
// 
// 
// 4. What is the class's invarient?
//
// a class invarient design affects its error handling routine and
// all other operations and functions related to them. 
// well designed class should be formed as programmer intended.
// 
// 
// 5. Should the class match existing inheritance graph?
// 
// most important thing in this section is inheritance virtuality design.
// 
// 
// 6. Which type casts are going to be allowed?
// 
// implicit or explicit
// 
// 
// 7. What operators and fuctions are going to be needed?
// 
// designing functions and operators
// 
// 
// 8. Which standard functions are going to be restricted?
// 
// they should be declared in private section or deleted.
// 
// 
// 9. How is the member accessor going to be?
// 
// decide public, protected, private or friend
// 
// 
// 10. What are the guaranteed specifications of the class type?
// 
// there are three things that might be considered in this section.
// 1) operating performance
// 2) memory allocation (lock, dynamic allocation, etc.)
// 3) exception-safety
// 
// 
// 11. Is the class type can be one of a family types?
// 
// if yes, the class should be made as template class
// 
// 
// 12. Is the class should be made?
// 
// if just some fuctionalities are needed, just simply implmenting 
// non-member functions or template functions


// Passing constant reference is better than passing value in most of cases
//
// but not for primitive types, iterators in STL and function object
// can prevent copying problems 
// can be good for performance


// Do not return reference in function
//
// can cause various problem
// consider RVO
class Player_ClassDesign
{
public:
	Player_ClassDesign() : mNum{ 0 } {}
	Player_ClassDesign(int inNum) : mNum{ inNum } {}

	int getNum() const
	{
		return mNum;
	}

private:
	int mNum;
};

// Fault example 1
//
// never even think like this.
// too awkward fault
const Player_ClassDesign& operator+(const Player_ClassDesign& lhs, const Player_ClassDesign& rhs)
{
	Player_ClassDesign result(lhs.getNum() + rhs.getNum());
	return result;
}

// Fault example 2
//
// memory leak happens
const Player_ClassDesign& operator*(const Player_ClassDesign& lhs, const Player_ClassDesign& rhs)
{
	Player_ClassDesign* result = new Player_ClassDesign(lhs.getNum() * rhs.getNum());
	return *result;
}

// Fault example 3
//
// returning objects always points same obejcts
const Player_ClassDesign& operator/(const Player_ClassDesign& lhs, const Player_ClassDesign& rhs)
{
	static Player_ClassDesign result = Player_ClassDesign(lhs.getNum() / rhs.getNum());
	return result;
}

// Proper way
//
// RVO works
inline const Player_ClassDesign operator-(const Player_ClassDesign& lhs, const Player_ClassDesign& rhs)
{
	return Player_ClassDesign(lhs.getNum() - rhs.getNum());

	// or (also RVO works)

	Player_ClassDesign result = Player_ClassDesign(lhs.getNum() - rhs.getNum());
	return result;
}


// Use non-member and non-friend functions
//
// comparing to member function, encapsulation and package flexibility improves
//
// encapsulation : non-friend functions doesn't access directly to private members
// 
// package flexiblility : core functions nests in class, while sub functions are seperated
// int other classified namespaces or header files as library form
//
// extendability : easy to add sub functions at classified namespaces or header files


// Non-member functions can cast all kind of types to class implicitly
const Player_ClassDesign operator&(const Player_ClassDesign& lhs, const Player_ClassDesign& rhs)
{
	Player_ClassDesign result = Player_ClassDesign(lhs.getNum() & rhs.getNum());
	return result;
}

void exampleFunc_ClassDesign()
{
	Player_ClassDesign example_ClassDesign_1{ 9 };
	Player_ClassDesign example_ClassDesign_2;

	example_ClassDesign_2 = example_ClassDesign_1 & 1; // casting works for both functions
	example_ClassDesign_2 = 1 & example_ClassDesign_1; // casting works only when non-member function
} 