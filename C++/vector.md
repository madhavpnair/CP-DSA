## Intro
- vector is a container in STL
- It can grow and shrink dynamically
- It supports random access in O(1)
```
template <typename T>
class MiniVector {
    T* arr;          // dynamic array
    int size;
    int capacity;

public:
    MiniVector() {
        size = 0;
        capacity = 1;
        arr = new T[capacity];
    }

    void push_back(T value) {
        if (size == capacity) {
            capacity *= 2;                // grow dynamically
            T* newArr = new T[capacity];

            for (int i = 0; i < size; i++)
                newArr[i] = arr[i];

            delete[] arr;
            arr = newArr;
        }

        arr[size++] = value;
    }

    T get(int index) {
        return arr[index];
    }

    int getSize() {
        return size;
    }

    ~MiniVector() {
        delete[] arr;
    }
};
```

## Safer access
### v[i] vs. v.at(i)
- `v[i]` is equivalent to `*(v.begin()+i)` which is a direct pointer arithmetic without any bounds checking and so gives undefined behaviour (crash, garbage value,overwrite memory etc.) on  out-of-bounds access.
This one is faster and preferred in CP
- `v.at[i]` checks `if (i >= size) throw out_of_range;` and accesses element. It is safer and used in production code but a bit slower due to the small runtime overhead. <br>
**We can make use of this in debugging phase to fix indexing bugs and switch back to [] for performance**.
