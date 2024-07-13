#ifndef Alphanumeric_screen_h
#define Alphanumeric_screen_h

#include <iostream>
#include <string>

class Alphanumeric_screen
{
	std::string content;
	char background_character;

public:
	enum {screen_width = 63, screen_height_as_enum = 17};
	static constexpr int screen_height = 17;

	// constructor
	Alphanumeric_screen(char sign = ' ')
	{
		background_character = sign;
		clear_screen();
	}

	void clear_screen()
	{
		content.clear();

		std::string one_line(screen_width - 1, background_character);
		one_line = one_line + '\n';
		for (int i = 0; i < screen_height; ++i)
			content = content + one_line;
	}

	void display()
	{
		std::cout << content << std::flush;
	}

	void write(int column, int row, std::string text)
	{
		content.replace( (screen_width * row) + column, text.length(), text);
	}
};
#endif