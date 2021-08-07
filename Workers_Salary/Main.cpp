#include <iostream>
using namespace std;
#define delimiter "\n-----------------------------------------\n"

class Employees
{
	string last_name;
	string first_name;
	string position;
	string salary_type;
public:
	const string& get_last_name() const
	{
		return last_name;
	}
	const string& get_first_name() const
	{
		return first_name;
	}
	const string& get_position() const
	{
		return position;
	}
	const string& get_salary_type() const
	{
		return salary_type;
	}
	void set_last_name(const string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const string& first_name)
	{
		this->first_name = first_name;
	}
	void set_position(const string& position)
	{
		this->position = position;
	}
	void set_salary_type(const string& salary_type)
	{
		this->salary_type = salary_type;
	}



	/////////////////// Constructors

	Employees(const string& last_name, const string& first_name, const string& position, const string& salary_type)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_position(position);
		set_salary_type(salary_type);
		cout << "E_Constructor: \t" << this << endl;

	}
	~Employees()
	{
		cout << "E_Destructor: \t" << this << endl;
	}

	///////////////////  Methods

	virtual void print() const
	{
		cout << last_name << "  " << first_name << ", " << position;
		cout << endl;
	}
};
class Hourly : public Employees
{
	double salary;
public:
	double get_salary() const
	{
		return salary;
	}
	void set_salary(double salary)
	{
		this->salary = salary;
	}

	/////////////////// Constructors

	Hourly
	(const string& last_name, const string& first_name,
		const string& position, const string& salary_type, double salary
	) :Employees(last_name, first_name, position, salary_type)
	{
		set_salary(salary);
		cout << "H_Constructor: \t" << this << endl;
	}
	~Hourly()
	{
		cout << "H_Destructor: \t" << this << endl;
	}
	//   Methods

	void print() const
	{
		Employees::print();
		cout << "Заработная плата: " << salary << " руб в час.";
		cout << endl;
	};
};
	class Monthly : public Employees
	{
		double salary;
	public:
		double get_salary() const
		{
			return salary;
		}
		void set_salary(double salary)
		{
			this->salary = salary;
		}
		/////////////////// Constructors

		Monthly
		(const string& last_name, const string& first_name,
			const string& position, const string& salary_type, double salary
		) :Employees(last_name, first_name, position, salary_type)
		{
			set_salary(salary);
			cout << "M_Constructor: \t" << this << endl;
		}
		~Monthly()
		{
			cout << "M_Destructor: \t" << this << endl;
		}
		///////////////////   Methods

		void print() const
		{
			Employees::print();
			cout << "Заработная плата: " << salary << " руб в месяц.";
			cout << endl;
		};
	};

	void main()
	{
		setlocale(LC_ALL, "Russian");

		Employees* group[] =
		{
			new Monthly("Орлов", "Святослав", "Мл. специалист по качеству","помесячно", 30000),
			new Monthly("Селиванов", "Максим", "Мл. специалист по качеству","помесячно", 32000),
			new Hourly("Зубов", "Дмитрий", "Специалист","почасовое", 150),
			new Hourly("Власова", "Ольга", "Аудитор","почасово", 400),
			new Hourly("Юшин", "Анатолий", "Инженер","почасово", 500)
		};
		for (int i = 0; sizeof(group) / sizeof(Employees*); i++)
		{
			group[i]->print();
			cout << delimiter << endl;
		}
	}