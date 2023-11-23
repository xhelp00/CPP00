#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <sstream>

class Brain
{

	protected:
				std::string *_ideas;
	public:
				Brain();
				Brain(const Brain& other);
				Brain& operator=(const Brain& other);
				~Brain();

				std::string *setIdeas();
				std::string *getIdeas() const;

};

#endif