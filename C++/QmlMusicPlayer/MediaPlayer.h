#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <QMediaPlayer>
#include <QObject>

class MediaPlayer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString display READ display NOTIFY displayChanged)

public:
    MediaPlayer();

    enum Enum_Operations {
        Error,
        Flag,
        MediaStatus,
        State
    };
    Q_ENUM(Enum_Operations)

public slots:
    void playClicked();
    void pauseClicked();
    void stopClicked();
//    void nextClicked();
//    void previousClicked();

    QString display();
    // QMediaPlayer& mediaplayer();

signals:
     void displayChanged(QString);

private:
    QMediaPlayer m_player;
    QString m_display;
};


#endif // MEDIAPLAYER_H
