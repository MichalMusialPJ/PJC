#include <iostream>
#include <vector>
#include <string>

auto boxPrint(std::vector<std::string> vec, char chr = '*') -> int {
    auto longestLength = 0;
    auto myChar = chr;

// Finding the longest word in vector
    for(std::string const& element : vec ){
        if(element.size() > longestLength){
            longestLength = element.size();
        }
    }

// If word shorter than longest add blank char until it has the same length
    for(std::string & element : vec){
        auto numberOfBlanks = longestLength - element.size();
        for( auto i = 0; i < numberOfBlanks; i++){
            element += " ";
        }
    }

// Printing box
    for(int i=0; i <= vec.size(); i++){
        if(i==0 || i == vec.size()){
            for(int j=0; j < longestLength + 2; j++){
                std::cout << myChar;
            }
            std::cout << "\n";
        }
        if(i != vec.size()) {
            std::cout << myChar << vec[i] << myChar << "\n";
        }
    }
    std::cout << "\n";

    return 0;
}

auto main() -> int {

//    Box print
    boxPrint({"a", "quick", "brown", "fox"});
    boxPrint({"a", "quick", "brown", "fox"}, '*');
    boxPrint({"a", "quick", "brown", "fox"}, '#');
    boxPrint(std::vector<std::string>{"a", "quick", "brown", "fox"}, '#');
    boxPrint({""});
    boxPrint({});
    boxPrint({}, '#');
    boxPrint({"", "hmmm", ""});
    boxPrint({"", "", ""});
}