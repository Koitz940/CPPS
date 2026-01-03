#include "Contact.hpp"

Contact::Contact(std::string s, std::string fs, std::string ns, std::string number, std::string secret)
{
	this->name = s;
	this->last = fs;
	this->nick = ns;
	this->number = number;
	this->secret = secret;
}

Contact::Contact()
{
	this->name = "";
	this->last = "";
	this->nick = "";
	this->number = "";
	this->secret = "";
}

Contact::~Contact() {}
