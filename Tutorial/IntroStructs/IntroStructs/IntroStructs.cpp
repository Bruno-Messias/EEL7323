/* IntroStructs.cpp : Introductions to use object oriented programming 
*  Date: 26/12/2020
*  Author: Bruno C. Messias
*/
#include <iostream>
#include <string>

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
	std::string get_status() { return status; }

};

int main()
{
	User me;
	me.first_name = "first";
	me.last_name = "last";
	//me.status = "all";//Can't acessed need a return value need a get


	std::cout << "First Nams: " << me.first_name << std::endl;
	std::cout << "Status: " << me.get_status() << std::endl;

	
	return 0;
}











