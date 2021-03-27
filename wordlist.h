#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <windows.h>
#include <time.h>

class wordlist{
	private:
		std::vector<std::string> words;
		int minimumLength;
	public:
		wordlist(const char* file)
		:minimumLength(2)
		{
			std::ifstream readIn(file);
			std::string word;
			
			if(readIn.is_open()){
				while(std::getline(readIn, word)){
	   			    words.push_back(word);
				}
				readIn.close();
			}
			else{
				std::cout << "Error! Failed to load file!" << std::endl;
				this->~wordlist();
				delete this;
			}
		}
		
		void setMinLenght(int minLength){
			minimumLength = minLength;
		}
		
		bool checkWord(std::string& charString){
			for(int i = 0; i < words.size(); i++){
				if(words[i] == charString && charString.length() >= minimumLength){//we're only counting words longer than the minimumLength
					return true;
				}
			}
			return false;
		}
		
		std::string getRandomWord(){
			srand(time(NULL));
			return words[(int)rand()%words.size()];
		}
		
		~wordlist(){
			words.clear();
		}
			
};

