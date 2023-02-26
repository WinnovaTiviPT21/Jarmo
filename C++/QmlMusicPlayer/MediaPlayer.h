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
    Q_PROPERTY(float volume READ getVolume WRITE setVolume NOTIFY volumeChanged)

    //test
    Q_PROPERTY(QString display READ display NOTIFY displayChanged)
    //Q_PROPERTY(QString display READ getDisplay WRITE setDisplay NOTIFY displayChanged)
    //Q_PROPERTY(QString currentMedia READ getCurrentMedia NOTIFY currentMediaChanged)

public:
    MediaPlayer(); // standard Qt constructor with parent for memory management

    //std::vector<QUrl>& getFiles();

public slots: // slots can be connected to signals, or called
    //void playClicked(const QUrl&);
    void playClicked(QUrl);
    void pauseClicked();
    void stopClicked();

    QString getState();
    QString getMedia();
    QString getDuration();
    float getPosition();
    float getVolume();

    float setPosition(float&);
    float setVolume(float&);

    void updateState();
    void updateDuration(qint64);
    void updatePosition(qint64);

    //test
    QString display();
//    QString getDisplay();
//    QString setDisplay(QString&);
//    void updateDisplay();

//    QString getCurrentMedia();
//    void updateCurrentMedia();


signals: // signals can be emitted
    void stateChanged();
    void mediaChanged();
    void durationChanged();
    void positionChanged();
    void volumeChanged();

    //test
    void displayChanged();
//    void currentMediaChanged();

private: // data members
    QMediaPlayer m_player;
    QUrl m_selectedFile;

    QString m_state;
    QString m_media;
    QString m_duration;
    float m_position = 0;
    float m_volume = 50;

    //test
    QString m_display;
//    QString m_currentMedia;
};


#endif // MEDIAPLAYER_H
