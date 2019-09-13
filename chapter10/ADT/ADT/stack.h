#ifndef STACK_H_
#define STACK_H_

typedef unsigned long Item;
class stack{
private:
	enum{MAX=10};
	Item items[MAX];
	int top;
public:
	stack();
	//~stack();
	bool isempty()const;
	bool isfull() const;
	bool push(const Item& item);
	bool pop(Item &item);
};
#endif