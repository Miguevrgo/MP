/*
 * Metodología de la Programación: Language3
 * Curso 2022/2023
 */

/** 
 * @file Language.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * 
 * Created on 12 February 2023, 10:40
 */

#include "Language.h"

const std::string Language::MAGIC_STRING_T="MP-LANGUAGE-T-1.0";

Language::Language(): _languageId("unknown"),_size(0){}

Language::Language(int numberBigrams){
    if(numberBigrams>DIM_VECTOR_BIGRAM_FREQ){
        throw std::out_of_range(std::string("Language::Language(int numberBigrams)") +
         "invalid number of bigrams" + std::to_string(numberBigrams));
    }
    else{
        _languageId="unknown";
        _size=numberBigrams;
    }
   
}

const std::string& Language::getLanguageId() const{
    return _languageId;
}

void Language::setLanguageId(std::string id){
    _languageId=id;
}