/* IntroStructs.cpp : Introductions to use object oriented programming 
*  Date: 26/12/2020
*  Author: Bruno C. Messias
*/
#include <iostream>
#include <string>
#include <vector>
#include "User.h"

//struct User //! In structs by the default the value is public
//{
//	std::string first_name;
//	std::string last_name;
//	std::string get_status() { return status; }
//	private:
//		std::string status = "all";//default value
//};

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

	std::cout << new_user.get_status() << std::endl;

	new_user.set_status("gold");
	std::cout << new_user.get_status() << std::endl;
	new_user.set_status("tacos");
	std::cout << new_user.get_status() << std::endl;

	std::cout << User::get_user_count() << std::endl;
	
	//new_user.~User(); //Using destructor

	std::cout << User::get_user_count() << std::endl;

	output_status(new_user);

	User new_user1;
	std::cin >> new_user1;

	/*
	new_user1.first_name = "I'ts ME";
	new_user1.last_name = "MARIO";
	*/

	//new_user1.set_status("gold");
	
	std::cout << std::endl << new_user1 << std::endl;

	return 0;
}











