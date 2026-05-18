//Ryan Ramdihal C++ Week 1 Assignment
#include <iostream>
#include <cstring>
#include <string>

using namespace std;
using std:: endl; //removes std from endl
using std::cout; //removes std from cout
using std::cin; //removes std from cin

/*
1. Define a class student with the following specification
Private members of class student
admno                        integer
sname                        20 character
eng. math, science       float
total                            float
ctotal()                        a function to calculate eng + math + science with float return type.
Public member function of class student
Takedata()                   Function to accept values for admno, sname, eng, science and invoke ctotal() to calculate total.
Showdata()                   Function to display all the data members on the screen.
*/
class student {
private:
    int admno;
    char sname[20];
    float eng, math, science, total;

    float ctotal() {
        return eng + math + science;
    }

public:
    void Takedata() {
        std::cout << "Enter admission number: ";
        std::cin >> admno;
        std::cout << "Enter student name: ";
        std::cin.ignore();
        std::cin.getline(sname, 20);
        std::cout << "Enter marks in English: ";
        std::cin >> eng;
        std::cout << "Enter marks in Math: ";
        std::cin >> math;
        std::cout << "Enter marks in Science: ";
        std::cin >> science;
        total = ctotal();
    }

    void Showdata() {
        std::cout << "Admission number: " << admno << std::endl;
        std::cout << "Student name: " << sname << std::endl;
        std::cout << "Marks in English: " << eng << std::endl;
        std::cout << "Marks in Math: " << math << std::endl;
        std::cout << "Marks in Science: " << science << std::endl;
        std::cout << "Total marks: " << total << std::endl;
    }
};





/*
2.  Define a class batsman with the following specifications:
Private members:
bcode                            4 digits code number
bname                           20 characters
innings, notout, runs        integer type
batavg                           it is calculated according to the formula –
                                     batavg =runs/(innings-notout)
calcavg()                        Function to compute batavg
Public members:
readdata()                      Function to accept value from bcode, name, innings, notout and invoke the function                                       calcavg()
displaydata()                   Function to display the data members on the screen.
*/

class batsman {
    private:
        int bcode;
        char bname[20];
        int innings, notout, runs;
        float batavg;
    
        void calcavg() {
            if (innings - notout > 0) {
                batavg = static_cast<float>(runs) / (innings - notout);
            } else {
                batavg = 0;
            }
        }
    
    public:
        void readdata() {
            std::cout << "Enter batsman code (4 digits): ";
            std::cin >> bcode;
            std::cout << "Enter batsman name: ";
            std::cin.ignore();
            std::cin.getline(bname, 20);
            std::cout << "Enter number of innings: ";
            std::cin >> innings;
            std::cout << "Enter number of not outs: ";
            std::cin >> notout;
            std::cout << "Enter number of runs: ";
            std::cin >> runs;
            calcavg();
        }
    
        void displaydata() {
            std::cout << "Batsman code: " << bcode << std::endl;
            std::cout << "Batsman name: " << bname << std::endl;
            std::cout << "Innings: " << innings << std::endl;
            std::cout << "Not outs: " << notout << std::endl;
            std::cout << "Runs: " << runs << std::endl;
            std::cout << "Batting average: " << batavg << std::endl;
        }
    };
    
/*
3. Define a class TEST in C++ with following description:
Private Members
TestCode of type integer
Description of type string
NoCandidate of type integer
CenterReqd (number of centers required) of type integer
A member function CALCNTR() to calculate and return the number of centers as
(NoCandidates/100+1)
Public Members
-  A function SCHEDULE() to allow user to enter values for TestCode, Description, NoCandidate & call function CALCNTR() to calculate the number of Centres
- A function DISPTEST() to allow user to view the content of all the data members
*/

class TEST {
private:
    int TestCode;
    std::string Description;
    int NoCandidate;
    int CenterReqd;

    int CALCNTR() {
        return (NoCandidate / 100+1);
    }

public:
    void SCHEDULE() {
        std::cout << "Enter Test Code: ";
        std::cin >> TestCode;
        std::cin.ignore(); 
        std::cout << "Enter Description: ";
        std::getline(std::cin, Description);
        std::cout << "Enter Number of Candidates: ";
        std::cin >> NoCandidate;
        CenterReqd = CALCNTR();
    }

    void DISPTEST() {
        std::cout << "Test Code: " << TestCode << std::endl;
        std::cout << "Description: " << Description << std::endl;
        std::cout << "Number of Candidates: " << NoCandidate << std::endl;
        std::cout << "Number of Centers Required: " << CenterReqd << std::endl;
    }
};




/*
4.  Define a class in C++ with following description:
Private Members
A data member Flight number of type integer
A data member Destination of type string
A data member Distance of type float
A data member Fuel of type float
A member function CALFUEL() to calculate the value of Fuel as per the following criteria
            Distance                                                          Fuel
            <=1000                                                           500
            more than 1000  and <=2000                          1100
            more than 2000                                              2200
Public Members
A function FEEDINFO() to allow user to enter values for Flight Number, Destination, Distance & call function CALFUEL() to calculate the quantity of Fuel
A function SHOWINFO() to allow user to view the content of all the data members.
*/

class Flight {
private:
    int FlightNumber;
    std::string Destination;
    float Distance;
    float Fuel;

    void CALFUEL() {
        if (Distance <= 1000) {
            Fuel = 500;
        } else if (Distance <= 2000) {
            Fuel = 1100;
        } else {
            Fuel = 2200;
        }
    }

public:
    void FEEDINFO() {
        std::cout << "Enter Flight Number: ";
        std::cin >> FlightNumber;
        std::cin.ignore(); 
        std::cout << "Enter Destination: ";
        std::getline(std::cin, Destination);
        std::cout << "Enter Distance: ";
        std::cin >> Distance;
        CALFUEL();
    }

    void SHOWINFO() {
        std::cout << "Flight Number: " << FlightNumber << std::endl;
        std::cout << "Destination: " << Destination << std::endl;
        std::cout << "Distance: " << Distance << std::endl;
        std::cout << "Fuel: " << Fuel << std::endl;
    }
};


/*
5. Define a class BOOK with the following specifications :
Private members of the class BOOK are
BOOK NO                integer type
BOOKTITLE             20 characters
PRICE                     float (price per copy)
TOTAL_COST()        A function to calculate the total cost for N number of copies where N is passed to the function as argument.
Public members of the class BOOK are
INPUT()                   function to read BOOK_NO. BOOKTITLE, PRICE
PURCHASE()            function to ask the user to input the number of copies to be purchased. It invokes TOTAL_COST() and prints the total cost to be paid by the user.
Note : You are also required to give detailed function definitions.
*/

class BOOK {
private:
    int BOOK_NO;
    char BOOKTITLE[20];
    float PRICE;

    float TOTAL_COST(int N) {
        return PRICE * N;
    }

public:
    void INPUT() {
        std::cout << "Enter Book Number: ";
        std::cin >> BOOK_NO;
        std::cin.ignore(); // To ignore the newline character left in the buffer
        std::cout << "Enter Book Title: ";
        std::cin.getline(BOOKTITLE, 20);
        std::cout << "Enter Price per Copy: ";
        std::cin >> PRICE;
    }

    void PURCHASE() {
        int N;
        std::cout << "Enter the number of copies to be purchased: ";
        std::cin >> N;
        float totalCost = TOTAL_COST(N);
        std::cout << "Total cost to be paid: " << totalCost << std::endl;
    }
};


/*
6. Define a class REPORT with the following specification:
Private members :
adno                         4 digit admission number
name                        20 characters
marks                       an array of 5 floating point values
average                    average marks obtained
GETAVG()                 a function to compute the average obtained in five subject
Public members:
READINFO()              function to accept values for adno, name, marks. Invoke the function GETAVG()            
DISPLAYINFO()          function to display all data members of report on the screen.
You should give function definitions.
*/

class REPORT {
private:
    int adno;
    char name[20];
    float marks[5];
    float average;

    void GETAVG() {
        float sum = 0;
        for (int i = 0; i < 5; ++i) {
            sum += marks[i];
        }
        average = sum / 5;
    }

public:
    void READINFO() {
        std::cout << "Enter admission number (4 digits): ";
        std::cin >> adno;
        std::cin.ignore(); // To ignore the newline character left in the buffer
        std::cout << "Enter name: ";
        std::cin.getline(name, 20);
        std::cout << "Enter marks for 5 subjects: ";
        for (int i = 0; i < 5; ++i) {
            std::cin >> marks[i];
        }
        GETAVG();
    }

    void DISPLAYINFO() {
        std::cout << "Admission number: " << adno << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Marks: ";
        for (int i = 0; i < 5; ++i) {
            std::cout << marks[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "Average marks: " << average << std::endl;
    }
};



/*
7. Write the definition for a class called Rectangle that has floating point data members length and width. The class has the following member functions:
void setlength(float) to set the length data member
void setwidth(float) to set the width data member
float perimeter() to calculate and return the perimeter of the rectangle
float area() to calculate and return the area of the rectangle
void show() to display the length and width of the rectangle
int sameArea(Rectangle) that has one parameter of type Rectangle. sameArea returns 1 if the two Rectangles have the same area, and returns 0 if they don't.

a. Write the definitions for each of the above member functions.
b. Write main function to create two rectangle objects. Set the length and width of the first rectangle to 5 and 2.5. Set the length     and width of the second rectangle to 5 and 18.9. Display each rectangle and its area and perimeter.
c. Check whether the two Rectangles have the same area and print a message indicating the result. Set the length and width of the     first rectangle to 15 and 6.3. Display each Rectangle and its area and perimeter again. Again, check whether the two     Rectangles have the same area and print a message indicating the result.
*/

class Rectangle {
private:
    float length;
    float width;

public:
    void setlength(float l) {
        length = l;
    }

    void setwidth(float w) {
        width = w;
    }

    float perimeter() const {
        return 2 * (length + width);
    }

    float area() const {
        return length * width;
    }

    void show() const {
        std::cout << "Length: " << length << ", Width: " << width << std::endl;
    }

    int sameArea(const Rectangle& other) const {
        return area() == other.area();
    }
};

/*
8. Write the definition for a class called complex that has floating point data members for storing real and imaginary parts. The class has the following member functions:
void set(float, float) to set the specified value in object
void disp() to display complex number object
complex sum(complex) to sum two complex numbers & return complex number
a. Write the definitions for each of the above member functions.
b. Write main function to create three complex number objects. Set the value in two objects and call sum() to calculate sum and assign it in third object. Display all complex numbers.
*/

class complex {
private:
    float real;
    float imag;

public:
    void set(float r, float i) {
        real = r;
        imag = i;
    }

    void disp() const {
        std::cout << real << " + " << imag << "i" << std::endl;
    }

    complex sum(const complex& c) const {
        complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }
};


/*
9. Write the definition for a class called Distance that has data member feet as integer  and inches as float. The class has the following member functions:
void set(int, float) to give value to object
void disp() to display distance in feet and inches
Distance add(Distance) to sum two distances & return distance
1. Write the definitions for each of the above member functions.
2. Write main function to create three Distance objects. Set the value in two objects and call add() to calculate sum and assign it in third object. Display all distances. 
*/

class Distance {
private:
    int feet;
    float inches;

public:
    void set(int f, float i) {
        feet = f;
        inches = i;
    }

    void disp() const {
        std::cout << feet << " feet " << inches << " inches" << std::endl;
    }

    Distance add(const Distance& d) const {
        Distance temp;
        temp.inches = inches + d.inches;
        temp.feet = feet + d.feet + static_cast<int>(temp.inches / 12);
        temp.inches = static_cast<int>(temp.inches) % 12 + (temp.inches - static_cast<int>(temp.inches));
        return temp;
    }
};

/*
10. Write the definition for a class called time that has hours and minutes as integer. The class has the following member functions:
void settime(int, int) to set the specified value in object
void showtime() to display time object
time sum(time) to sum two time object & return time
1. Write the definitions for each of the above member functions.
2. Write main function to create three time objects. Set the value in two objects and call sum() to calculate sum and assign it in third object. Display all time objects. 
*/
class Time {
    private:
        int hours;
        int minutes;
    
    public:
        void settime(int h, int m) {
            hours = h;
            minutes = m;
        }
    
        void showtime() const {
            std::cout << hours << " hours " << minutes << " minutes" << std::endl;
        }
    
        Time sum(const Time& t) const {
            Time temp;
            temp.minutes = minutes + t.minutes;
            temp.hours = hours + t.hours + temp.minutes / 60;
            temp.minutes %= 60;
            return temp;
        }
    };
    




int main() {
    /*
    //1
    student s;
    std::cout << "Question 1:\n ";

    s.Takedata(); //take in data
    s.Showdata();


    //2
    batsman b;
    std::cout << "Question 2:\n ";

    b.readdata(); //take in data
    b.displaydata();

    //3
    TEST t;
    std::cout << "Question 3:\n ";

    t.SCHEDULE(); //take in data
    t.DISPTEST();

    //4
    Flight f;
    std::cout << "Question 4:\n ";

    f.FEEDINFO(); //take in data
    f.SHOWINFO();

    //5
    std::cout << "Question 5:\n ";

    BOOK book;
    book.INPUT(); //take in data
    book.PURCHASE(); //amount of books to purchase

    //6
    std::cout << "Question 6:\n ";

    REPORT r;
    r.READINFO(); //take in data
    r.DISPLAYINFO();
    */

    //7
    Rectangle rect1, rect2;
    std::cout << "Question 7:\n ";


    // Set length and width of the first rectangle
    rect1.setlength(5);
    rect1.setwidth(2.5);
    // Set length and width of the second rectangle
    rect2.setlength(5);
    rect2.setwidth(18.9);

    // Display each rectangle and its area and perimeter
    std::cout << "Rectangle 1:" << std::endl;
    rect1.show();
    std::cout << "Area: " << rect1.area() << ", Perimeter: " << rect1.perimeter() << std::endl;

    std::cout << "Rectangle 2:" << std::endl;
    rect2.show();
    std::cout << "Area: " << rect2.area() << ", Perimeter: " << rect2.perimeter() << std::endl;

    // Check whether the two rectangles have the same area
    if (rect1.sameArea(rect2)) {
        std::cout << "Rectangle 1 and Rectangle 2 have the same area." << std::endl;
    } else {
        std::cout << "Rectangle 1 and Rectangle 2 do not have the same area." << std::endl;
    }

    // Set new length and width of the first rectangle
    rect1.setlength(15);
    rect1.setwidth(6.3);

    // Display each rectangle and its area and perimeter again
    std::cout << "Rectangle 1 (updated):" << std::endl;
    rect1.show();
    std::cout << "Area: " << rect1.area() << ", Perimeter: " << rect1.perimeter() << std::endl;

    std::cout << "Rectangle 2:" << std::endl;
    rect2.show();
    std::cout << "Area: " << rect2.area() << ", Perimeter: " << rect2.perimeter() << std::endl;

    // Check whether the two rectangles have the same area again
    if (rect1.sameArea(rect2)) {
        std::cout << "Rectangle 1 and Rectangle 2 have the same area." << std::endl;
    } else {
        std::cout << "Rectangle 1 and Rectangle 2 do not have the same area." << std::endl;
    }


    //8
    complex c1, c2, c3;
    std::cout << "Question 8:\n ";

    // Set values for the first complex number
    c1.set(3.4, 5.6);
    // Set values for the second complex number
    c2.set(1.2, 3.8);

    // Calculate the sum of the two complex numbers and assign it to the third complex number
    c3 = c1.sum(c2);

    // Display all complex numbers
    std::cout << "Complex number 1: ";
    c1.disp();
    std::cout << "Complex number 2: ";
    c2.disp();
    std::cout << "Sum of complex numbers: ";
    c3.disp();

    //9
    Distance d1, d2, d3;
    std::cout << "Question 9:\n ";


    // Set values for the first distance
    d1.set(5, 9.5);
    // Set values for the second distance
    d2.set(3, 11.25);

    // Calculate the sum of the two distances and assign it to the third distance
    d3 = d1.add(d2);

    // Display all distances
    std::cout << "Distance 1: ";
    d1.disp();
    std::cout << "Distance 2: ";
    d2.disp();
    std::cout << "Sum of distances: ";
    d3.disp();


    //10
    Time t1, t2, t3;
    std::cout << "Question 10:\n ";

    t1.settime(2, 45);
    t2.settime(3, 30);
    t3 = t1.sum(t2);
    std::cout << "Time 1: ";
    t1.showtime();
    std::cout << "Time 2: ";
    t2.showtime();
    std::cout << "Sum of times: ";
    t3.showtime();
    return 0;
}