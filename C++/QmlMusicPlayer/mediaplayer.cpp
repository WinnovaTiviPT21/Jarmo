#include <QMediaPlayer>
#include "mediaplayer.h"

MediaPlayer::MediaPlayer() {}

QString MediaPlayer::display() {
    return m_display;
}

void MediaPlayer::playClicked() {

    //m_mediaplayer.setMedia(QUrl::fromLocalFile(sName));
    m_mediaplayer.setMedia(QUrl::fromLocalFile("/C:/Users/Oppilas/Documents/GitHub/Jarmo/C++/QmlMusicPlayer/Testi.mp3"));
    m_mediaplayer.play();
    m_mediaplayer.setVolume(50);
    // m_display += QString::number(digitValue);
    emit displayChanged(m_display);
}

//void pauseClicked(){}

//void stopClicked(){}

//void MediaPlayer::play;
