#ifndef Tool_h
#define Tool_h

#include <string>

class Tool
{
	std::string name;
	std::string units;
	int display;
	int x, y;
	static int unknown_amount;

public:
	Tool(int, int, std::string, std::string, int value = 0);
	Tool(void);

	void change_display(int w);
	void draw();

};

#endif

