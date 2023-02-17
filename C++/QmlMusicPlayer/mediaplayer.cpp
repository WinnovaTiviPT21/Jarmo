#include <QMediaPlayer>
#include "mediaplayer.h"


MediaPlayer::MediaPlayer()
{
    connect(&m_player, &QMediaPlayer::stateChanged, this, &MediaPlayer::updateState);
    connect(&m_player, &QMediaPlayer::durationChanged, this, &MediaPlayer::updateDuration);
    connect(&m_player, &QMediaPlayer::positionChanged, this, &MediaPlayer::updatePosition);
}


// get
QString MediaPlayer::getState() {
    return m_state;
}
QString MediaPlayer::getMedia() {
    return m_media;
}
QString MediaPlayer::getDuration(){
    return m_duration;
}
float MediaPlayer::getPosition() {
    return m_position;
}
float MediaPlayer::getVolume() {
    return m_volume;
}


// set
float MediaPlayer::setPosition(float& position) {
    m_player.setPosition(position);
    return m_position;
}
float MediaPlayer::setVolume(float& volume) {
    m_player.setVolume(volume);
    return m_volume;
}


// update
void MediaPlayer::updatePosition(qint64 p) {
    if (m_player.duration() != 0) {
        m_position = 100 * p / m_player.duration();

        emit positionChanged();
    }
}

void MediaPlayer::updateState() {
    emit stateChanged();
}
void MediaPlayer::updateDuration(qint64) {
//    int d, min, sec;

//    d = m_player.duration()/ 1000;
//    min = d / 60;
//    sec = d % 60;
//    m_duration = QString::number(min) + "min " + QString::number(sec);

//    qint64 x = m_player.duration();
//    m_duration = QString::number(x);
    emit durationChanged();
}

QString MediaPlayer::openClicked {
    select();
    return 0;
}

void MediaPlayer::playClicked() {
    if (m_player.state() == QMediaPlayer::StoppedState) {
        m_player.setMedia(QUrl::fromLocalFile("C:/Users/Oppilas/Documents/GitHub/Jarmo/C++/QmlMusicPlayer/Testi.mp3"));
        m_player.play();
    }
    else if (m_player.state() == QMediaPlayer::PausedState) {
        m_player.play();
    }

    m_player.setVolume(m_volume);
}
void MediaPlayer::pauseClicked() {
        m_player.pause();
}
void MediaPlayer::stopClicked() {
    m_player.stop();
}
