#include "Contact.hpp"

Contact::Contact(std::string s, std::string fs, std::string ns)
{
	name = s;
	last = fs;
	nick = ns;
}

Contact::Contact()
{
	name = "";
	last = "";
	nick = "";
}

Contact::~Contact() {}