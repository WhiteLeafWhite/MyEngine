#pragma once
enum class ComponentType:int {
	COMPONENT = 0,
	RENDERER = 1,
	COLLIDER = 2,
	RIGIDBODY = 3,
	SCRIPT = 4
};
class Component
{
protected:
	
public:
	bool active;
	ComponentType comtype;
	Component();
	bool Isactive();
	virtual void dosomething();
	void disable();
	void enable();
	bool operator == ( const Component &b) const{
		return comtype == b.comtype;
	}
	bool operator> (const Component& b) const {
		return comtype > b.comtype;
	}
	bool operator< (const Component& b) const {
		return comtype < b.comtype;
	}
};

