#ifndef USER_CLASS
#define USER_CLASS

class User //In classes by default the value is private
{
	static int user_count; //Static is a feature in all object of a class
	std::string status = "all"; // default value

public:
	static int get_user_count();
	std::string first_name;
	std::string last_name;
	User();
	User(std::string first_name, std::string last_name);
	~User();
	std::string get_status();
	void set_status(std::string status);
	friend void output_status(User user);
	friend std::ostream& operator << (std::ostream& out, const User user);
	friend std::istream& operator >> (std::istream& in, User& user);
};

#endif // !USER_CLASS

