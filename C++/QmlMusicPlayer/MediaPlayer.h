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

public:
    MediaPlayer(); // standard Qt constructor with parent for memory management

    //std::vector<QUrl>& getFiles();

public slots: // slots can be connected to signals, or called
    void playClicked(const QUrl&);
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

signals: // signals can be emitted
    void stateChanged();
    void mediaChanged();
    void durationChanged();
    void positionChanged();
    void volumeChanged();

private: // data members
    QMediaPlayer m_player;
    QUrl m_selectedFile;

    QString m_state;
    QString m_media;
    QString m_duration;
    float m_position = 0;
    float m_volume = 50;
};


#endif // MEDIAPLAYER_H
