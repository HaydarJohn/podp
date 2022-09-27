#include <iostream>

class entity
{
public:

entity()
{
	x=0 ; y= 0; z= 0;
}

	double x,y,z;

	void log()
	{
	std::cout<<x<<" "<<y<<" "<<z<<std::endl;
	}

	void moveto(double ax,double ay,double az)
	{
		x=+ax; y=+ ay; z=+ az;
	}

};




int main()
{
	std::cout<<"main çalışıyor"<<std::endl;

	entity protagonist;


	protagonist.log();

	protagonist.moveto(5,5,5);

	protagonist.log();
}
