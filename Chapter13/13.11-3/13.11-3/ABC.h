//头文件
#ifndef ABC_H_
#define ABC_H_

#include <iostream>

//抽象基类
class ABC
{
private:
	char * label;
	//char *需要深度复制，string类不需要 
	int rating;
public:
	ABC(const char * l = "null", int r = 0);
	ABC(const ABC & rs);
	ABC & operator=(const ABC & rs);

	virtual ~ABC();
	virtual void View() = 0;
	friend std::ostream& operator<<(std::ostream& os, const ABC& rs);
	char * getLabel(){ return label; }
	int getRating(){ return rating; }
};

class baseDMA : public ABC
{
public:
	baseDMA(const char * l = "null", int r = 0);
	baseDMA(const baseDMA & rs);
	virtual void View();
};

class lacksDMA : public ABC
{
private:
	enum { COL_LEN = 40 };
	char color[COL_LEN];
public:
	lacksDMA(const char * c = "blank", const char * l = "null", int r = 0);
	lacksDMA(const char * c, const ABC & rs);

	friend std::ostream& operator<<(std::ostream& os, const lacksDMA& ls);
	virtual void View();
};

class hasDMA : public ABC
{
private:
	char * style;
public:
	hasDMA(const char * s = "none", const char * l = "null", int r = 0);
	hasDMA(const char * s, const ABC & rs);
	hasDMA(const hasDMA & hs);
	~hasDMA();

	hasDMA & operator=(const hasDMA & hs);
	friend std::ostream& operator<<(std::ostream& os, const hasDMA& hs);
	virtual void View();
};

#endif