#include <iostream>
#include <stack>
#include <string>

using std::stack;
using std::string;

string getSet();
void stripSpace(string set, int *p);
bool isNum(const string& st);
int convertString(const string& st);
int wordCount(string set);
void insertionSort(int n, int _array[]);
void removeDuplicates(int n, int _array[]);
//remove duplicates from set
//sort int array


int main() {


    int *p;//pointer to array of ints
    int word_count = 0; //used to dynamically generate standard string set arrays

    string set_a = "";

//    Initialize first set
    std::cout << "Please enter a set of  positive integers :\n" << std::endl;
    set_a = getSet();
    word_count = wordCount(set_a);
    //create temp array of strings using no. of words ie word count
    //pass pointer to string array along with first set to strip spaces and convert to int array
    int set_one[word_count];
    p = set_one;
    stripSpace(set_a, p);

    //    Initialize second set
    int *q;
    string set_b = "";

    std::cout << "Please enter a second set of positive integers :\n" << std::endl;
    set_b = getSet();
    int word_count_two = wordCount(set_b);
    int set_two[word_count_two];
    q = set_two;
    stripSpace(set_b, q);

    for (int i = 0; i < word_count; i++)
        std::cout<< set_one[i] <<' ';

    std::cout<< '\n';

    for (int i = 0; i < word_count_two; i++)
        std::cout<< set_two[i] <<' ';

    std::cout<< '\n';

    insertionSort(word_count, set_one);

    std::cout<< "Post Insertion Sort " <<std::endl;

    for (int i = 0; i < word_count; i++)
        std::cout<< set_one[i] <<' ';

    std::cout<< '\n';

    removeDuplicates(word_count, set_one);

    std::cout<< "Post Removal " <<std::endl;

    for (int i = 0; i < word_count; i++)
        if (set_one[i] != -1)
         std::cout<< set_one[i] <<' ';
    p = NULL;
    q = NULL;
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


void stripSpace(string set, int *p)
{
    string unique_set;
    int index = 0;
    std::stack <int> numbers;

    bool _go = true;
    while (_go){
        index = set.find(" ");
        if (index == string::npos) {_go = false;}
        //check for numeric properties
        //if yes push on int stack
        string temp = set.substr(0, index);

        if (isNum(temp))
            numbers.push(convertString(temp));
            //first_words.push(temp);
        set = set.substr(index+1, set.length());
    }

    int _size = numbers.size();

    int new_set[_size];

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

int convertString(const string& st){
    try {
        std::string::size_type reference;
        return  std::stof (st, &reference);
    }
    catch (int e)
    {
        return -1;
    }

}


void insertionSort(int n, int _array[]){
    int i, j;
    int x;
    for (i=0; i < n; i++){
        x = _array[i];
        j = i-1;
        while (j >= 0 && _array[j] > x){
            _array[j+1] = _array[j];
            j--;
        }
        _array[j+1] = x;

    }
}

void removeDuplicates(int n, int _array[]) {
    int i, j;
    for (i=0; i<n; i++){
        for(j=i+1; j<n; j++)
            if(_array[i] == _array[j])
                _array[j] = -1;
    }
}