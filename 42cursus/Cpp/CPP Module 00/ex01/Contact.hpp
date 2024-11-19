#include <string>

# pragma once

class Contact
{
	public:

	void		setFirstName(std::string str);
	void		setLastName(std::string str);
	void		setNickname(std::string str);
	void		setPhone(std::string str);
	void		setSecret(std::string str);
	std::string	returnFirst(void) const;
	std::string	returnLast(void) const;
	std::string	returnNick(void) const;
	std::string	returnPhone(void) const;
	std::string	returnSecret(void) const;
	void		setValue(void);
	
	private:

	int			verifCharInput(int loop);
	std::string	firstn;
	std::string	lastn;
	std::string	nick;
	std::string	phone;
	std::string	secret;
};
