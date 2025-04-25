// ASSIG#-03 SPELL CHECKER USING HASHING
//ROLL NO: 23I-6058                  // NAME: ABDALLAH FAISAL AYOOB
// To my testing everything is working. PSA my repository file is called repository.txt, and the file containing the input is called input.txt


#include <iostream>
#include <fstream>
#include <list>
#include <string>
using namespace std;

//--------------------------------------CLASS START ------------------------------------------------//

class hashing {
private:
    list<string>* table;
    int size;
    int Num_element;
    
public:
    hashing();
    ~hashing();
    void insert();
    bool search();
    int hashfunction(string);
    void loadfactor();
};
//--------------------------------------CLASS END ------------------------------------------------//


//--------------------------------------MAIN START------------------------------------------------//
int main()
{
    hashing obj;
    obj.insert();
    obj.search();
    obj.loadfactor();
}
//--------------------------------------MAIN END ------------------------------------------------//


//--------------------------------------FUNCTION START------------------------------------------------//
hashing::hashing() {
    size = 9973; // I took the Largest prime number under 10k
    table = new list<string>[size];
    Num_element=0;
}

hashing::~hashing() {
    delete [] table;
}

int hashing::hashfunction(string key) {
    int index = 0;            
    const int base = 31; // prime number that distributes values well    
    const int tableSize = 9973;     

    for (int i = 0; i < key.length(); i++) 
    {
        index = (index * base + key[i]) % tableSize; 
    }

   
    return index % size;
}

void hashing::insert() {
    ifstream rep_file("pink.txt"); // !!!!File Name might be different!!!!

    if (!rep_file.is_open()) 
    {
        cout << "Error opening repository file" << endl;
        return;
    }

    string rep_key;

    while (getline(rep_file, rep_key))
     {
        if (!rep_key.empty()) {

            string cleaned_word = "";
            for (int i = 0; i < rep_key.length(); i++) {

                char ch= rep_key[i]; 

                if (ch >= 65 && ch <= 90) {
                    ch = ch + 32;
                }

                if (ch >= 97 && ch <= 122) {

                    cleaned_word = cleaned_word+ch; 
                }
            }

            if (!cleaned_word.empty()) {
                int index = hashfunction(cleaned_word);
                table[index].push_back(cleaned_word);

                Num_element++;
            }
        }
    }
    cout<<"---------"<<endl;
    cout<<"File read "<<endl;
     cout<<"---------"<<endl;

    rep_file.close();
}

bool hashing::search() {
    ifstream input_file("cut.txt"); //!!!!! FILE NAME MIGHT BE DIFFERENT!!!!!!
    ofstream output_file("cut.txt",ios::app);  
    if (!input_file.is_open() || !output_file.is_open()) {
        cout << "Error opening input/output file" << endl;
        return false;
    }

    string input_key;
    bool found_any = false;

    output_file << "\n\nOUTPUT: ";  
    while (getline(input_file, input_key)) {

        string current_word = "";

        for (int i = 0; i < input_key.length(); i++) {
            char ch = input_key[i];

            if (ch == ' ' || ch == '.' || ch == ',' || ch == '\n') { 
                if (!current_word.empty()) {
                    string cleaned_word = "";
                    for (int j = 0; j < current_word.length(); j++) {
                        char ch = current_word[j];
                        if (ch >= 65 && ch <= 90) {
                            ch = ch + 32;  
                        }
                        if (ch >= 97 && ch <= 122) {
                            cleaned_word = cleaned_word + ch;
                        }
                    }

                    if (!cleaned_word.empty()) {
                        int index = hashfunction(cleaned_word);
                        bool found = false;

                        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
                            const string& word_in_table = *it;
                            if (word_in_table == cleaned_word) {
                                found = true;
                                found_any = true;
                                break;
                            }
                        }

                        if (!found) {
                            string uppercase_word = "";
                            for (int i = 0; i < current_word.length(); i++) {
                                char c = current_word[i];
                                if (c >= 'a' && c <= 'z') {
                                    c = c - 32;
                                }
                                uppercase_word = uppercase_word + c;
                            }
                            current_word = uppercase_word;
                        }
                    }

                    output_file << current_word << ch;  
                    current_word = "";  
                }
            } else {
                current_word = current_word + ch;  
            }
        }

       
        if (!current_word.empty()) {
            string cleaned_word = "";
            for (int j = 0; j < current_word.length(); j++) {
                char ch = current_word[j];
                if (ch >= 65 && ch <= 90) {
                    ch = ch+32 ;  
                }
                if (ch >= 97 && ch <= 122) {
                    cleaned_word += ch;
                }
            }

            if (!cleaned_word.empty()) {
                int index = hashfunction(cleaned_word);
                bool found = false;

                for (auto it = table[index].begin(); it != table[index].end(); ++it) {
                    const string& word_in_table = *it;
                    if (word_in_table == cleaned_word) {
                        found = true;
                        found_any = true;
                        break;
                    }
                }

                if (!found) {
                    string uppercase_word = "";
                    for (int i = 0; i < current_word.length(); i++) {
                        char c = current_word[i];
                        if (c >= 'a' && c <= 'z') {
                            c = c - 32; 
                        }
                        uppercase_word = uppercase_word + c;
                    }
                    current_word = uppercase_word;
                }
            }

            output_file << current_word;  
        }

        output_file << '\n';  
    }

    input_file.close();
    output_file.close();

    cout<<"--------------------------------------"<<endl;
    cout<<"Information uploaded to input.txt file "<<endl;
     cout<<"-------------------------------------"<<endl;

    


    return found_any;
}

void hashing::loadfactor() {
    float loadfactor = static_cast<float>(Num_element) / static_cast<float>(size); // had to static cast otherwise it wasnt working properly
    cout<<"--------------------"<<endl;
    cout << "Load factor: " << loadfactor << endl;
    cout<<"--------------------"<<endl;
}


//--------------------------------------FUNCTION END ------------------------------------------------|