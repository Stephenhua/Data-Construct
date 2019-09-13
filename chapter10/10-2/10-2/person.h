#ifndef PERSON_H_
#define PERSON_H_
class Person{
private:
	static const int Limits = 25;
	std::string lname;
	char fname[Limits];
public:
	Person(){ lname = ""; fname[0] = '\0'; }
	Person(const std::string& ln, const char *fn = "Hell0" );
	void Show() const;
	void Formshow() const;
};

#endif