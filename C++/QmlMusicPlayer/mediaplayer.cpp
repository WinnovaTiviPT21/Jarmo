#include <QMediaPlayer>
#include <QMediaContent>
#include "mediaplayer.h"


MediaPlayer::MediaPlayer() {
    connect(&m_player, &QMediaPlayer::stateChanged, this, &MediaPlayer::updateState);
    connect(&m_player, &QMediaPlayer::durationChanged, this, &MediaPlayer::updateDuration);
    connect(&m_player, &QMediaPlayer::positionChanged, this, &MediaPlayer::updatePosition);

    //test
    //connect(&m_player, &QMediaPlayer::displayChanged, this, &MediaPlayer::updateDisplay);
    //QString currentMedia = m_player.metaData(QMediaMetaData::Title).toString();


//#ifdef  Q_OS_ANDROID
//    QStringList files = {"/storage/emulated/0/Music"};
//#else
//    QStringList files = QStandardPaths::standardLocations(QStandardPaths::MusicLocation);
//#endif

//    QString defaultsPath = "data/defaults.conf";
//#if defined(Q_OS_ANDROID)
//    defaultsPath = "data/android/defaults.conf";
//#endif
//    QFile defaults(defaultsPath);

}



//test
QString MediaPlayer::display() {
//    m_display = m_player.metaData("Title").toString();
//    emit displayChanged();
    return m_display;
}



// get
QString MediaPlayer::getState() {
    return m_state;
}

QString MediaPlayer::getMedia() {
    return m_media;
}

QString MediaPlayer::getDuration() {
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
void MediaPlayer::updateState() {
    emit stateChanged();
}

void MediaPlayer::updatePosition(qint64 position) {
    if (m_player.duration() != 0) {
        m_position = 100 * position / m_player.duration();
        emit positionChanged();
    }
}

void MediaPlayer::updateDuration(qint64) {
    //int d, min, sec;
    //d = m_player.duration()/ 1000;
    //min = d / 60;
    //sec = d % 60;
    //m_duration = QString::number(min) + "min " + QString::number(sec);
    //qint64 x = m_player.duration();
    //m_duration = QString::number(x);
    emit durationChanged();
}


void MediaPlayer::playClicked(const QUrl& fileUrl) {
        if (m_player.state() == QMediaPlayer::StoppedState) {
            m_player.setMedia(fileUrl);
            m_display = m_player.metaData("Title").toString();
            m_player.play();
            emit displayChanged();
        }
        else if (m_player.state() == QMediaPlayer::PlayingState) {
            m_player.pause();
        }
        else if (m_player.state() == QMediaPlayer::PausedState) {
            m_player.play();
        }
    }

void MediaPlayer::pauseClicked() {
        m_player.pause();
}

void MediaPlayer::stopClicked() {
    m_player.stop();
    m_player.setVolume(m_volume);
    emit volumeChanged();
}
