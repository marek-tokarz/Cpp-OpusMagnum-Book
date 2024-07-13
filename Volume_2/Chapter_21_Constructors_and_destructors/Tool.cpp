#include "Tool.h"
#include "Alphanumeric_screen.h"

using namespace std;

extern Alphanumeric_screen screen; // global object

Tool::Tool(int xx, int yy, string nnn, string unit, int w)
{
	name = nnn;
	units = unit;
	display = w;
	x = xx;
	y = yy;
	draw();
}

Tool::Tool(void)
{
	++unknown_amount;	// one more unknown screen display
	units = " ";

	name = "A s. d. n.: "; // name = "A screen display number: "; - with this name of a 'Tool' 
	// a text printed in a terminal could not fit into one line with width: 63
	name = name + to_string(unknown_amount);

	// position for a 'Tool' at the screen
	x = 33;
	y = 1 + (unknown_amount - 1) * 4;

	display = 0;
	draw();
}

void Tool::change_display(int w)
{
	display = w;
	draw();
}

void Tool::draw()
{
	screen.write(x, y,     " ________________________");
	screen.write(x, y + 1, "I                        I");
	screen.write(x, y + 2, "I                        I");
	screen.write(x, y + 3, "I________________________I");

	screen.write(x + 4, y + 1, name);
	screen.write(x + 7, y + 2, to_string(display));
	screen.write(x + 14, y + 2, units);
	screen.display();
}

int Tool::unknown_amount;