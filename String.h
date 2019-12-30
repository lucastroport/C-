#ifndef STRING_H
#define STRING_H
#include <iostream>
using namespace std;
	
	
class String{
	// Input and output stream
	friend ostream &operator<<(ostream&, const String &);
	friend istream &operator>>(istream&, String &);
public:
	
    // Constructor by defaut
	String();

	// The constructor receives a string terminated by \0; 
	// also it receives a variable that indicates if it is caseSensitive or not 
	// (by default case-insensitive)
	String(const char *s, bool ignoreCase = false);

	// Destructor
	virtual ~String();

	// copy constructor
	String(const String &c);
	
	// assignment operator
	String &operator=(const String &c);
	
	// sum operator
	String operator+(const String &c);
	// concat operator
	String operator+=(const String &c);
	/*Comparation operators */
	bool operator==(const String &c);
	bool operator!=(const String &c);
	bool operator<(const String &c);
    bool operator>(const String &c);
    bool operator<=(const String &c);
	bool operator>=(const String &c);
	
	// Returns a new char* but without sharing memory.
	char *GetNewCharPtr() const;

	// Returns the length of the string 
	unsigned int Length() const;

	/*// Returns true if the the string contains substr
	bool Contains(const String &substr) const;
	*/
	// PRE: index < Largo()
	// Returns the character at the given index
	char operator[] (const unsigned int index);
		
	//Compares the string with s. The result is positive if the first string is lexicographically greater 
	//than the second string else the result would be negative.
	int CompareTo(String s);

	//Returns true if the string is empty
	bool IsEmpty() const;
	//Converts the string to upper case
	String ToUpperCase();
	//Converts the string to lowercase
	String ToLowerCase();
	//Returns true if the string contains substr.
	bool Contains(const String &substr) const;

	
    private :
        char* str;
        bool ignoreCase;
		int lengthAuxConst(const char* str)const;
		char* copyStr(const char * s);	
			
};
#endif