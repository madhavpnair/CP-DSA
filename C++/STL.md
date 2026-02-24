# Intro
### TODO

## template class
A blueprint for creating classes to work with any data type
<br>It is like a generic class

eg :
```
template <typename T>  // here T is a placeholder for a type
class Box {
    T value;
public:
    Box(T v) { value = v; }
    T get() { return value; }
};
```
Now we can create
```
Box<int> b1(10);   // compiler replaces T with int
Box<double> b2(3.14);
Box<string> b3("hello");
```

## container
It is a template class to store and organize multiple elements efficiently

eg :
 ```
vector<int> v;
list<int> l;
set<int> s;
map<int, int> m;
```
vector as a template class
```
template <typename T>
class vector {
    // implementation
};
```
we make use of this generic class
```
vector<int>
vector<double>
vector<string>
```