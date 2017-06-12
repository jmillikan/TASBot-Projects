#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include "settings.h"

class main_window : public QMainWindow
{
		Q_OBJECT
		
	public:
		main_window(const Settings &s, QWidget *parent = 0);
		~main_window();
};

#endif // MAIN_WINDOW_H
