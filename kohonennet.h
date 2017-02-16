#ifndef KOHONENNET_H
#define KOHONENNET_H
#include "neuron.h"
#include <vector>
#include <QString>
#include <QImage>
#include <iostream>

using std::vector;


class KohonenNet
{
public:

    class InputNeuron : public Neuron{
    public:

        float kernelFunction(){
            return value;
        }

    };

    KohonenNet();
    vector<Neuron*> inNeurons;
    vector<Neuron> outNeurons;
    int handle(QImage);

private:
    void study(Neuron &n, QImage pic);
    //QString names[5] = {"face0.bmp", "face1.bmp", "face2.bmp", "face3.bmp","face4.bmp"};

    int nums[5] = {0,1,2,3,8};
    QString names[5] = {"0.bmp", "1.bmp", "2.bmp", "3.bmp", "8.bmp"};
    const uint numNumbers = 5;
};

#endif // KOHONENNET_H
