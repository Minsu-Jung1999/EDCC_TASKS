class Vector2 {
private:
    int capacity;
    int* data;
    int size;
    
    void copy(int* toFill, int* toCopy, int size);
public:
    Vector2();
    Vector2(int capacity);
    void append(int value);
    int getSize();
    int get(int index);
    void insert(int index, int value);    // implement this!
    {
        
    }
};