#include "String.h"
#ifndef STRING_CPP
#define STRING_CPP


ostream &operator<<(ostream &os, const String &string){
	if(string.str != NULL)
		os << string.str;
	return os;
}

istream &operator>>(istream &is, String &s){
	char aux[200];
	is>>aux;
	s = aux;
	return is;
}

String::String(){
    this->str = new char[1];
    this->str[0] = '\0';
    this->ignoreCase = true;
}

String::~String(){
    if(this->str != NULL) delete [] this->str;
}

String::String(const char *s,bool ignoreCase){
  
	this->str = this->copyStr(s);
	this->ignoreCase = ignoreCase;
}

String::String(const String &c) {
	this->str = NULL;
	*this = c;
}
/*OPERATORS*/
//= OPERATOR
String &String::operator=(const String &c){
    if(this != &c) {
		delete [] this->str;
		this->str = c.GetNewCharPtr();
		this->ignoreCase = c.ignoreCase;
	}
	return *this;
	
}
//+= OPERATOR
String String ::operator+=(const String &c) {
	const char *oldString = this->str == NULL ? "" : this->str;
    int newSize = this->Length() + c.Length() + 1; 	
    char *newString = new char[newSize];

   	strcpy(newString, oldString);
	strcat(newString, c.str);

	delete [] this->str;
	this->str = newString;

	return *this;
}
//+ OPERATOR
String String::operator+(const String &c) {

	String answer;
    answer += *this;
    answer += c;
    return answer;
}
//== OPERATOR
bool String::operator==(const String &c){
	if (!ignoreCase) return this->CompareTo(c) == 0;
	else {
		String aux = c;
		return this->CompareTo(aux.ToUpperCase()) == 0;
	}
	
}

//!= OPERATOR
bool String::operator!=(const String &c){
	if(!ignoreCase) return this->CompareTo(c) != 0;
	else {
		String aux = c;
		return this->CompareTo(aux.ToUpperCase()) != 0;
	}
}

//< OPERATOR
bool String::operator<(const String &c) {
	if (!ignoreCase) return strcmp(this->str, c.str) < 0;
	else {
		String aux = c;
		return this->CompareTo(aux.ToUpperCase()) < 0;
	}
}

//> OPERATOR
bool String::operator>(const String &c) {
	if (!ignoreCase) return strcmp(this->str, c.str) > 0;
	else {
		String aux = c;
		return this->CompareTo(aux.ToUpperCase()) > 0;
	}
}

//<= OPERATOR
bool String::operator<=(const String &c) {
	if (!ignoreCase) return strcmp(this->str, c.str) <= 0;
	else {
		String aux = c;
		return this->CompareTo(aux.ToUpperCase()) <= 0;
	}
}

//>= OPERATOR
bool String::operator>=(const String &c) {
	if (!ignoreCase) return strcmp(this->str, c.str) >= 0;
	else {
		String aux = c;
		return this->CompareTo(aux.ToUpperCase()) >= 0;
	}
}
//[] OPERATOR
char String::operator[] (const unsigned int index)
{
	return this->str[index];
}
//Returns the size of the String
unsigned int String::Length()const {
		return lengthAuxConst(this->str);
}
//Returns a char* of the string itself.
char* String::GetNewCharPtr() const{
	int largoVec = this->Length();
	char* ret = new char[largoVec+1];
	for (int i = 0; i <= largoVec; i++) {
		ret[i] = str[i];
	}
	return ret;
}

int String::lengthAuxConst(const char* str)const {
		const char* aux = str;
		int n = 0;
		while (*aux != '\0') {
			n++;
			aux++;
		}
		return n;
}

int String::CompareTo(String s){
	int i = 0;
	int j = 0;
	String tmp = (*this);
	
	if (this->ignoreCase) tmp.ToUpperCase();//in case we have to ignore the case.

	while (tmp[i] != '\0' && s[i] != '\0') {
		if (tmp[i] != s[i]) return tmp[i] - s[j];
		i++;
		j++;
	}
	return tmp[i] - s[j];

}

bool String::IsEmpty() const{
	return this->Length() == 0;
}

String String::ToUpperCase(){
	const char *oldString = this->str == NULL ? "" : this->str;
	char *newString = this->copyStr(oldString);

	int i = 0;
	if(!this->IsEmpty()){
		while(i < this->Length()){
			newString[i] = toupper(oldString[i]);
			i++;
		}
	}
	delete [] this->str;
	this->str = newString;
	return *this;
	
}

String String::ToLowerCase(){
	const char *oldString = this->str == NULL ? "" : this->str;
	char *newString = this->copyStr(oldString);

	int i = 0;
	if(!this->IsEmpty()){
		while(i < this->Length()){
			newString[i] = tolower(oldString[i]);
			i++;
		}
	}
	delete [] this->str;
	this->str = newString;
	return *this;

}

char *String::copyStr(const char* s){
	int largoVec = lengthAuxConst(s);
	char* ret = new char[largoVec+1];
	for (int i = 0; i <= largoVec; i++) {
		ret[i] = s[i];
	}
	return ret;
}

bool String::Contains(const String &substr) const {

	if(substr.IsEmpty()) return true;

	char* s2 = substr.str;
	unsigned int j, j2;
	int sizeS1 = lengthAuxConst(this->str);
	int sizeS2 = lengthAuxConst(substr.str);

	if(!this->ignoreCase){
		for (unsigned int i = 0; i < sizeS1; i++){
			if (sizeS2 + i > sizeS1 + 1) return false;
			if(this->str[i] == s2[0]){
				j = i;
				j2 = 0;
				while(j2 < sizeS2 && this->str[j] == s2[j2]){
					j++;
					j2++;
				}
				if(j2 == sizeS2) return true;
			}
		}
	}else {
		for (unsigned int i = 0; i < sizeS1; i++){
			if (sizeS2 + i > sizeS1 + 1) return false;
			if(toupper(this->str[i]) == toupper(s2[0])){
				j = i;
				j2 = 0;
				while(j2 < sizeS2 && this->str[j] == s2[j2]){
					j++;
					j2++;
				}
				if(j2 == sizeS2) return true;
			}
		}
	}
	return false;
}
#endif