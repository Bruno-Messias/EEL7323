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
	static int user_count; //Static is a feature in all object of a class
	std::string status = "all"; // default value

public:

	static int get_user_count()
	{
		return user_count;
	}

	std::string first_name;
	std::string last_name;

	User() //Constructor
 
	{ 
		//std::cout << "New User\n"; 
		user_count++;
	} 	
	User(std::string first_name, std::string last_name) //Overloading constructor
	{
		//std::cout << "New User\n";
		user_count++;
		this->first_name = first_name;
		this->last_name = last_name;
	}
	~User() //Destructor 
	{ 
		//std::cout << "Destructor\n";
		user_count--;
	} 

	std::string get_status() { return status; } //Getting a private variable

	void set_status(std::string status)  //Setting a private variable
	{ 
		if (status == "gold" || status == "silver" || status == "bronze")
			this->status = status;
		else
			this->status = "all";
	}

	friend void output_status(User user); // can acess the private value by using this void output status -> is a friend function

	friend std::ostream& operator << (std::ostream& out, const User user); //now this function can read the private values

	friend std::istream& operator >> (std::istream& in, User& user);

};

int User::user_count = 0; //Cant initialized inside the class;

void output_status(User user)
{
	std::cout << user.status;
}

std::ostream& operator << (std::ostream& out, const User user)
{
	out <<	"Fist Name: " << user.first_name << "\n"
			"Last Name: " << user.last_name << "\n"
			"Status: " << user.status << "\n"; //Now this work beacuse the friend function
			//"Staus: " << user.get_status() << "\n"; //not work with const User
	
	return out;
}

std::istream& operator >> (std::istream &in, User &user)
{
	std::cout << "Insert First Name - Last Name - status:  ";
	in >> user.first_name >> user.last_name >> user.status;
	return in;
}

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











