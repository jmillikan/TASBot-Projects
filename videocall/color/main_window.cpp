#include "main_window.h"
#include "draw_area.h"

main_window::main_window(const Settings &s, QWidget *parent)
        : QMainWindow(parent)
{
	setCentralWidget(new draw_area(s, this));
}

main_window::~main_window()
{
	
}
