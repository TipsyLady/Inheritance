#include <iostream>
#include <Windows.h>
using namespace std;
#define delimiter "\n-----------------------------------------\n"

namespace Geometry
{
	enum Colour
	{
		CONSOLE_DEFAULT = 0x07,
		CONSOLE_RED = 0xCC,
		CONSOLE_GREEN = 0xAA,
		CONSOLE_BLUE = 0x99,

		RED = 0x000000FF, //00 - Alpha, 00 - Blue, Green, Red
		GREEN = 0x0000FF00,
		BLUE = 0x00FF0000

	};

	class Shape
	{
	protected:
		Colour colour; //����� �������������� ������ ����� ����������, ������������� ������
	public:
		Colour get_colour() const
		{
			return colour;
		}
		void set_colour(Colour colour)
		{
			this->colour = colour;
		}
		Shape(Colour colour = Colour::CONSOLE_DEFAULT) : colour(colour) {}
		virtual ~Shape() {}

		virtual double get_area() const = 0; //����� ����������� �����
		virtual double get_perimeter() const = 0;
		virtual void draw() const = 0;
	};

	class Square : public Shape
	{
		double side;
	public:
		double get_side() const
		{
			return side;
		}
		void set_side(double side)
		{
			if (side <= 0)side = 1;
			this->side = side;
		}
		Square(double side, Colour colour) :Shape(colour)
		{
			set_side(side);
		}
		~Square() {}

		double get_area()const
		{
			return side * side;
		}
		double get_perimeter() const
		{
			return side * 4;
		}
		void draw()const
		{
			//#define SIMPLE_DRAW
#ifdef SIMPLE_DRAW

			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //�������� �������������� �������,
			// ����� ������� ����� ���������� � ���� ������� ����� ���������.
			SetConsoleTextAttribute(hConsole, get_colour()); // ������ ���� ������ � ��������� ���� �������
			for (int i = 0; i < side; i++)
			{
				for (int j = 0; j < side; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Colour::CONSOLE_DEFAULT); //���������� ���� �� �����
	}

#endif // SIMPLE_DRAW

		//1. �������� ���������� ����(Handler to Window)
		HWND hwnd = GetConsoleWindow();
		hwnd = FindWindow(NULL, L"Inheritance - Microsoft Visual Studio");
		//2. �������� �������� ����������
		HDC hdc = GetDC(hwnd);//HDC - handler to device context
		//3. ������� �������� � ����� ��� ���������
		HPEN hpen = CreatePen(PS_SOLID, 5, colour);//PS_SOLID- �������� �����,
		// 5 - ������� ����� � ��������, pen (��������) - ������ ������ ������
		HBRUSH hbrush = CreateSolidBrush(colour);

		//4. ����� ����� � ��������:
		SelectObject(hdc, hpen);
		SelectObject(hdc, hbrush);

		//5. ���������� �������
		::Rectangle(hdc, 300, 300, side, side);

	// :: - Global scope (global namespace)
		//6. ���������� �������
		DeleteObject(hbrush);
		DeleteObject(hpen);
		ReleaseDC(hwnd, hdc);

};
};

class Rectangle : public Shape
{
	double side_A;
	double side_B;
public:
	double get_side_A() const
	{
		return side_A;
	}
	double get_side_B() const
	{
		return side_B;
	}
	void set_side_A(double side_A)
	{
		if (side_A <= 0)side_A = 1;
		this->side_A = side_A;
	}
	void set_side_B(double side_B)
	{
		if (side_B <= 0)side_B = 1;
		this->side_B = side_B;
	}
	Rectangle(double side_A, double side_B, Colour colour) : Shape(colour)
	{
		set_side_A(side_A);
		set_side_B(side_B);
	}
	~Rectangle() {}

	double get_area() const
	{
		return side_A * side_B;
	}
	double get_perimeter() const
	{
		return 2 * (side_A + side_B);
	}
	void draw()const
	{
		HWND hwnd = GetConsoleWindow();
		hwnd = FindWindow(NULL, L"Inheritance - Microsoft Visual Studio");
		
		HDC hdc = GetDC(hwnd);
		
		HPEN hpen = CreatePen(PS_SOLID, 5, colour);
		HBRUSH hbrush = CreateSolidBrush(colour);

		SelectObject(hdc, hpen);
		SelectObject(hdc, hbrush);

		
		::Rectangle(hdc, 300, 300, 300+ side_A, 300 +side_B);

		
		DeleteObject(hbrush);
		DeleteObject(hpen);
		ReleaseDC(hwnd, hdc);
	}
	void print()const
	{
		cout << "����� ������� A: " <<get_side_A() << endl;
		cout << "����� ������� B: " <<get_side_B() << endl;
		cout << "������� ��������������: " << get_area() << endl;
		cout << "�������� ��������������: " << get_perimeter() << endl;
	}
};
class Circle : public Shape
{
	double radius;
protected:
	double Pi = 3.1415926;
public:
	double get_radius() const
	{
		return radius;
	}
	void set_radius(double radius)
	{
		if (radius <= 0)radius = 1;
		this->radius = radius;
	}
	Circle(double radius, Colour colour) : Shape(colour)
	{
		set_radius(radius);
	}
	~Circle() {}
	double get_area() const
	{
		return Pi * radius * radius;
	}
	double get_perimeter() const
	{
		return 2 * Pi * radius;
	}
	void draw()const
	{
		HWND hwnd = GetConsoleWindow();
		hwnd = FindWindow(NULL, L"Inheritance - Microsoft Visual Studio");

		HDC hdc = GetDC(hwnd);

		HPEN hpen = CreatePen(PS_SOLID, 5, colour);
		HBRUSH hbrush = CreateSolidBrush(colour);

		SelectObject(hdc, hpen);
		SelectObject(hdc, hbrush);


		::Ellipse(hdc, 300, 300, 300 + radius, 300 + radius);


		DeleteObject(hbrush);
		DeleteObject(hpen);
		ReleaseDC(hwnd, hdc);
	}
	void print()const
	{
		cout << "����� �����: " << get_radius() << endl;
		cout << "������� �����: " << get_area() << endl;
		cout << "�������� �����: " << get_perimeter() << endl;
	}
};
	class Triangle : public Shape
	{
	protected:
		double side_A;
		double side_B;
		double side_C;
	public:
		double get_side_A() const
		{
			return side_A;
		}
		double get_side_B() const
		{
			return side_B;
		}
		double get_side_C() const
		{
			return side_C;
		}
		void set_side_A(double side_A)
		{
			if (side_A <= 0)side_A = 1;
			this->side_A = side_A;
		}
		void set_side_B(double side_B)
		{
			if (side_B <= 0)side_B = 1;
			this->side_B = side_B;
		}
		void set_side_C(double side_C)
		{
			if (side_C <= 0)side_C = 1;
			this->side_C = side_C;
		}
		Triangle(double side_A, double side_B, double side_C, Colour colour) : Shape(colour) {}
		virtual ~Triangle (){}
		virtual double get_area() const = 0;
		virtual double get_perimeter() const = 0;
		virtual void draw() const = 0;
		
	};
	class EqualTriangle :public Triangle
	{
	public:
		EqualTriangle(double side_A, double side_B, double side_C, Colour colour) : Triangle(side_A, side_B, side_C, colour) 
		{
			set_side_A(side_A);
			set_side_B(side_B);
			set_side_C(side_C);
		}
		double get_area() const
		{
			if (get_side_A() == get_side_B() && get_side_B() == get_side_C()) return ((side_A * side_A) * sqrt(3)) / 4;
			else cout << "�� - �� - ��, ��� �� �������������� �����������! ��-��, ����� ������ ��������!" << endl;
			
		}
		double get_perimeter() const
		{
			if (get_side_A() == get_side_B() && get_side_B() == get_side_C()) return side_A * side_B * side_C;
			else cout << "�� - �� - ��, ��� �� �������������� �����������! ��-��, ����� ������ ��������!" << endl;
		}
		void draw()const 
		{

		}

		void print()const
		{
			cout << "����� ������� � ��������������� ������������: " << get_side_A() << endl;
			cout << "������� ������������: " << get_area() << endl;
			cout << "�������� ������������: " << get_perimeter() << endl;
		}
	};

}

void main()
{
	setlocale(LC_ALL, "Russian");
	//Shape shape (Colour :: CONSOLE_BLUE);
	//cout << hex << shape.get_colour() << endl;
	/*Geometry::Square square(500, Geometry::Colour::RED);
	cout << "����� �������: " << square.get_side() << endl;
	cout << "������� ��������: " << square.get_area() << endl;
	cout << "�������� ��������: " << square.get_perimeter() << endl;
	square.draw();
	cin.get();*/
	
	/*Geometry::Rectangle rectangle(400, 200, Geometry::Colour::BLUE);
	rectangle.print();
	rectangle.draw();*/

	Geometry::Circle circle(300, Geometry::Colour::GREEN);
	circle.print();
	circle.draw();
	Geometry::EqualTriangle equal(2, 2, 2, Geometry::Colour::RED);
	equal.print();

	//Geometry::Rectangle rect;
};