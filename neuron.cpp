#include "neuron.h"
#include <cmath>

float Neuron::Akson::getSignal()
{
    return (ownerNeuron->kernelFunction()) ;
}

Neuron::Neuron()
{
    akson.ownerNeuron = this;
}

float Neuron::kernelFunction()
{
    float result(0.);
    for(Dendrit d : dendrits){
        result += d.inputAkson->getSignal() * d.weight;
    }
    return result / 2500;
}
