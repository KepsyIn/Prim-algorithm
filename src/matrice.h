#include <iostream>

class matrice {
    private:
        int **data;
        int size;
        void init();
    public:
        matrice() : size(0), data(nullptr) {};
        matrice(int s);
        ~matrice(){
                for (int i = 0; i < size; ++i) {
                    delete[] data[i];
                }
                delete[] data;
        };
        void createMatrice(int size);
        void setVal(int l, int c, int val);
        void print();
        int* operator[](unsigned int index) const {
            if (index >= size) {
                throw std::runtime_error("index out of bounds");
            }
            return data[index];
        }
        matrice& operator=(const matrice& mat) {

            for (int i = 0; i < size; ++i) {
                    delete[] data[i];
                }
                delete[] data;

                size = mat.size;
                data = new int*[size];
                
                for (int i = 0; i < size; ++i) {
                    data[i] = new int[size];
                    for (int j = 0; j < size; ++j) {
                        data[i][j] = mat.data[i][j];
                    }
                }
            return *this;
        }
        bool operator==(const matrice& other) const {
            if (size != other.size) {
                return false;
            }

            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    if (data[i][j] != other.data[i][j]) {
                        return false;
                    }
                }
            }

            return true;
        }

        bool operator!=(const matrice& other) const {
            return !(*this == other);
        }

};