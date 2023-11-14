#ifndef HARL_CLASS_HPP
#define HARL_CLASS_HPP

# include <string>

class Harl {

	private:
				void debug( void );
				void info( void );
				void warning( void );
				void error( void );

	public:
				Harl();
				~Harl();
				void complain( std::string level );
				int	getLevel(std::string level);

};
typedef void (Harl::*function_p)(void);
#endif