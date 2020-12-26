/* IntroStructs.cpp : Introductions to use object oriented programming 
*  Date: 26/12/2020
*  Author: Bruno C. Messias
*/
#include <iostream>
#include <string>
#include <vector>

//struct User //! In structs by the default the value is public
//{
//	std::string first_name;
//	std::string last_name;
//	std::string get_status() { return status; }
//	private:
//		std::string status = "all";//default value
//};
class User //In classes by default the value is private
{
	std::string status = "all"; // default value

public:
	std::string first_name;
	std::string last_name;
	User() { std::cout << "New User\n"; }
	User(std::string first_name, std::string last_name)
	{
		std::cout << "New User\n";
		this->first_name = first_name;
		this->last_name = last_name;
	}
	std::string get_status() { return status; }

	~User() { std::cout << "Destructor\n"; }
};


int main()
{
	User me;
	me.first_name = "first";
	me.last_name = "last";
	//me.status = "all";//Can't acessed need a return value need a get


	std::cout << "First Name: " << me.first_name << std::endl;
	std::cout << "Status: " << me.get_status() << std::endl;

	//User user;
	//user.first_name = "Me";

	//std::vector<User> users;
	////users.push_back(user);

	//std::cout << "\n" << users[0].first_name << std::endl;

	User new_user("me", "today");

	std::cout << new_user.first_name << " " << new_user.last_name << std::endl;

	return 0;
}











