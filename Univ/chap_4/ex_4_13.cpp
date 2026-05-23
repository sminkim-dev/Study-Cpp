#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Histogram{
    private:
        string fullText;
    public:
        Histogram(string line){this->fullText = line;}
        void add(string text){
            this->fullText += text;
        }
        void addc(string sign){
            this->fullText += sign;
        }
        void draw(){
            cout << fullText << endl;

            int totalAlpabets = 0;
            int counts[26] = {0};

            
            for(int i = 0; i < fullText.length(); i++){
                char c = fullText[i];
                if(isalpha(c)){
                    c = tolower(c);
                    counts[c - 'a']++;
                    totalAlpabets++;
                }
            }
            cout << "총 알파벳 수 " << totalAlpabets << endl << endl;
            
            for(int i = 0; i < 26; i++){
                char alphabet = 'a' + i;
                cout << alphabet << " (" << counts[i] << ")\t: ";

                for(int j = 0; j < counts[i]; j++){
                    cout << "*";
                }
                cout << "\n";
            }

        }
};

int main(){
    Histogram histo("You fill up my senses, like a night in a forest\n");
    histo.add("like the mountains in springtime, like a walk in the rain\n");
    histo.addc("-");
    histo.add("annie's song by john denver");
    histo.draw();

    cin.clear();
    cin.ignore(100,'\n');
    cin.get();
}