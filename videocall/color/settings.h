#ifndef SETTINGS_H
#define SETTINGS_H

struct Settings {
// And I would do it again!
    int width;
    int height;
    QString irc_host;
    QString irc_password;
    QString irc_channel;
    QString irc_bot_name;
    int irc_port;
    bool irc_use_ssl;
    QString pictures_folder;
    QString emotes_folder;
};

#endif // SETTINGS_H
