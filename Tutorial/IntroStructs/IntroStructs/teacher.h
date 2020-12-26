#ifndef TEACHER_H
#define TEACHER_H

#include<vector>
#include<string>
#include <iostream>
#include "User.h"

class Teacher : public User
{
public:
	std::vector<std::string> classes_teaching;
	void output();
	Teacher();
};


#endif // !TEACHER_H


