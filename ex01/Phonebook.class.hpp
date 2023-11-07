#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "Contact.class.hpp"

class Phonebook
{

	private:

		Contact _contacts[8];
		int _index;

	public:
	
		Phonebook( void );
		~Phonebook( void );
		Contact getContact(int index);
				
		//add
		//search
};

#endif