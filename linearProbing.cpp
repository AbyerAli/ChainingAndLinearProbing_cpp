#include <iostream>

using namespace std;
#define VACANT_SLOT -999999

class LinearProbing{
    int size;
    int *arr;
    unsigned int hashingFunction(int key) {
        return key % size;
    }
public:
    LinearProbing(int size) {
        this->size = size;
        arr = new int[size];
    }
    void insertData(int data) {
        int index = hashingFunction(data);
        for (int i = 0; i < size; i++)
        {   
            if(arr[index] == 0 || arr[index] == VACANT_SLOT) {
                arr[index] = data;
                return;
            }
            if(index == size-1) {
                index = 0;
            } else {
                index += 1;
            }
        }
        // empty space was not found as whole array is looped.
        cout << "the list is full" << endl;
    }
    void searchData(int data) {
        int index = hashingFunction(data);
        for (int i = 0; i < size; i++)
        {   
            if(arr[index] == data) {
                cout << "found at index: " << index << endl;
                return;
            }
            if(index == size -1) {
                index = 0;
            } else {
                index += 1;
            }
        }
        cout << "Not Found in array" << endl;
    }
    void printArray() {
        for (int i = 0; i < size; i++)
        {
            cout << "index " << i << ": " << arr[i] << endl;
        }
        
    }
};

int main() {
    LinearProbing obj(10);
    obj.insertData(5);
    obj.insertData(15);
    obj.insertData(25);
    obj.insertData(35);
    obj.insertData(45);
    obj.insertData(55);
    obj.insertData(55);
    obj.insertData(95);
    obj.insertData(95);
    obj.insertData(105);
    obj.searchData(105);
    obj.printArray();
}