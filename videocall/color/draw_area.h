#ifndef DRAW_AREA_H
#define DRAW_AREA_H

#include <QWidget>
#include <QImage>
#include <QMap>
#include <QKeyEvent>
#include <QStack>
#include "bot.h"
#include "settings.h"

class draw_area : public QWidget
{
		Q_OBJECT
	public:
		explicit draw_area(const Settings &s, QWidget *parent = 0);

	public slots:
		void register_color(QString color, unsigned int space);
		void register_emote(QString emote, int hash);
		
	protected:
		void paintEvent(QPaintEvent *event);
		void keyPressEvent(QKeyEvent *event);
		
	private:
		struct emote_location{
			QString name;
			unsigned int x;
			unsigned int y;
		};

		QImage *image;
		int image_width;
		int image_height;
		QMap<QString, QPixmap *> emotes;
		QVector<QImage *> pictures;
		QVector<QVector<QPair<int, int>>> picture_coords;
		int current_picture = 0;
		bot irc;
		QVector <emote_location> registered_emotes;
		QStack <QPair<int, int>> stack;

		void flood_fill(int x, int y, QColor target, QColor new_color);
		void update_picture();

};

#endif // DRAW_AREA_H
