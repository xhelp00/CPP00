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
	Contact();

	//destructor
	~Contact();

	//set methods
	void setFirstName (std::string str);
	void setLastName (std::string str);
	void setNickName (std::string str);
	void setPhoneNumber (std::string str);
	void setSecret (std::string str);


	//get methods
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickName() const;
	std::string getPhoneNumber() const;
	std::string getSecret() const;

};

#endif