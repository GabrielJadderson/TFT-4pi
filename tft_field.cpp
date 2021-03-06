#include <stdio.h>
#include <sstream>
#include "tft_field.h"

#define OFFSET_TEXT 3

/*
 * TFT_filed:
 *	Constructor of the class
 *********************************************************************************
 */
TFT_field::TFT_field(TFT_ST7735& tft, unsigned char start_x, unsigned char start_y, unsigned char width, unsigned char height,
					 unsigned int color, unsigned char size, unsigned int background, bool border)
	: _tft(tft)
	, _refresh(true)
	, _start_x(start_x)
	, _start_y(start_y)
	, _width(width)
	, _height(height)
	, _color(color)
	, _size(size)
	, _background(background)
	, _border(border)
{

}


/*
 * setColor:
 *	set color for text an border
 *********************************************************************************
 */
void TFT_field::setColor(unsigned int color)
{
	if (color != _color)
	{
		_color = color;
		_refresh = true;
	}
}

/*
 * setSize:
 *	set size for the text
 *********************************************************************************
 */
void TFT_field::setSize(unsigned char size)
{
	if (size != _size)
	{
		_size = size;
		_refresh = true;
	}
}

/*
 * setValue:
 *	set new value(string) to display
 *********************************************************************************
 */
void TFT_field::setValue(std::string text)
{
	if (text != _text)
	{
		_text = text;
		_refresh = true;
	}
}

/*
 * setValue:
 *	set new value(int) to display
 *********************************************************************************
 */
void TFT_field::setValue(int number)
{
	std::stringstream ss;    //create a stringstream
	ss << number;            //add number to the stream
	_text = ss.str();        //return a string with the contents of the stream
	_refresh = true;

}

/*
 * setValue:
 *	set new value(double) to display
 *********************************************************************************
 */
void TFT_field::setValue(double number)
{
	std::stringstream ss;    //create a stringstream
	ss << number;            //add number to the stream
	_text = ss.str();        //return a string with the contents of the stream
	_refresh = true;

}

/*
 * refresh:
 *	delete field and refresh with actual values
 *********************************************************************************
 */
void TFT_field::refresh()
{
	unsigned char y_begin;

	if (_refresh) //refresh only if there were changes
	{
	  // clear field
		_tft.fillRect(_start_x, _start_y, _width, _height, _background);

		// draw border
		if (_border)
			_tft.drawRect(_start_x, _start_y, _width, _height, _color);

		  // draw text
		_tft.setBackground(_background);
		y_begin = _start_y + (_height - (FONT_HEIGHT*_size)) / 2;
		_tft.drawString(_start_x + OFFSET_TEXT, y_begin, _text.c_str(), _color, _size);

		_refresh = false;
	}
}