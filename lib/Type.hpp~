#ifndef TYPE_H
#define TYPE_H

#include <iostream>
#include <vector>
#include <functional>

namespace __Type
{

typedef int tag_type;

const std::vector<std::string> support_types{"int", "double", "long long", "long double", "char", "string"};
constexpr tag_type None_tag = -1;
constexpr tag_type int_tag = 0;
constexpr tag_type double_tag = 1;
constexpr tag_type long_long_tag = 2;
constexpr tag_type long_double_tag = 3;
constexpr tag_type char_tag = 4;
constexpr tag_type string_tag = 5;

class TypeError {

	protected:
	std::string msg;

	public:
	TypeError(std::string __msg) : msg(__msg) {}

	// Operator for std::cerr
	friend std::ostream& operator<<(std::ostream& os, TypeError error)
	{ return (os << "[TypeError] " << error.msg << '\n'); }
};

tag_type get_tag(std::string _typename) {
	std::hash<std::string> tagger;

	auto tar_tag = tagger(_typename);

	try {
		for(int i = 0; i < support_types.size(); ++i)
			if(tar_tag == tagger(support_types[i]))
				return i;
		throw TypeError("Invalid Declaration");
	} catch(const TypeError& error) {
		std::cerr << error;
	}
}

class NoneType       {} None;
class IntType        {} Int;
class DoubleType     {} Double;
class LongLongType   {} LongLong;
class LongDoubleType {} LongDouble;
class CharType       {} Char;
class StringType     {} String;

/*
switch(this->tag) {
	case int_tag:
		break;
	case double_tag:
		break;
	case long_long_tag:
		break;
	case long_double_tag:
		break;
	case char_tag:
		break;
	case string_tag:
		break;
	default:
		throw TypeError("'None' type does not have any member function or operator");
		break;
}
*/

class Type {

	protected:
	int _int;
	double _double;
	long long _ll;
	long double _ld;
	char _char;
	std::string _str;

	tag_type tag;

	public:
	Type() : tag(None_tag) {}
	Type(const Type& type) { *this = type; }
	Type(int _v) : _int(_v), tag(int_tag) {}
	Type(double _v) : _double(_v), tag(double_tag) {}
	Type(long long _v) : _ll(_v), tag(long_long_tag) {}
	Type(long double _v) : _ld(_v), tag(long_double_tag) {}
	Type(char _v) : _char(_v), tag(char_tag) {}
	Type(std::string _v) : _str(_v), tag(string_tag) {}

	// Additional Constructor
	Type(float _v) { *this = Type((double)_v); }
	Type(unsigned int _v) { *this = Type((long long)_v); }
	Type(short _v) { *this = Type((int)_v); }
	Type(const char *_v) { *this = Type(std::string(_v)); }
	Type(NoneType _None) { *this = Type(); }
	Type(IntType _Int, int _v=int()) { *this = Type(_v); }
	Type(DoubleType _Double, double _v=double()) { *this = Type(_v); }
	Type(LongLongType _LongLong, long long _v=int()) { *this = Type(_v); }
	Type(LongDoubleType _LongDouble, long double _v=double()) { *this = Type(_v); }
	Type(CharType _Char, char _v=char()) { *this = Type(_v); }
	Type(StringType _String, std::string _v=std::string()) { *this = Type(_v); }

	// Member functions
	std::string now_type() { 
		try {
			if(tag == None_tag)
				throw TypeError("'None' type does not have any member function or operator");
			return support_types[tag]; 
		} catch(const TypeError& error) {
			std::cerr << error;
		}
	}
	int value(IntType& _Int) {
		try {
			if(this->tag != int_tag)
				throw TypeError("The type of Type is not 'int'");
			return this->_int;
		} catch(const TypeError& error) {
			std::cerr << error;
		}
	}
	double value(DoubleType& _Double) {
		try {
			if(this->tag != double_tag)
				throw TypeError("The type of Type is not 'double'");
			return this->_double;
		} catch(const TypeError& error) {
			std::cerr << error;
		}
	}
	long long value(LongLongType& _LongLong) {
		try {
			if(this->tag != long_long_tag)
				throw TypeError("The type of Type is not 'long long'");
			return this->_ll;
		} catch(const TypeError& error) {
			std::cerr << error;
		}
	}
	long double value(LongDoubleType& _LongDouble) {
		try {
			if(this->tag != long_double_tag)
				throw TypeError("The type of Type is not 'long double'");
			return this->_ld;
		} catch(const TypeError& error) {
			std::cerr << error;
		}
	}
	char value(CharType& _Char) {
		try {
			if(this->tag != char_tag)
				throw TypeError("The type of Type is not 'char'");
			return this->_char;
		} catch(const TypeError& error) {
			std::cerr << error;
		}
	}
	std::string value(StringType& _String) {
		try {
			if(this->tag != string_tag)
				throw TypeError("The type of Type is not 'string'");
			return this->_str;
		} catch(const TypeError& error) {
			std::cerr << error;
		}
	}
	unsigned int length() {
		try {
			if(this->tag != string_tag)
				throw TypeError("Only 'string' type have member function length()");
			return this->_str.length();
		} catch(const TypeError& error) {
			std::cerr << error;
		}
	}
	std::string slice(const unsigned int _begin, const unsigned int _end) {
		try {
			if(this->tag != string_tag)
				throw TypeError("Only 'string' type have member function slice()");
			return this->_str.substr(_begin, _end-_begin);
		} catch(const TypeError& error) {
			std::cerr << error;
		}
	}

	// Operator for class Type
	char operator[](const unsigned int _index) {
		try {
			if(this->tag != string_tag)
				throw TypeError("Only 'string' type have operatr[]()");
			return this->_str[_index];
		} catch(const TypeError& error) {
			std::cerr << error;
		}
	}
	Type operator+(Type type) {
		try {
			if(this->tag != type.tag)
				throw TypeError("Different type between two Types");
			switch(this->tag) {
				case int_tag:
					return this->_int + type._int;
					break;
				case double_tag:
					return this->_double + type._double;
					break;
				case long_long_tag:
					return this->_ll + type._ll;
					break;
				case long_double_tag:
					return this->_ld + type._ld;
					break;
				case char_tag:
					return this->_char + type._char;
					break;
				case string_tag:
					return this->_str + type._str;
					break;
				default:
					throw TypeError("'None' type does not have any member function or operator");
					break;
			}
		} catch(const TypeError& error) {
			std::cerr << error;
		}
	}
	Type operator-(Type type) {
		try {
			if(this->tag != type.tag)
				throw TypeError("Different type between two Types");
			switch(this->tag) {
				case int_tag:
					return this->_int - type._int;
					break;
				case double_tag:
					return this->_double - type._double;
					break;
				case long_long_tag:
					return this->_ll - type._ll;
					break;
				case long_double_tag:
					return this->_ld - type._ld;
					break;
				case char_tag:
					return this->_char - type._char;
					break;
				case string_tag:
					throw TypeError("'string' type does not have operator-()");
					break;
				default:
					throw TypeError("'None' type does not have any member function or operator");
					break;
			}
		} catch(const TypeError& error) {
			std::cerr << error;
		}
	}
	Type operator*(Type type) {
		try {
			if(this->tag != type.tag)
				throw TypeError("Different type between two Types");
			switch(this->tag) {
				case int_tag:
					return this->_int * type._int;
					break;
				case double_tag:
					return this->_double * type._double;
					break;
				case long_long_tag:
					return this->_ll * type._ll;
					break;
				case long_double_tag:
					return this->_ld * type._ld;
					break;
				case char_tag:
					return this->_char * type._char;
					break;
				case string_tag:
					throw TypeError("'string' type does not have operator*()");
					break;
				default:
					throw TypeError("'None' type does not have any member function or operator");
					break;
			}
		} catch(const TypeError& error) {
			std::cerr << error;
		}
	}
	Type operator/(Type type) {
		try {
			if(this->tag != type.tag)
				throw TypeError("Different type between two Types");
			switch(this->tag) {
				case int_tag:
					return this->_int / type._int;
					break;
				case double_tag:
					return this->_double / type._double;
					break;
				case long_long_tag:
					return this->_ll / type._ll;
					break;
				case long_double_tag:
					return this->_ld / type._ld;
					break;
				case char_tag:
					throw TypeError("'char' type does not have operator/()");
					break;
				case string_tag:
					throw TypeError("'string' type does not have operator/()");
					break;
				default:
					throw TypeError("'None' type does not have any member function or operator");
					break;
			}
		} catch(const TypeError& error) {
			std::cerr << error;
		}
	}
	Type operator+=(Type type)
	{ return (*this = operator+(type)); }
	Type operator-=(Type type)
	{ return (*this = operator-(type)); }
	Type operator*=(Type type)
	{ return (*this = operator*(type)); }
	Type operator/=(Type type)
	{ return (*this = operator/(type)); }
	Type operator++() {
		try {
			switch(this->tag) {
				case int_tag:
					++this->_int;
					break;
				case double_tag:
					++this->_double;
					break;
				case long_long_tag:
					++this->_ll;
					break;
				case long_double_tag:
					++this->_ld;
					break;
				case char_tag:
					++this->_char;
					break;
				case string_tag:
					throw TypeError("'string' type does not have operator++()");
					break;
				default:
					throw TypeError("'None' type does not have any member function or operator");
					break;
			}
			return *this;
		} catch(const TypeError& error) {
			std::cerr << error;
		}
	}
	Type operator--() {
		try {
			switch(this->tag) {
				case int_tag:
					--this->_int;
					break;
				case double_tag:
					--this->_double;
					break;
				case long_long_tag:
					--this->_ll;
					break;
				case long_double_tag:
					--this->_ld;
					break;
				case char_tag:
					--this->_char;
					break;
				case string_tag:
					throw TypeError("'string' type does not have operator++()");
					break;
				default:
					throw TypeError("'None' type does not have any member function or operator");
					break;
			}
			return *this;
		} catch(const TypeError& error) {
			std::cerr << error;
		}
	}
	Type operator++(int) { Type ret(*this); operator++(); return ret; }
	Type operator--(int) { Type ret(*this); operator--(); return ret; }

	friend std::ostream& operator<<(std::ostream& os, Type type) {
		try {
			switch(type.tag) {
				case int_tag:
					os << type._int;
					break;
				case double_tag:
					os << type._double;
					break;
				case long_long_tag:
					os << type._ll;
					break;
				case long_double_tag:
					os << type._ld;
					break;
				case char_tag:
					os << type._char;
					break;
				case string_tag:
					os << type._str;
					break;
				default:
					throw TypeError("'None' type does not have any member function or operator");
					break;
			}
		} catch(const TypeError& error) {
			std::cerr << error;
		}
		return os;
	}
	friend std::istream& operator>>(std::istream& is, Type& type) {
		try {
			switch(type.tag) {
				case int_tag:
					is >> type._int;
					break;
				case double_tag:
					is >> type._double;
					break;
				case long_long_tag:
					is >> type._ll;
					break;
				case long_double_tag:
					is >> type._ld;
					break;
				case char_tag:
					is >> type._char;
					break;
				case string_tag:
					is >> type._str;
					break;
				default:
					throw TypeError("'None' type does not have any member function or operator");
					break;
			}
		} catch(const TypeError& error) {
			std::cerr << error;
		}
		return is;
	}

#define __PICK_TAG_COMPARE_CODE(OP)  \
		try { \
			if(this->tag != type.tag) \
				throw TypeError("Different type between two Types"); \
			switch(this->tag) { \
				case int_tag: \
					return this->_int OP type._int; \
					break; \
				case double_tag: \
					return this->_double OP type._double; \
					break; \
	 			case long_long_tag: \
					return this->_ll OP type._ll; \
					break; \
				case long_double_tag: \
					return this->_ld OP type._ld; \
					break; \
				case char_tag: \
					return this->_char OP type._char; \
					break; \
				case string_tag: \
					return this->_str OP type._str; \
					break; \
				default: \
					throw TypeError("'None' type does not have any member function or operator"); \
					break; \
			} \
		} catch(const TypeError& error) { \
			std::cerr << error; \
		} 
	bool operator<(Type type) { __PICK_TAG_COMPARE_CODE(<); }
	bool operator>(Type type) { __PICK_TAG_COMPARE_CODE(>); }
	bool operator<=(Type type) { __PICK_TAG_COMPARE_CODE(<=); }
	bool operator>=(Type type) { __PICK_TAG_COMPARE_CODE(>=); }
	bool operator==(Type type) { __PICK_TAG_COMPARE_CODE(==); }
	bool operator!=(Type type) { __PICK_TAG_COMPARE_CODE(!=); }
#undef __PICK_TAG_COMPARE_CODE
};

}

#endif
