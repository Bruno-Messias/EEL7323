#include <iostream>
#include <string>
#include <vector>
#include "User.h"


int User::get_user_count()
{
	return user_count;
}

User::User() //Constructor
{
	//std::cout << "New User\n"; 
	user_count++;
}

User::User(std::string first_name, std::string last_name) //Overloading constructor
{
		std::cout << "New User\n";
		user_count++;
		this->first_name = first_name;
		this->last_name = last_name;
}

User::~User() //Destructor 
{
		//std::cout << "Destructor\n";
		user_count--;
}

std::string User::get_status() //Getting a private variable
{ 
	return status;
} 

void User::set_status(std::string status)  //Setting a private variable
{
	if (status == "gold" || status == "silver" || status == "bronze")
		this->status = status;
	else
		this->status = "all";
}

void User::output()
{
	std::cout << "i'm a user\n";
}

int User::user_count = 0;

void output_status(User user)
{
	std::cout << user.status;
}

std::ostream& operator << (std::ostream& out, const User user)
{
	out << "Fist Name: " << user.first_name << "\n"
		"Last Name: " << user.last_name << "\n"
		"Status: " << user.status << "\n"; //Now this work beacuse the friend function
		//"Staus: " << user.get_status() << "\n"; //not work with const User

	return out;
}

std::istream& operator >> (std::istream& in, User& user)
{
	std::cout << "Insert First Name - Last Name - status:  ";
	in >> user.first_name >> user.last_name >> user.status;
	return in;
}