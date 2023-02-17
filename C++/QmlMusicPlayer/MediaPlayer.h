#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <QMediaPlayer>
#include <QObject>

class MediaPlayer : public QObject
{
    Q_OBJECT // enabled meta object abilities

    // property declarations required for QML
    Q_PROPERTY(QString state READ getState NOTIFY stateChanged)
    Q_PROPERTY(QString media READ getMedia NOTIFY mediaChanged)
    Q_PROPERTY(QString duration READ getDuration NOTIFY durationChanged)
    Q_PROPERTY(float position READ getPosition WRITE setPosition NOTIFY positionChanged)
    Q_PROPERTY(float volume READ getVolume WRITE setVolume NOTIFY stateChanged)

public:
    MediaPlayer(); // standard Qt constructor with parent for memory management

//    std::vector<QUrl>& getFiles();

//    enum Enum_Operations {
//        Error,
//        Flag,
//        MediaStatus,
//        State
//    };
//    // enables enum introspections
//    Q_ENUM(Enum_Operations)

public slots: // slots can be connected to signals, or called
    //void open();

    void playClicked();
    void pauseClicked();
    void stopClicked();
    //void nextClicked();
    //void previousClicked();

    QString getState();
    QString getMedia();
    QString getDuration();
    float getPosition();
    float setPosition(float&);
    float getVolume();

    float setVolume(float&);

    //void selectFile();
    //void updateState();
    //QMediaPlayer& player();

signals: // signals can be emitted
    void stateChanged(QString);
    void mediaChanged(QString);
    void durationChanged(QString);
    void positionChanged(float);
    //void stateChanged(float);

private:
    // data members
    QMediaPlayer m_player;

    QString m_state;
    QString m_media;
    QString m_duration;
    float m_position;
    float m_volume;
};


#endif // MEDIAPLAYER_H
