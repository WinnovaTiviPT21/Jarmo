#include <QMediaPlayer>
#include "mediaplayer.h"

bool paused;

//std::string currentMedia();

MediaPlayer::MediaPlayer() {}

QString MediaPlayer::display() {
    return m_display;
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

    //m_player.setVolume(50);

    //m_display += QString::number(digitValue);

    emit displayChanged(m_display);
}

void MediaPlayer::pauseClicked() {
    if (paused == false){
        m_player.pause();
        paused = true;
    }
}

void MediaPlayer::stopClicked() {
    m_player.stop();
    paused = false;
}

