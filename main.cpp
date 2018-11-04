#include <iostream>
#include <stack>
#include <string>

using std::stack;
using std::string;

string getSet();
void stripSpace(string set, float *p);
bool isNum(const string& st);
float convertString(const string& st);
int wordCount(string set);
//remove duplicates from set
//sort float array


int main() {


    float *p;//pointer to array of floats
    int word_count = 0; //used to dynamically generate standard string set arrays

    string set_a = "";

//    Initialize first set
    std::cout << "Please enter a set of characters/tokens :\n" << std::endl;
    set_a = getSet();
    word_count = wordCount(set_a);
    //create temp array of strings using no. of words ie word count
    //pass pointer to string array along with first set to strip spaces and convert to float array
    float set_one[word_count];
    p = set_one;
    stripSpace(set_a, p);

    //    Initialize second set
    float *q;
    string set_b = "";

    std::cout << "Please enter a second set of characters/tokens :\n" << std::endl;
    set_b = getSet();
    word_count = wordCount(set_b);
    float set_two[word_count];
    q = set_two;
    stripSpace(set_b, q);

    for (int i = 0; i < word_count; i++)
        std::cout<< set_two[i] <<' ';

    p = NULL;

    return 0;
}


string getSet()
{
    string set;
    getline(std::cin, set);
    return set;
}

int wordCount(string set){
    int index = 0;
    int counter = 0;
    bool _go = true;
    while (_go){
        index = set.find(" ");
        if (index == string::npos) {_go = false;}
        //check for numeric value before counting
        string temp = set.substr(0, index);
        if (isNum(temp))
            counter++;
        set = set.substr(index+1, set.length());
    }
   return counter;
}


void stripSpace(string set, float *p)
{
    string unique_set;
    int index = 0;
    std::stack <float> numbers;

    bool _go = true;
    while (_go){
        index = set.find(" ");
        if (index == string::npos) {_go = false;}
        //check for numeric properties
        //if yes push on float stack
        string temp = set.substr(0, index);

        if (isNum(temp))
            numbers.push(convertString(temp));
            //first_words.push(temp);
        set = set.substr(index+1, set.length());
    }

    int _size = numbers.size();

    float new_set[_size];

    for (int i =_size-1;i >= 0;i--){
        new_set[i] = numbers.top();
        numbers.pop();
    }

    //return new_set;
    for (int i =0;i < _size;i++){
        *p = new_set[i];
        p++;
    }
}

bool isNum(const string& st){
    for (int i=0;i<st.size();i++)
        if (!isdigit(st[i]))
            return false;
    return true;
}

float convertString(const string& st){
    std::string::size_type reference;
    return  std::stof (st, &reference);
}
