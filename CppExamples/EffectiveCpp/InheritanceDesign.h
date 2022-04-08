#pragma once


// Inheritance Design Example
//
// 1. public inheritance design should follow 'is-a' model
// 
// public inheritance means that every base fields are applied exactly same to the derived classes
// 
// 
// 2. public inheritance designed derived class must not hide its base functions
//
// proper ways to unhide base functions
// 1) using keyword
class InheritanceDesignBase_1
{
public:
	virtual void func_1() {};
	virtual void func_2() {};

private:
	int mNum;
};

class InheritanceDesignDerived_1 : public InheritanceDesignBase_1
{
public:
	using InheritanceDesignBase_1::func_1;
	using InheritanceDesignBase_1::func_2;
};

// 2) passing function
class InheritanceDesignBase_2
{
public:
	virtual void func_1() {};
	virtual void func_2() {};

private:
	int mNum;
};

class InheritanceDesignDerived_2 : public InheritanceDesignBase_2
{
public:
	// passing functions implicitly runs as inline
	virtual void func_1()
	{
		InheritanceDesignBase_2::func_1();
	}

	virtual void func_2()
	{
		InheritanceDesignBase_2::func_2();
	}
};

// Inheritance specification with interfaces and complexes
//
// when inherits complex(virtual, non-virtual), base class inherits its every virtual and non-virtual functions
// the compiler can't catch users fault when some interfaces are not implemented.
// so there is some way of catching these faults at compile time like bellow
//
// Method) seperates interface and base implementation part
class InheritanceDesignDirection {};

class InheritanceDesignMonster
{
public:
	// interface
	virtual void attack(const InheritanceDesignDirection& target) = 0;

protected:
	// default implementation
	void defaultAttack(const InheritanceDesignDirection& target)
	{
		// attack code
	}
};

class InheritanceDesignMonsterA : public InheritanceDesignMonster
{
public: 
	virtual void attack(const InheritanceDesignDirection& target)
	{
		this->defaultAttack(target);
	}
};

// now at InheritanceDesignMonsterB, because of attack is a abstract function,
// default function does not being called implicitly.
// compiler will catch user's fault.
class InheritanceDesignMonsterB : public InheritanceDesignMonster
{
	virtual void attack(const InheritanceDesignDirection& target)
	{
		// custom attack code
	}
};

//
// Alternatives for using virtual functions
//
// there are several non-virtual function calling designs that we have to know
//
// Method 1) using NVI pattern(non-virtual interface)
// this method's main idea is that non-virtual function calls the virtual function indirectly
class InheritanceDesignCharacter
{
public:
	int healthValue() const
	{
		int returnVal = calcHealthValue();
		return returnVal;
	}

// encapsulated in private
private:
	virtual int calcHealthValue() const
	{
		return 1;
		// calculate character health value
		// derived class can override this function that is called by non-virtual interface
	}
};

// Method 2) alternate virtual function to pointer data member
// this method is one of strategy pattern
// int this method, using std::fucntion instead typedef bellow can be a another way
class InheritanceDesignCharacter2; // forward declaration

int InheritanceDesignDefaultCalcHealthValue(const InheritanceDesignCharacter2& gameCharacter) { return 1; }

class InheritanceDesignCharacter2
{
public:
	// type definition of a function for returning int, parameter for character class reference
	typedef int(*HealthCalcFunc)(const InheritanceDesignCharacter2&);

	explicit InheritanceDesignCharacter2(HealthCalcFunc hcf = InheritanceDesignDefaultCalcHealthValue) : healthCalcFunc{ hcf } {}

	int healthValue() const
	{
		return healthCalcFunc(*this);
	}

private:
	HealthCalcFunc healthCalcFunc;
};

// No default parameter setting at virtual functions
//
// virtual function is dynamically binded
// while default parameter is statically binded
//
// Wrong Example
class InheritanceDesignShape
{
public:
	enum ShapeColor { Red, Blue, Green };

	virtual void draw(ShapeColor color = Red) const = 0;
};

class InheritanceDesignRectangle : public InheritanceDesignShape
{
public:
	virtual void draw(InheritanceDesignShape::ShapeColor color = InheritanceDesignShape::ShapeColor::Red) const
	{
		// duplicated code
		// dependency exists
	};
};

// Right Example (using NVI)
class InheritanceDesignShape2
{
public:
	enum ShapeColor { Red, Blue, Green };

	void draw(ShapeColor color = ShapeColor::Red) const
	{
		doDraw(color);
	}

private:
	virtual void doDraw(ShapeColor color) const = 0;
};

class InheritanceDesignRectangle2 : public InheritanceDesignShape
{
private:
	virtual void draw(InheritanceDesignShape2::ShapeColor color) const
	{
		// implementation
	};
};

// 'has-a' relation or 'is-implemented-in-terms-of' relation is a object composition form
//
// public inheritance means : 'is-a'
// object composition means : 'has-a', 'is-implemented-in-terms-of'
// private inheritance means : 'is-implemented-in-terms-of'
// 
// normaly object composition is better than using private inheritance
//
// private inheritance example
class InheritanceDesignTimer
{
public:
	explicit InheritanceDesignTimer(int tickFrequency) {};

	virtual void onTick() const {};
};

class InheritanceDesignWidget : private InheritanceDesignTimer
{
private:
	virtual void onTick() const {};
};

// using obejct composition for same case
//
// reason 1) when restricting base class's overriding, this is a good way
// reason 2) lowers the compiler dependency
class InheritanceDesignTimer2
{
public:
	explicit InheritanceDesignTimer2(int tickFrequency) {};

	virtual void onTick() const {};
};

class InheritanceDesignWidget2
{
private:
	class WidgetTimer : public InheritanceDesignTimer2
	{
	public:
		virtual void onTick() const {};
	};

	WidgetTimer timer;
};

