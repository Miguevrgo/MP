/**
 * Metodología de la Programación: Language5
 * Curso 2022/2023
 **/

/**
 * @file BigramFreq.cpp
 * @author Miguel Ángel De la Vega Rodríguez<miguevrod@correo.ugr.es>
 * @version 0.1
 * @date 2023-13-5
 * 
 */


#include "BigramFreq.h"


BigramFreq::BigramFreq(Bigram bigram,int frequency){
    _bigram=bigram;
    _frequency=frequency;
}

const Bigram& BigramFreq::getBigram() const{
    return _bigram;
}

int BigramFreq::getFrequency() const{
    return _frequency;
}

void BigramFreq::setBigram(const Bigram &bigram){
    _bigram=bigram;
}

void BigramFreq::setFrequency(int frequency){
    if (frequency<0){
        throw std::out_of_range(std::string("invalid frequency") + std::to_string(frequency));
    }
    else{
        _frequency=frequency;
    }
}

std::string BigramFreq::toString() const{
    return(_bigram.toString() + " " + std::to_string(_frequency));
}

void BigramFreq::serialize(std::ostream& outputStream){}
void BigramFreq::deserialize(std::istream& inputSstream){}

std::ostream operator<<(std::ostream os, BigramFreq bigramFreq){}
std::istream operator>>(std::istream is, BigramFreq bigramFreq){}
bool operator>(BigramFreq bigramFreq1, BigramFreq bigramFreq2){}
bool operator<(BigramFreq bigramFreq1, BigramFreq bigramFreq2){}
bool operator==(BigramFreq bigramFreq1, BigramFreq bigramFreq2){}
bool operator!=(BigramFreq bigramFreq1, BigramFreq bigramFreq2){}
bool operator<=(BigramFreq&bigramFreq1, BigramFreq bigramFreq2){}
bool operator>=(BigramFreq bigramFreq1, BigramFreq bigramFreq2){}