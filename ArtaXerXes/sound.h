#ifndef SOUND_H
#define SOUND_H

#include <QObject>

namespace xerxes{

class Sound : public QObject
{
    Q_OBJECT
public:
    explicit Sound(QObject *parent = 0);
    ~Sound();
private:
    bool buffercheck;
    bool isFirstTime;
public slots:
    void VoiceOverNetwork(bool checkButton);

};

}
#endif // SOUND_H
