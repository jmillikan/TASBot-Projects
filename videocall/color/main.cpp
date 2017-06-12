#include "main_window.h"
#include "settings.h"
#include <QApplication>
#include <iostream>
#include <QCoreApplication>
#include <QCommandLineParser>
#include <QStringList>
#include <QTextStream>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QTextStream out(stdout);
	QCommandLineParser options;
	Settings s;

	// Options with defaults
	const QCommandLineOption widthOption(
		QStringList() << "w" << "width", "Image buffer width", "width", "128");
	const QCommandLineOption heightOption(
		QStringList() << "h" << "height", "Image buffer height", "height", "112");
	const QCommandLineOption ircHostOption(
		"host", "IRC/Twitch host", "host", "irc.chat.twitch.tv");
	const QCommandLineOption ircPortOption(
		"port", "IRC port", "port", "6667");
	const QCommandLineOption ircUseSslOption(
		"ssl", "1 = Use SSL", "1/0", "0");
	const QCommandLineOption picturesFolderOption(
		"pictures", "Pictures folder", "pictures", "../pictures");
	const QCommandLineOption emotesFolderOption(
		"emotes", "Emotes folder", "emotes", "../twitchemotes");

	// Options without defaults
	const QCommandLineOption ircPasswordOption(
		QStringList() << "p" << "password", "Required. IRC bot password", "password"/*, "default..." */);
	const QCommandLineOption ircBotNameOption(
		QStringList() << "b" << "botname", "Required. IRC bot name", "botname"/*, "default..." */);
	const QCommandLineOption ircChannelOption(
		QStringList() << "c" << "channel", "Required. IRC channel", "channel"/*, "default..." */);

	options.addOption(widthOption);
	options.addOption(heightOption);
	options.addOption(ircHostOption);
	options.addOption(ircPasswordOption);
	options.addOption(ircBotNameOption);
	options.addOption(ircChannelOption);
	options.addOption(ircPortOption);
	options.addOption(ircUseSslOption);
	options.addOption(picturesFolderOption);
	options.addOption(emotesFolderOption);

	if(!options.parse(QCoreApplication::arguments())
	   || !options.isSet(ircPasswordOption)
	   || !options.isSet(ircBotNameOption)
	   || !options.isSet(ircChannelOption)){
		QTextStream out(stdout);
		out << options.helpText();

		QApplication::quit();
		return 1;
	}
	
	s.width = options.value(widthOption).toInt();
	s.height = options.value(heightOption).toInt();
	s.irc_host = options.value(ircHostOption);
	s.irc_password = options.value(ircPasswordOption);
	s.irc_bot_name = options.value(ircBotNameOption);
	s.irc_channel = options.value(ircChannelOption);
	s.irc_port = options.value(ircPortOption).toInt();
	s.irc_use_ssl = options.value(ircUseSslOption).toInt() == 1;
	s.pictures_folder = options.value(picturesFolderOption);
	s.emotes_folder = options.value(emotesFolderOption);

	main_window w(s);
	w.show();
	
	return a.exec();
}
