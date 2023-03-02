#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <QMediaPlayer>
#include <QObject>

class MediaPlayer : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString state READ getState NOTIFY stateChanged)
    Q_PROPERTY(QString media READ getMedia NOTIFY mediaChanged)
    Q_PROPERTY(QString duration READ getDuration NOTIFY durationChanged)
    Q_PROPERTY(float position READ getPosition WRITE setPosition NOTIFY positionChanged)
    Q_PROPERTY(float volume READ getVolume WRITE setVolume NOTIFY volumeChanged)

    //test
    Q_PROPERTY(QString display READ getDisplay NOTIFY displayChanged)
    //Q_PROPERTY(QString display READ getDisplay WRITE setDisplay NOTIFY displayChanged)

public:
    MediaPlayer();
    //MediaPlayer(QObject *parent = nullptr) : QObject(parent) {}

    //std::vector<QUrl>& getFiles();

public slots:
    //void playClicked(const QUrl&);
    void playClicked(QUrl);
    void pauseClicked();
    void stopClicked();

    QString getState();
    QString getMedia();
    QString getDuration();
    float getPosition();
    float setPosition(float&);
    float getVolume();
    float setVolume(float&);

    void updateState();
    void updateDuration(qint64);
    void updatePosition(qint64);

    //test
    QString getDisplay();
    //QString setDisplay(QString&);
    void updateDisplay();

signals: // signals can be emitted
    void stateChanged();
    void mediaChanged();
    void durationChanged();
    void positionChanged();
    void volumeChanged();

    //test
    void displayChanged();
    //void currentMediaChanged();

private:
    QMediaPlayer m_player;
    QUrl m_selectedFile;

    QString m_state;
    QString m_media;
    QString m_duration;
    float m_position = 0;
    float m_volume = 50;

    //test
    QString m_display;
};


#endif // MEDIAPLAYER_H
