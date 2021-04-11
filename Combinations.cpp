#include <iostream>
#include <windows.h>
#include <string>
#include <time.h>
#include "wordlist.h"

const char* alphabet = "abcdefghijklmnopqrstuvwxyz";
const char* consonants = "bcdfghjklmnprstvwxyz";
const char* vowels = "aeiou";
const char* commonVowels = "ae";
 
std::string generator(int maxWordLength, int maxVowels){
	//srand(time(NULL));
	int wordLength = 0;
	int vowelCount = 0;
	std::string word;
	
	wordLength = rand() % maxWordLength;
		
	for (int i = 0; i < wordLength; i++){
        if(rand() % 2 == 1 && vowelCount < maxVowels){
            int vowelChoice = rand() % 5;
	        int betterVowelChoice = rand() % 2;
				
	        if(rand() % 5 > 2){
				word.push_back(commonVowels[betterVowelChoice]);
			}
			else{
				word.push_back(vowels[vowelChoice]);
			}
				
			vowelCount++;
	   }
		else {
			word.push_back(consonants[(int)rand() % 21]);
		}
	}
	
	return std::string(word);
 }
 
std::string pureRandomGenerator(int maxWordLength){
	//srand(time(NULL));
	int wordLength = 0;
	std::string word;
	
	wordLength = rand() % maxWordLength;
		
	for (int i = 0; i < wordLength; i++){
        word.push_back(alphabet[(int)rand() % 26]);
	}
	
	return std::string(word);
 }

int main(){
	int length = 0;
	int vowelCount = 0;
	int wordsFound = 0;
	int minWordLength = 0;
	int stringCount = 0;
	char choice;
	int j = 0;
	
	std::string generatedWord;
	std::vector<std::string> realWords;
	
	wordlist Words("google-10000-english-master/google-10000-english-master/20k.txt");
	
	while(true){
		std::cout << "Enter max word length: ";
		std::cin >> length;
		
		std::cout << "\nPure random[Y] or semi-random[N]? \n>";
		std::cin >> choice;
		
		if(choice == 'N' || choice == 'n'){
		  std::cout << "\nEnter max vowel count: ";
		  std::cin >> vowelCount;
        }
        
        std::cout << "\nEnter minimum valid word length: ";
        std::cin >> minWordLength;
        Words.setMinLenght(minWordLength);
        
        std::cout << "\nEnter number of strings to generate: ";
        std::cin >> stringCount;
        
		srand(time(NULL));
		
		for(int i = 0; i < stringCount; i++){
			j++;
			
			choice == 1 ? generatedWord = pureRandomGenerator(length+1) : generatedWord = generator(length+1, vowelCount);

			std::cout << generatedWord << " ";
			
			j%6 == 0 ? std::cout << std::endl : std::cout << "";
			
			if(Words.checkWord(generatedWord)){
                wordsFound++;
                realWords.push_back(generatedWord);
			}		
		}
		
		std::cout << "\n\n\n";
		std::cout << "-------------------------------------------------------------------------" << "\n\n";
		std::cout << "---> " << wordsFound << " words found <---\n";
		std::cout << "---> " << (double) wordsFound / stringCount * 100 << "% of "<< stringCount << " strings generated <---\n\n";
		std::cout << "Words generated: \n\n";
	
        j = 0;
        
		for(int i = 0; i < realWords.size(); i++){
			j++;
			std::cout << "\t" << realWords[i] << " ";
			
		    if (j % 6 == 0){
			   std::cout << std::endl;	   
		   }
		}
		
		wordsFound =  0;
		realWords.clear();
		std::cout << std::endl << std::endl;
		
		system("pause");
		system("cls");
	}
	
	return 0;
}
