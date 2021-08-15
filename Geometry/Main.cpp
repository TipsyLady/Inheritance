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
		Colour colour; //любую геометрическую фигуру можно нарисовать, опеределенным цветом
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

		virtual double get_area() const = 0; //чисто виртуальный метод
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

			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //Получаем обработчикокна консоли,
			// через который можно обратиться к окну консоли нашей программы.
			SetConsoleTextAttribute(hConsole, get_colour()); // задать цвет текста в выбранном окне консоли
			for (int i = 0; i < side; i++)
			{
				for (int j = 0; j < side; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Colour::CONSOLE_DEFAULT); //Возвращаем цвет на место
	}

#endif // SIMPLE_DRAW

		//1. Получить Обработчик окна(Handler to Window)
		HWND hwnd = GetConsoleWindow();
		hwnd = FindWindow(NULL, L"Inheritance - Microsoft Visual Studio");
		//2. Получить контекст устройства
		HDC hdc = GetDC(hwnd);//HDC - handler to device context
		//3. Создать карандаш и кисть для рисования
		HPEN hpen = CreatePen(PS_SOLID, 5, colour);//PS_SOLID- сплошная линия,
		// 5 - толщина линии в пикселях, pen (карандаш) - рисует контур фигуры
		HBRUSH hbrush = CreateSolidBrush(colour);

		//4. Взять кисть и карандаш:
		SelectObject(hdc, hpen);
		SelectObject(hdc, hbrush);

		//5. Нарисовать квадрат
		::Rectangle(hdc, 300, 300, side, side);

	// :: - Global scope (global namespace)
		//6. Освободить ресурсы
		DeleteObject(hbrush);
		DeleteObject(hpen);
		ReleaseDC(hwnd, hdc);

};
};

class Rectangle : public Shape
{

};
	}

void main()
{
	setlocale(LC_ALL, "Russian");
	//Shape shape (Colour :: CONSOLE_BLUE);
	//cout << hex << shape.get_colour() << endl;
	Geometry::Square square(500, Geometry::Colour::RED);
	cout << "Длина стороны: " << square.get_side() << endl;
	cout << "Площадь квадрата: " << square.get_area() << endl;
	cout << "Периметр квадрата: " << square.get_perimeter() << endl;
	square.draw();
	cin.get();

	//Geometry::Rectangle rect;
};