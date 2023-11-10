#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Phonebook.class.hpp"
#include "Contact.class.hpp"


int	count(Contact contacts[8]);
void printColumn(const std::string& text);

#endif