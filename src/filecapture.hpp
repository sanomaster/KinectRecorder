#ifndef FILECAPTURE_H
#define FILECAPTURE_H

#include <icapture.hpp>
#include <cstdio>
#include <stdexcept>

class FileCapture : public ICapture
{
public:
    FileCapture(std::string path);
    ~FileCapture();
    void readFrame();
    bool isConnected();
    int getFrameCount () { return frame_count; }
    bool setFrameNumber(int n);

private:
    int iter;
    std::string cur_path;
    FILE* file;
    int frame_count;
};

#endif // FILECAPTURE_H
