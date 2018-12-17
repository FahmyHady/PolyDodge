#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/System/Time.hpp>
#include<string.h>
#include<string>
#include<string>
using namespace std;
using namespace sf;
class   MyClass : public CircleShape
{
public:

	MyClass(RenderWindow *win2, int radius2 = 100, int points2 = 30, Color color2 = Color::Blue, float Srotation2 = 0, float Sposx2 = 0, float Sposy2 = 500, float Sstepx2 = 2, float Sstepy2 = 0, int origin2 = 100)
	{
		if (Sposx2 == 0 || Sposy2>800 )
		{
			Wrotation = 90;

		}

		else
		{
			Wrotation = 60;
		}
		radius = radius2;
		points = points2;
		color = color2;
		Srotation = Srotation2;
		Sposx = Sposx2;
		Sposy = Sposy2;
		Sstepx = Sstepx2;
		Sstepy = Sstepy2;
		origin = origin2;
		win = win2;
		SShape = CircleShape(radius, points);
		SShape.setFillColor(color);
		SShape.setOrigin(origin, origin);
		SShape.setPosition(Sposx, Sposy);
		Warstep = 0;
		Warner = sf::CircleShape(100, 3);
		Warner.setFillColor(Color::Color(255, 0, 0, 255));
		Warner.setPosition(Sposx, Sposy);
		Warner.setOutlineThickness(5);
		Warner.setOutlineColor(Color::Yellow);
		Warner.setOrigin(100, 100);
		score = 0;
		b = sf::seconds(0);
		myfont.loadFromFile("Best Prices.ttf");
		Score.setFont(myfont);
		Score.setCharacterSize(20);
		Score.setFillColor(Color::Blue);
		Score.setPosition(900, 40);
		t.setFont(myfont);
		t.setString("YOU LOST, BE CAREFUL!\n PRESS MOUSE BUTTON TO CONTINUE PLAYING");
		t.setCharacterSize(30);
		t.setFillColor(Color::Red);
		t.setPosition(420, 540);
	}
	~MyClass() {
	}

	void updateShape()
	{

		while (win->getSize().x + radius > SShape.getPosition().x  && win->getSize().y + radius > SShape.getPosition().y && SShape.getPosition().y >= 0 && SShape.getPosition().x >= 0)
		{
			win->clear();
			Score.setString(to_string(score));
			SShape.move(Sstepx, Sstepy);
			SShape.rotate(Srotation);
			win->draw(Score);
			win->draw(SShape);
			win->display();

			if (Mouse::getPosition().x >= SShape.getPosition().x - radius
				&& Mouse::getPosition().x <= SShape.getPosition().x + (5*radius/6)
				&& Mouse::getPosition().y >= SShape.getPosition().y - radius
				&& Mouse::getPosition().y <= SShape.getPosition().y + (5 * radius / 6))

			{
				win->draw(t);

				win->display();
				while (e.type != Event::MouseButtonPressed)
				{
					win->pollEvent(e);
					if ((e.type == Event::Closed))
					{
						win->close();
					}

				}

				score = 0;
			}

		}
		SShape.setPosition(Sposx, Sposy);

			this->score++;

		
	}
	void DrawWarning()
	{
		Warner.setRotation(Wrotation);
		flag = 0;

		int z = 0;
		while (flag==0)
		{
			if (b.asSeconds() < 2)
			{
				//win->clear();

				win->draw(Warner);
				Warstep += 0.01f;
				b = sf::seconds(Warstep);
				win->display();
			}
			else
			{
				b = sf::seconds(0);
				flag++;
				Warstep = 0;
				win->clear();

			}
		}
		

	}
private:
	CircleShape SShape;
	float Warstep;
	CircleShape Warner;
	Time b;
	Font myfont;
	Text t;
	Text Score;
	int radius, points, origin;
	static int score;
	Color color;
	float Srotation;
	float Sposx, Sposy, Sstepx, Sstepy;
	float Wrotation;
	RenderWindow *win;
	Event e;
	int flag;
};
int MyClass::score = 0;

void main()
{
	RenderWindow window;
	RenderWindow *pwindow;
	pwindow = &window;
	window.create(sf::VideoMode(1950, 1080), "Grapher");
	Event e;
	e.type = Event::EventType::GainedFocus;
	MyClass Mark1(&window, 100, 30, Color::Blue, 0, 0, 500, 2, 0, 100);
	MyClass Mark2(&window, 100, 3, Color::Cyan, 2, 1200, 0, 0, 2, 100);
	MyClass Mark3(&window, 150, 3, Color::Yellow, 2, 800, 0, 0, 2, 0);
	MyClass Mark4(&window, 100, 4, Color::Red, 2, 1200, 0, -2, 2.5, 100);
	MyClass Mark5(&window, 140, 5, Color::Green, 2, 0, 1080, 2.5, -2.5, 140);
	MyClass Mark6(&window, 130, 5, Color::Magenta, 2, 0, 0, 2.5, 2.5, 130);
	MyClass Mark7(&window, 125, 5, Color::White, 3, 0, 600, 3, 0, 125);
	MyClass Mark8(&window, 125, 3, Color::Color(200,155,233,255), 2, 800, 0, 1, 2, 0);
	MyClass Mark9(&window, 125, 30, Color::Color(100, 155, 250, 255), 2, 0, 500, 2.5, 0, 50);
	MyClass Mark10(&window, 200, 5, Color::White, 0, 0, 1000, 3,-2, 200);
	MyClass Mark11(&window, 125, 30, Color::Color(255, 200, 150, 255), 2, 0, 200, 2.5,0.5, 50);
	MyClass Mark12(&window, 400, 5, Color::Color(100, 200, 150, 255), 0.1, 0, 500, 1, 0, 400);
	MyClass Mark13(&window, 400, 5, Color::Color(100, 200, 150, 255), 0.1, 0, 0, 3, 0, 400);



	while (window.isOpen())
	{
		window.pollEvent(e);
		
		Mark1.DrawWarning();
		Mark1.updateShape();
		//
		Mark2.DrawWarning();
		Mark2.updateShape();
		//
		Mark3.DrawWarning();
		Mark3.updateShape();
		//
		Mark4.DrawWarning();
		Mark4.updateShape();
		//
		Mark5.DrawWarning();
		Mark5.updateShape();
		//
		Mark6.DrawWarning();
		Mark6.updateShape();
		//
		Mark7.DrawWarning();
		Mark7.updateShape();
		//
		Mark8.DrawWarning();
		Mark8.updateShape();
		//
		Mark9.DrawWarning();
		Mark9.updateShape();
		//
		Mark10.DrawWarning();
		Mark10.updateShape();
		//
		Mark11.DrawWarning();
		Mark11.updateShape();
		//
		Mark12.DrawWarning();
		Mark12.updateShape();
		//
		Mark8.DrawWarning();
		Mark8.updateShape();
		//
		Mark4.DrawWarning();
		Mark4.updateShape();
		//
		Mark10.DrawWarning();
		Mark10.updateShape();
		Mark13.DrawWarning();
		Mark13.updateShape();
	}
}



