// Ash Nguyen
// CIS-17B-S25-33477
// 5/25/25
// Assignment 5 Template Types and Generics

#include <iostream>
#include <string>
#include <array>
#include <typeinfo>

using namespace std;

//Generic Package<T>
template<typename T>
class Package
{
private:
    T item; // item in package
public:
    Package(T i) : item(i) {}
    void label()
    {
        // label of what the package containts
        cout << "Generic package containing: " << typeid(T).name() << "\n";
    }
};

//Specialization for strings
template<>
class Package<string>
{
private:
    string item;
public:
    Package(string i) : item(i) {}
    // label of the package
    void label()
    {
        cout << "Book package: \"" << item << "\"\n";
    }
};

// Partial Specialization for Pointer Types
template<typename T>
class Package<T*>
{
private:
    T* item;
public:
    Package(T* i) : item(i) {}
    // label that the package is fragile
    void label()
    {
        cout << "Fragile package for pointer to type: " << typeid(T).name() << "\n";
    }
};

// Box Class Template
template<typename T, int Size>
class Box
{
private:
    array<T, Size> items;
    int count = 0;
public:
    bool addItem(const T& item)
    {
        if (count < Size)
        {
            items[count++] = item;
            cout << "Added item to box: \"" << item << "\"\n";
            return true;
        }
        else
        {
            cout << "Box is full! Cannot add item: \"" << item << "\"\n";
            return false;
        }
    }

    void printItems() const
    {
        // what's currently in the box
        cout << "Box contents:\n";
        for (int i = 0; i < count; ++i) {
            cout << " - " << items[i] << "\n";
        }
    }
};

// Function Template
template<typename T>
void shipItem(const T& item)
{
    cout << "Shipping item of type: " << typeid(T).name() << "\n";
}

// Function Template Specialization for double
template<>
void shipItem(const double& item)
{
    // double is temperature controlled item
    cout << "Shipping temperature-controlled item: " << item << "°C\n";
}

// Function Template Specialization for std::string
template<>
void shipItem(const string& item)
{
    cout << "Shipping item of type: std::string\n";
}

int main()
{
    cout << "\n        Congo Smart Packaging System\n";
    cout << "===============================================\n";
    Package<int> intPackage(42);
    intPackage.label();

    Package<string> bookPackage("Code Languages");
    bookPackage.label();

    double temp = 28.5;
    Package<double*> fragilePackage(&temp);
    fragilePackage.label();

    cout << "-------------------------\n";


    Box<string, 3> bookBox;
    bookBox.addItem("C++");
    bookBox.addItem("Java");
    bookBox.addItem("C#");
    bookBox.addItem("Python"); // Should not be added
    bookBox.printItems();

    cout << "-------------------------\n";

    // shipItem calls
    shipItem(10);
    shipItem(string("Program"));
    shipItem(28.5); // double specialization

    return 0;
}


