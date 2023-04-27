#pragma once
#include "Object.h"
#include <memory>

using std::shared_ptr;
using std::ostream;

class IShape :public Object {
public:
	virtual double area() const = 0;
	virtual double perimeter() const = 0;
	virtual string type() const = 0;
	string toString();
protected:
	virtual void doPrint(ostream&) const = 0;
	friend ostream& operator<<(ostream&, shared_ptr<IShape>);
};
