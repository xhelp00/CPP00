#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

class Contact
{

	private:

		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _darkestSecret;

	public:

	//constructor
	Contact( void );

	//destructor
	~Contact( void );

	//set method
	void setContact (std::string fn, std::string ln, std::string nn, std::string pn, std::string sec);
	
	//get methods
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickName() const;
	std::string getPhoneNumber() const;
	std::string getSecret() const;

};

#endif