#include <iostream>
#include <string>

using namespace std;

class Album{
private:
    string title;
    string name;
public:
    Album(string title ="", string name = ""){this->title=title; this->name = name;}
    void setTitle(string title){this->title = title;}
    void setName(string name){this->name = name;}
    string getTitle(){return title;}
    string getName(){return name;}
};
class AlbumManager : public Album{
    Album *a;
    int size;
    public:
        AlbumManager(int size){
            this->size = size;
            this->a = new Album[size];
        }
        ~AlbumManager(){delete []a;}
        void run(){
            for(int i = 0; i < size; i++){
                string title;
                string name;
                cout << "곡명? ";
                cin.ignore(1);
                getline(cin,title,'\n');
                a[i].setTitle(title);
                cout << "가수? ";
                cin >> name;
                a[i].setName(name);
            }
            string temp;
            getline(cin, temp, '\n');
            cout << "장미 앨범에서 곡을 검색합니다." << endl;
            while(true){
                bool find = false;
                cout << "검색할 곡명 입력 >> ";
                string name;
                getline(cin, name, '\n');
                if(name == "그만") return;
                for(int i = 0; i < size; i++){
                    if(name == a[i].getTitle()){
                        cout << "가수는 " << a[i].getName() << "입니다." << endl;
                        find = true;
                        continue;
                    }
                }
                if(!find){
                    cout << name << "는/은 없는 곡입니다." << endl;
                    continue;
                }
            }
        }
};
int main(){
    cout << "장미 앨범에 곡을 저장합니다." << endl;
    cout << "곡 개수 입력 >> ";
    int size;
    cin >> size;
    AlbumManager al(size);
    al.run();

    cin.get();
}