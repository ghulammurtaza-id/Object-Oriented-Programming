#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MediaFile {
protected:
    string filePath;
    int size;
public:
    MediaFile(string path, int s) :filePath(path), size(s){}
    virtual void play()= 0;
    virtual void stop() = 0;
};

class VisualMedia:virtual public MediaFile {
protected:
    int resolution;
public:
    VisualMedia(string path, int s, int res) :MediaFile(path, s),resolution(res) {}
    void play()override {
        cout << "Playing visual media from " << filePath << endl;
    }
};

class AudioMedia :virtual public MediaFile {
protected:
    int sampleRate;
public:
    AudioMedia(string path, int s, int rate): MediaFile(path, s),sampleRate(rate) {}
    void play() override {
        cout << "Playing audio media from " << filePath << endl;
    }
};

class VideoFile : public VisualMedia,public AudioMedia {
public:
    VideoFile(string path, int s, int res, int rate)
        : MediaFile(path, s),VisualMedia(path, s, res), AudioMedia(path, s, rate) {}
    void play() override {
        VisualMedia::play();
        AudioMedia::play();
    }
    void stop() override {
        cout << "Stopped video " << filePath << endl;
    }
};

class ImageFile :public VisualMedia{
public:
    ImageFile(string path, int s, int res): MediaFile(path, s), VisualMedia(path, s, res) {}
    void stop() override {
        cout << "Stopped image " <<filePath<< endl;
    }
};

class AudioFile :public AudioMedia {
public:
    AudioFile(string path, int s,int rate) : MediaFile(path, s),AudioMedia(path, s, rate) {}
    void stop() override {
        cout << "Stopped audio " << filePath << endl;
    }
};

int main() {
    vector<MediaFile*> media;
    media.push_back(new VideoFile("video.mp4", 100,1080, 44100));
    media.push_back(new ImageFile("image.jpg", 50, 720));
    media.push_back(new AudioFile("audio.mp3", 20,48000));

    for (auto file : media) {
        file->play();
        file->stop();
    }

    return 0;
}
