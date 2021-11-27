/*
 * CONSTRUCTOR INVOKATION HELP GUIDE
 * Provide arguments for Derived class followed by arguments for Base class OR
 * Provide arguments for Derived class and set Base class variables later through member functions OR
 * Don't provide arguments at all, use member functions to set and update Base as well as Derived variables
 */

#include <iostream>
#include <string>
using namespace std;

class staff //Super class
{
	protected:
		//Declarations
		int code;
		string name;
	public:
		//Initializations
		static int members;
		staff(int Code, string Name) //Constructor function 1
		:code{Code}, name{Name}{
				members++;
			}
		staff() //Constructor function 2
		{
			code = -1;
			name = "";
			members++;
			}
		//Member functions
		auto setStaff(int Code, string Name) //Regarding constructor 2
		{
			this->code = Code;
			this->name = Name;
			}
		auto setStaff(int Code) //Overloaded function
		{
			cout<<"Staff Code updated\n";
			this->code = Code;
			}
		auto setStaff(string Name) //Overloaded function
		{
			cout<<"Staff Name updated\n";
			this->name = Name;
			}
		auto showStaff()
		{
			cout<<"Staff Code is: "<<this->code
				<<"\nStaff Name is: "<<name<<"\n";
			}
		auto returnMembers()
		{
			return members;
			}
	};

int staff::members = 0;

class teacher : public staff //First hierarchy -1
{
	protected:
		//Declarations
		string subject,
				publication;
	public:
		//Initializations
		teacher(string Subject, string Publication, int Code, string Name) //Constructor function 1
		:staff(Code, Name), subject{Subject}, publication{Publication}{}
		teacher(string Subject, string Publication) //Constructor function 2
		:subject{Subject}, publication{Publication}
		{}
		teacher() //Constructor function 3
		{
			subject = "";
			publication = "";
			}
		//Member functions
		auto setTeacher(string Subject, string Publication) //Regarding constructor 3
		{
			this->subject = Subject;
			this->publication = Publication;
			}
		auto setTeacher(string Subject) //Overloaded function
		{
			//Under the assumption that all subject lengths are less than 10 and all publication lengths are greater than 10
			if(Subject.length() < 10)
			{
				cout<<"Teacher Subject Updated\n";
				this->subject = Subject;
				}
			else
			{
				cout<<"Teacher Publication Updated\n";
				this->publication = Subject;
				}
			}
		auto showTeacher()
		{
			cout<<"Teacher Subject is: "<<this->subject
				<<"\nPublication Name is: "<<publication<<"\n";
			this->showStaff(); //Since class inherted from Staff Base Class
			}
	};

class typist : public staff //First hierarchy -2
{
	protected:
		//Declarations
		int speed;
	public:
		//Initializations
		typist(int Speed, int Code, string Name) //Constructor function 1
		:staff(Code, Name), speed{Speed}{}
		typist(int Speed) //Constructor function 2
		:speed{Speed}{}
		typist() //Constructor function 3
		{
			speed = 0;
			}
		//Member functions
		auto setTypist(int Speed) //Regarding constructor 3
		{
			this->speed = Speed;
			}
		auto setTypist(int Speed, int Code, string Name) //Overloaded function
		{
			this->speed = Speed;
			setStaff(Code, Name);
			}
		auto showTypist()
		{
			cout<<"Typist speed is: "<<this->speed<<" wpm\n";
			this->showStaff(); //Since class inherted from Staff Base Class
			}
	};

class officer : public staff //First hierarchy -3
{
	protected:
		//Declarations
		int grade;
	public:
		//Initializations
		officer(int Grade, int Code, string Name) //Constructor function 1
		:staff(Code, Name), grade{Grade}{}
		officer(int Grade) : grade{Grade}{} //Constructor function 2
		officer() //Constructor function 3
		{
			grade = 0;
			}
		//Member functions
		auto setOfficer(int Grade) //Regarding constructor 3
		{
			grade = Grade;
			}
		auto showOfficer()
		{
			cout<<"Officer Grade is: "<<this->grade<<" \n";
			this->showStaff(); //Since class inherted from Staff Base Class
			}
	};

class regular : public typist //Second hierarchy -1
{
	public:
		//Initializations
		regular(int Speed, int Code, string Name) //Constructor function 1
		:typist(Speed, Code, Name){}
		regular()
		{
			cout<<"Regular constructor invoked\n";
			}
		//Member functions
		auto setRegular(int Speed, int Code, string Name)
		{
			setTypist(Speed, Code, Name);
			}
		auto showRegular()
		{
			this->showTypist();
			}
	};

class casual : public typist //Second hierarchy -2
{
	protected:
		//Declarations
		int dailyWages;
	public:
		//Initializations
		casual(int DailyWages, int Speed, int Code, string Name) //Constructor function 1
		:typist(Speed, Code, Name), dailyWages{DailyWages}{}
		casual(int DailyWages) //Constructor function 2
		:dailyWages{DailyWages}{}
		casual() //Constructor function 3
		{
			dailyWages = 0;
			}
		//Member functions
		auto setCasual(int DailyWages) //Overloaded functions
		{
			dailyWages = DailyWages;
			}
		auto setCasual(int DailyWages, int Speed, int Code, string Name)
		{
			dailyWages = DailyWages;
			setTypist(Speed, Code, Name);
			}
		auto showCasual()
		{
			cout<<"Daily Wages are: "<<dailyWages<<"\n";
			this->showTypist();
			}
	};

int main()
{
	cout<<"Set DataBase -\n";

	// Staff DB
	staff obj1, obj2(352, "Mohit");
	obj2.showStaff();
	obj2.setStaff(353);
	obj2.showStaff();
	obj2.setStaff("Meenakshi Ma'am");
	obj2.showStaff();
	cout<<"DataBase Members: "<<obj2.returnMembers()<<"\n\n";

	//Teacher DB
	teacher obj3, obj4("oops", "Harley and sons");
	obj3.setTeacher("Maths");
	obj3.setTeacher("Harendra kumar verma");
	obj3.setStaff(353, "Maths teacher");
	obj3.showTeacher();
	cout<<"DataBase Members: "<<obj3.returnMembers()<<"\n\n";

	//Typist DB
	typist obj5, obj6(554);
	obj6.setStaff(352, "Mangal Singh");
	obj6.showTypist();
	cout<<"DataBase Members: "<<obj6.returnMembers()<<"\n\n";

	//Officer DB
	officer obj7, obj8(9, 353, "Officer Staff");
	obj8.showOfficer();
	cout<<"DataBase Members: "<<obj8.returnMembers()<<"\n\n";

	//Regular DB
	regular obj9; //parenthesis not required to invoke a constructor with no parameters
	obj9.setRegular(40, 352, "Meenakshi");
	obj9.showStaff();
	cout<<"DataBase Members: "<<obj9.returnMembers()<<"\n\n";

	//Casual DB
	casual obj10;
	obj10.setCasual(150, 35, 325, "Jitendra singh");
	obj10.showCasual();
	cout<<"DataBase Members: "<<obj10.returnMembers()<<"\n\n";

	return EXIT_SUCCESS;
	}
