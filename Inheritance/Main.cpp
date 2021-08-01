#include <iostream>
using namespace std;
#define delimiter "\n-----------------------------------------\n"

class Human
{
	string last_name;
	string first_name;
	unsigned int age;
public:
	const string& get_last_name() const
	{
		return last_name;
	}
	const string& get_first_name() const
	{
		return first_name;
	}
	unsigned int get_age() const
	{
		return age;
	}
	void set_last_name(const string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}
	// Constructors
	Human(const string& last_name, const string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "H_Constructor: \t" << this << endl;

	}
	~Human()
	{
		cout << "H_Destructor: \t" << this << endl;
	}

	// Methods

	virtual void print() const
	{
		cout << last_name << "  " << first_name << ", " << age;
		print_year_suffix(age);
		cout << endl;
	
	}
protected:
	void print_year_suffix(unsigned int age) const
	{
		if (age >= 5 && age <= 20)cout << " лет";
		else if(age % 10 >= 5 || age % 10 == 0) cout << " лет";
		else if (age % 10 > 1 && age % 10 < 5) cout << " года";
		else cout << " год";
		cout << endl;
	}
};
class Student : public Human
{
	string speciality;
	string group;
	double rating;
public:
	const string& get_speciality() const
	{
		return speciality;
	}
	const string& get_group() const
	{
		return group;
	}
	double get_rating() const
	{
		return rating;
	}
	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	//  Constructor

	Student
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& group, double rating
	):Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		cout << "S_Constructor: \t" << this << endl;
	}
	~Student()
	{
		cout << "S_Destructor: \t" << this << endl;
	}
	//   Methods
	void print()const
	{
		Human::print();
		cout << "Специальность: " << speciality << ", группа: " << group << ", успеваемость: " << rating << endl;
	}
};
class Teacher :public Human
{
	string speciality;
	unsigned int experience;
public:
	const string& get_speciality() const
	{
		return speciality;
	}
	unsigned int get_experience() const
	{
		return experience;
	}
	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}
	//   Constructors
	Teacher
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, unsigned int experience
	) :Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "T_Constructor: \t" << this << endl;
	}
	~Teacher()
	{
		cout << "T_Destructor: \t" << this << endl;
	}
	//   Methods
	void print()const
	{
		Human::print();
		cout << "Специальность: " << speciality << ", опыт: " << experience;
		print_year_suffix(experience);
		cout << endl;
	}
};
class Graduate : public Student
{
	string diploma_theme;
public:
	const string& get_diploma_theme() const
	{
		return diploma_theme;
	}
	void set_diploma_theme(const string& diploma_theme)
	{
		this->diploma_theme = diploma_theme;
	}
	Graduate
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& group, double rating,
		const string& diploma_theme
	) :Student(last_name, first_name, age, speciality, group, rating)
	{
		set_diploma_theme(diploma_theme);
		cout << "G_Constructor: \t" << this << endl;
	}
	~Graduate()
	{
		cout << "G_Destructor: \t" << this << endl;
	}

	//   Methods
	void print()const
	{
		Student::print();
		cout << "Тема дипломного проекта: " << diploma_theme << endl;
	}
};

//#define INHERITANCE
#define POLYMORPHISM
void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef INHERITANCE

	cout << "Наследование" << endl;
	Human vasya("Тупенко", "Василий", 22);
	vasya.print();
	cout << delimiter << endl;
	Student student("Иванов", "Федор",25, "РПО", "ВБУ_011", 90);
	student.print();
	cout << delimiter << endl;
	Teacher teacher("Федоров", "Иван", 112, "РПО", 111);
	teacher.print();
	cout << delimiter << endl;
	Graduate graduate("Веселов", "Евгений", 34, "РПО", "ВБУ_011", 90, "Ракетное топливо");
	graduate.print();
	cout << delimiter << endl;
#endif // INHERITANCE

	Human* group[] =
	{
		new Student("Галлятмутдинова", "Альбина", 25,"РПО", "ВБУ_011", 95),
		new Graduate("Ремизов", "Дмитрий", 27, "РПО", "ВБУ_011", 95, "Haval как лучшее изобретение"),
		new Teacher("Dog", "Saymon", 32, "Dog_life", 5),
		new Student("Sorokina", "Masha", 26,"РПО", "ВБУ_011", 100)
	};
	for (int i = 0; sizeof(group) / sizeof(Human*); i++)
	{
		group[i]->print();
		cout << delimiter << endl;
	}
}