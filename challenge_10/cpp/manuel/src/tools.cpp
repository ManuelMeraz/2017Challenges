#include <map>
#include <string>

#include "include/tools.h"

std::map<char, int> tools::count (std::string input) {

    std::map<char, int> counter;
    int length = input.length();

    for(int i = 0; i < length; i++) {
        if(input[i] == '(' || input[i] == '{' || input[i] == '[' || input[i] == '<') {
            // count all the openers
            counter[input[i]]++;

            // count the closers
        } else if(input[i] == ')') {
            counter['(']--;
        } else if(input[i] == '}') {
            counter['{']--;
        } else if(input[i] == ']') {
            counter['[']--;
        } else if(input[i] == '<') {
            counter['<']--;
        }

        if(counter[input[i]] < 0) {
            // If there are more closers than
            // openers, this is false

            counter.clear();
            return counter;
        }
    }

    return counter;
}

bool tools::verify_closers(std::map<char, int> counter) {

    if(counter['{'] != 0 || counter['('] != 0 || counter['['] != 0 || counter.empty()) {
        return false;
    }

    else return true;
}