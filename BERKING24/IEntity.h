//The file was written by Haponenko Vladislav 16.11.2019
#pragma once
#include <iostream>
class IEntity
{
	///
	///The class is corresponding for a common representation of an objects are ment 
	//to be stored in a data base
	//
	//From the description of a class, all stored objects must have an operator <<
public:
	IEntity() {};
	virtual ~IEntity() {};


	///
	///Is ment to be used in operator<<
	///thus it views a text representation of an object
	///
	///@param out The parameter os is an output stream
	///
	///@param b The parameter is an object for outputing 
	///
	///@return an output stream with a text representation of an object
	friend std::ostream& operator<<(std::ostream& out, const IEntity& b)
	{
		b.do_print(out);
		return out;
	}
private:
	virtual std::ostream& do_print(std::ostream&) const = 0;

};
