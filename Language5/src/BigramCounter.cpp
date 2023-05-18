/*
 * Metodología de la Programación: Language5
 * Curso 2022/2023
 */

/** 
 * @file BigramCounter.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * 
 * Created on 12 February 2023, 11:00
 */

#include "BigramCounter.h"

/**
 * DEFAULT_VALID_CHARACTERS is a c-string that contains the set of characters
 * that will be considered as part of a word (valid chars). 
 * The characters not in the c-string will be considered as separator of words.
 * The constructor of the class BigramCounter uses this c-string as a 
 * default parameter. It is possible to use a different c-string if that
 * constructor is used with a different c-string
 */
const char* const BigramCounter::DEFAULT_VALID_CHARACTERS="abcdefghijklmnopqrstuvwxyz\xE0\xE1\xE2\xE3\xE4\xE5\xE6\xE7\xE8\xE9\xEA\xEB\xEC\xED\xEE\xEF\xF0\xF1\xF2\xF3\xF4\xF5\xF6\xF8\xF9\xFA\xFB\xFC\xFD\xFE\xFF";

BigramCounter::BigramCounter(std::string validChars){
    int length = validChars.length(); // Length of the string validChars 
    
    allocate(length);

    //Initialize the array to 0
    for (int i=0;i<length;i++){
        for (int j=0;j<length;j++){
            _frequency[i][j] = 0;
        }
    }
}
BigramCounter::BigramCounter(const BigramCounter &orig){
    this->allocate(orig.getSize());
    this->_validCharacters =orig._validCharacters;
    for (int i=0;i<orig.getSize();i++){
        for (int j=0;j<orig.getSize();j++){
            _frequency[i][j]=orig._frequency[i][j];
        }
    }
}

BigramCounter::~BigramCounter(){
    deallocate();
}

int BigramCounter::getNumberActiveBigrams() const{
    unsigned int length = _validCharacters.length();
    unsigned int counter = 0;
    for (int i=0;i<length;i++){
        for (int j=0;j<length;j++){
            if (_frequency[i][j] > 0){
                counter++;
            }
        }
    }
    return counter;
}

bool BigramCounter::setFrequency(const Bigram &bigram, int frequency){
    int pos = findBigramPos(bigram);
    bool found = false;
    if (pos!=-1){
        this->_frequency[pos/10][pos%10]=frequency;
        found = true;
    }
    return (found);
}

void BigramCounter::increaseFrequency(const Bigram &bigram, int frequency){
    int pos = findBigramPos(bigram);
    if (pos!=-1){
        this->_frequency[pos/10][pos%10]++;
    }
}

BigramCounter& BigramCounter::operator=(const BigramCounter &orig){
    if (this!=&orig){
        this->deallocate();
        this->allocate(orig.getSize());
        this->_validCharacters = orig._validCharacters;
        for (int i=0;i<orig.getSize();i++){
            for (int j=0;j<orig.getSize();j++){
                this->_frequency[i][j] = orig._frequency[i][j];
            }
        }
    }
    /*
    else{
        throw std::invalid_argument(std::string("BigramCounter& BigramCounter::operator=(const BigramCounter &orig)"))
         + "Cannot assign object to itself.");
    }
     */
    return *this;
}

BigramCounter& BigramCounter::operator+=(const BigramCounter &rhs){
    for (int i=0;i<getSize();i++){
        for (int j=0;j<getSize();j++){
            this->_frequency[i][j] += rhs._frequency[i][j];
        }
    }

    return *this;
}

void BigramCounter::calculateFrequencies(const char *const fileName){}
Language BigramCounter::toLanguage() const{}

const int& BigramCounter::operator()(int row, int column) const{
    return _frequency[row][column];
}

int& BigramCounter::operator()(int row, int column){
    return _frequency[row][column];
}

void BigramCounter::allocate(int n_elements){
    _frequency = new int*[n_elements];
    _frequency[0] = new int[n_elements*n_elements];
    for (int i=1;i<n_elements;++i){
        _frequency[i]=_frequency[i-1]+n_elements;
    }
}

int BigramCounter::findBigramPos(const Bigram &bigram) const{
    int pos;
    bool found_x = false;
    bool found_y = false; 
    for (int i=0;i<_validCharacters.length();i++){
        if (_validCharacters[i]==bigram.getText().at(0)){
            pos += i*10;
            found_x = true;
        }
        if (_validCharacters[i]==bigram.getText().at(1)){
            pos += i;
            found_y = true;
        }
    }
    if (!(found_x && found_y)){
        pos=-1;
    }
    return pos;
}

void BigramCounter::deallocate(){
    delete [] _frequency[0];
    delete [] _frequency;
    _frequency=nullptr;
}