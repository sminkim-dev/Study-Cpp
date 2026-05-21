#include <iostream>
using namespace std;

class SortedArray {
private:
    int size;
    int *p;
    void sort() {
        if (!p || size <= 1) return;
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - 1 - i; j++) {
                if (p[j] > p[j + 1]) {
                    int temp = p[j];
                    p[j] = p[j + 1];
                    p[j + 1] = temp;
                }
            }
        }
    }
public:
    SortedArray() : p(NULL), size(0) {}

    // 복사 생성자 수정 (깊은 복사)
    SortedArray(const SortedArray& src) {
        this->size = src.size;
        if (src.p != NULL) {
            this->p = new int[this->size];
            for (int i = 0; i < size; i++) this->p[i] = src.p[i];
        } else {
            this->p = NULL;
        }
    }

    SortedArray(int p[], int size) {
        this->size = size;
        this->p = new int[size];
        for (int i = 0; i < size; i++) this->p[i] = p[i];
        sort();
    }

    ~SortedArray() { if (p) delete[] p; }

    // operator+ 인덱스 로직 수정
    SortedArray operator+(const SortedArray& op2) {
        SortedArray tmp;
        tmp.size = this->size + op2.size;
        tmp.p = new int[tmp.size];
        
        // 첫 번째 배열 복사
        for (int i = 0; i < this->size; i++) tmp.p[i] = this->p[i];
        // 두 번째 배열 복사 (인덱스 주의)
        for (int i = 0; i < op2.size; i++) tmp.p[this->size + i] = op2.p[i];
        
        tmp.sort();
        return tmp;
    }

    SortedArray &operator=(const SortedArray& op2) {
        if (this == &op2) return *this;
        delete[] p;
        this->size = op2.size;
        this->p = new int[size];
        for (int i = 0; i < size; i++) this->p[i] = op2.p[i];
        return *this;
    }

    void show() {
        cout << "배열 : ";
        for (int i = 0; i < this->size; i++) cout << this->p[i] << " ";
        cout << endl;
    }
};

int main() {
    int n[] = {2, 20, 6};
    int m[] = {10, 7, 8, 30};
    SortedArray a(n, 3), b(m, 4), c;

    c = a + b;
    
    a.show();
    b.show();
    c.show(); // 이제 정상적으로 합쳐지고 정렬되어 출력됩니다.
    return 0;
}