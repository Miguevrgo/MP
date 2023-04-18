/*
 * Metodología de la Programación: Language3
 * Curso 2022/2023
 */

/* 
 * File:   main.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 *
 * Created on 7 de febrero de 2023, 14:02
 */

#include "Language.h"


/**
 * Shows help about the use of this program in the given output stream
 * @param outputStream The output stream where the help will be shown (for example,
 * cout, cerr, etc) 
 */
void showEnglishHelp(std::ostream& outputStream) {
    outputStream << "Error, run with the following parameters:" << std::endl;
    outputStream << "language3 [-t min|max] <file1.bgr> <file2.bgr> [ ... <filen.bgr>]" << std::endl;
}

/**
 * This program reads an undefined number of Language objects from the set of 
 * files passed as parameters to main(). All the Languages object, except the 
 * first one, must be stored in a dynamic array of Language objects. Then, 
 * for each Language in the dynamic array, this program prints to the 
 * standard output the name of the file of that Language and the distance from 
 * the first Language to the current Language. 
 * Finally, the program should print in the standard output, the name of 
 * the file with the Language with the minimum|maximum distance to the Language 
 * of the first file and its language identifier.
 * 
 * At least, two Language files are required to run this program.
 * Running example:
 * > language3 [-t min|max] <file1.bgr> <file2.bgr> [  ... <filen.bgr>] 
 */
int main(int argc, char* argv[]) {

    //Checks that the program has been called with at least 3 parameters
    if (argc < 3 ) {
        showEnglishHelp(std::cerr);
        return 1;
    }

    //Creates the language used as a reference
    Language ref_language;
    ref_language.load(argv[1]);
   
    //Creates dynamic language array
    Language* languages=nullptr;
    languages = new Language[argc-2];
    
    //Loads each language into the array
    for (int i=2;i<argc;i++){
        languages[i-2].load(argv[i]);
    }
    
    //Prints distance between texts and calculates nearest
    double min_dist=100;
    double distance;
    int min_index;
    for (int i = 0; i < argc-2; i++) {
        distance = ref_language.getDistance(languages[i]);
        if(distance < min_dist){
            min_dist=distance;
            min_index=i;
        }
        std::cout << "Distance to " << argv[i+2] << ": " << distance << std::endl;
    }

    std::cout << "Nearest language file: " << argv[min_index+2] << std::endl;
    std::cout << "Identifier of the nearest language: " << languages[min_index].getLanguageId() << std::endl;
    
    delete[] languages;
    return 0;
}