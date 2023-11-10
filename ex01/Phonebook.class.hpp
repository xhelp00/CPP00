#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "Contact.class.hpp"

class Phonebook
{

	private:
		Contact _contacts[8];
		int _index;

	public:
		Phonebook();
		~Phonebook();
		//add
		void add();
		//search
		void search();
		//print
		void print(Contact contact);
};

#endif