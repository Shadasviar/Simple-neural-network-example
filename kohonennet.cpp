#include "kohonennet.h"
#include <cmath>
#include <iostream>

KohonenNet::KohonenNet():inNeurons(),outNeurons(5)
{

    QImage pic(names[0]);

    for(int k(0); k < pic.width(); ++k){
        for(int j(0); j < pic.height(); ++j){

            Neuron *inp = new InputNeuron();
            for(uint g(0); g < numNumbers; ++g){
                InputNeuron::Dendrit *d = new InputNeuron::Dendrit();
                d->inputAkson = &inp->akson;
                outNeurons.at(g).dendrits.push_back(*d);
            }
            inNeurons.push_back(inp);

        }
    }


    for(uint i(0) ; i < numNumbers; ++i){
        QImage pic(names[i]);
        study(outNeurons.at(i), pic);
    }

}

int KohonenNet::handle(QImage pic)
{

    vector<float> data;
    for(int i(0); i < pic.width(); ++i){
        for(int j(0); j < pic.height(); ++j){
            data.push_back((127.5-abs(255 - qGray(pic.pixel(i,j))))/127.5);
        }
    }

    for(uint i(0); i < data.size(); ++i){
        inNeurons.at(i)->value =data.at(i);
    }

    int maxIndex(0);
    for(uint i(0); i < outNeurons.size(); ++i){
        float f = abs(100 - (100*outNeurons.at(i).akson.getSignal())/outNeurons.at(i).value);
        float g = abs(100 - ((100*outNeurons.at(maxIndex).akson.getSignal())/outNeurons.at(i).value));
        if(f > g)
            maxIndex = i;
    }

    return nums[maxIndex];
}


void KohonenNet::study(Neuron &n, QImage pic)
{

    vector<float> data;
    for(int i(0); i < pic.width(); ++i){
        for(int j(0); j < pic.height(); ++j){
            data.push_back((127.5 - qGray(pic.pixel(i,j)))/127.5);
        }
    }


    for(uint i(0); i < n.dendrits.size(); ++i){
        n.dendrits.at(i).weight += data[i];
    }

    for(uint i(0); i < data.size(); ++i){
        inNeurons.at(i)->value = data.at(i);
    }
    n.value = n.akson.getSignal();
}




