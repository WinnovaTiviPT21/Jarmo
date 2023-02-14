#include <QMediaPlayer>
#include "mediaplayer.h"

bool paused;

MediaPlayer::MediaPlayer() {}

QString MediaPlayer::getMedia() {
    return m_media;
}

QString MediaPlayer::getDuration(){
//    qint64 x = m_player.duration();
//    m_duration = QString::number(x);
    return m_duration;
}

float MediaPlayer::getPosition() {
    return m_position;
}

float MediaPlayer::setPosition(float&) {
    return m_position;
}

float MediaPlayer::getVolume() {
    return m_volume;
}

float MediaPlayer::setVolume(float& volume) {
    m_player.setVolume(volume);
    return m_volume;
}

void MediaPlayer::playClicked() {
    if (paused == true) {
        m_player.play();
        paused = false;
    }
    else {
        //m_mediaplayer.setMedia(QUrl::fromLocalFile("/C:/Users/Oppilas/Documents/GitHub/Jarmo/C++/QmlMusicPlayer/Testi.mp3"));
        m_player.setMedia(QUrl::fromLocalFile("D:/Maahantuoja/Documents/GitHub/Jarmo/C++/QmlMusicPlayer/Testi.mp3"));
        m_player.play();
        paused = false;
    }

    m_player.setVolume(20);

    m_player.currentMedia();

    qint64 x = m_player.duration();
    m_duration = QString::number(x);
    emit durationChanged(m_duration);
}

void MediaPlayer::pauseClicked() {
    if (paused == false){
        m_player.pause();
        paused = true;
    }
}

void MediaPlayer::stopClicked() {
    m_player.stop();
    paused = true;
}
