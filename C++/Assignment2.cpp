//C++ Assignment 2, Ryan Ramdihal, COP 4020 with Professor Leinecker

//Note: Question 9 overwrites question 8, so the output of question 8 is not displayed in file SECOND.TXT
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <iomanip>

using namespace std; //removes std from cout, cin, and endl

// 10. Write the objects of EMPLOYEE to a binary file and read the objects of EMPLOYEE from binary file and display them on screen.
class EMPLOYEE {
    int ENO;
    char ENAME[10];

public:
    void GETIT() {
        cout << "Enter Employee Number: ";
        cin >> ENO;
        cin.ignore(); // To ignore the newline character left in the buffer
        cout << "Enter Employee Name: ";
        cin.getline(ENAME, sizeof(ENAME));
    }

    void SHOWIT() const {
        cout << "Employee Number: " << ENO << ", Employee Name: " << ENAME << endl;
    }
};

void writeEmployeesToFile(const string& filename, EMPLOYEE employees[], int size) {
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "File could not be opened." << endl;
        return;
    }

    for (int i = 0; i < size; ++i) {
        outFile.write(reinterpret_cast<char*>(&employees[i]), sizeof(EMPLOYEE));
    }

    outFile.close();
    cout << "Employees have been written to " << filename << endl;
}

void readEmployeesFromFile(const string& filename) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "File could not be opened." << endl;
        return;
    }

    EMPLOYEE emp;
    while (inFile.read(reinterpret_cast<char*>(&emp), sizeof(EMPLOYEE))) {
        emp.SHOWIT();
    }

    inFile.close();
}

//12. Write a function readfile() to read all the records present in an already existing binary file SHIP.DAT and display them on the screen, also count the number of records present in the file.
class Computer {
    char chiptype[10];
    int speed;

public:
    void getdetails() {
        cout << "Enter Chip Type: ";
        cin.ignore(); // To ignore the newline character left in the buffer
        cin.getline(chiptype, sizeof(chiptype));
        cout << "Enter Speed: ";
        cin >> speed;
    }

    void showdetails() const {
        cout << "Chip: " << chiptype << ", Speed = " << speed << endl;
    }
};

void readfile(const string& filename) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "File could not be opened." << endl;
        return;
    }

    Computer comp;
    int count = 0;
    while (inFile.read(reinterpret_cast<char*>(&comp), sizeof(Computer))) {
        comp.showdetails();
        count++;
    }

    inFile.close();
    cout << "Total number of records: " << count << endl;
}

//13. Write a function to read contents of file STUDENT.DAT and display the details of those Students whose Percentage is above 75.
class Student {
    char S_Admno[10];    // Admission number of student
    char S_Name[30];     // Name of student
    int Percentage;      // Marks Percentage of student

public:
    void EnterData() {
        cin.ignore(); // To ignore the newline character left in the buffer
        cout << "Enter Admission Number: ";
        cin.getline(S_Admno, sizeof(S_Admno));
        cout << "Enter Name: ";
        cin.getline(S_Name, sizeof(S_Name));
        cout << "Enter Percentage: ";
        cin >> Percentage;
    }

    void DisplayData() const {
        cout << setw(12) << S_Admno;
        cout << setw(32) << S_Name;
        cout << setw(3) << Percentage << endl;
    }

    int ReturnPercentage() const {
        return Percentage;
    }
};

void displayHighPercentageStudents(const string& filename) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "File could not be opened." << endl;
        return;
    }

    Student student;
    while (inFile.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        if (student.ReturnPercentage() > 75) {
            student.DisplayData();
        }
    }

    inFile.close();
}
// 14. fill in the blank statements
class Employee
{
            int Eno;
            char Ename[20];
            public:
            //Function to count the total number of records
            int Countrec();
};

int Employee::Countrec()
{
            fstream File;
            File.open("EMP.DAT", ios::binary | ios::in);
            File.seekg(0, ios::end); //Statement 1
            int Bytes = File.tellg(); //Statement 2
            int Count = Bytes / sizeof(Employee);
            File.close();
            return Count;
}

//15 Add new students to the file STUDENT.DAT
class STUD {
    int Rno;
    char Name[20];

public:
    void Enter() {
        //cout << "Enter Roll Number: ";
        cin >> Rno;
       // cin.ignore(); // To ignore the newline character left in the buffer
       // cout << "Enter Name: ";
        cin.getline(Name, sizeof(Name));
    }

    void Display() const {
        cout << "Roll Number: " << Rno << ", Name: " << Name << endl;
    }
};

void addNewStudentsToFile(const string& filename, STUD students[], int size) {
    ofstream outFile(filename, ios::binary | ios::app);
    if (!outFile) {
        cerr << "File could not be opened." << endl;
        return;
    }

    for (int i = 0; i < size; ++i) {
        outFile.write(reinterpret_cast<char*>(&students[i]), sizeof(STUD));
    }

    outFile.close();
    cout << "New students have been added to " << filename << endl;
}
//16. fill in the blank statements
class Item {
    int Ino;
    char ItemName[20];

public:
    // Function to search and display the content from a particular record number
    void Search(int);
    // Function to modify the content of a particular record number
    void Modify(int);
};

void Item::Search(int RecNo) {
    fstream File;
    File.open("STOCK.DAT", ios::binary | ios::in);
    File.seekg((RecNo - 1) * sizeof(Item), ios::beg); // Statement 1, to search and display the content from a particular record number
    File.read((char*)this, sizeof(Item));
    cout << Ino << " ==> " << ItemName << endl;
    File.close();
}

void Item::Modify(int RecNo) {
    fstream File;
    File.open("STOCK.DAT", ios::binary | ios::in | ios::out);
    cin >> Ino;
    cin.getline(ItemName, 20);
    File.seekp((RecNo - 1) * sizeof(Item), ios::beg); // Statement 2, to modify the content of a particular record number
    File.write((char*)this, sizeof(Item));
    File.close();
}
//3. Write a user-defined function in C++ to read the content from a text file OUT.TXT, count and display the number of alphabets present in it.
void countAlphabets(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "File could not be opened." << endl;
        return;
    }
    char ch;
    int count = 0;
    while (inFile.get(ch)) {
        if (isalpha(ch)) {
            count++;
        }
    }

    inFile.close();
    cout << "Question 3: The number of alphabets in " << filename << " is: " << count << endl;
}

//4. Write a function to count the number of blank present in a text file named "OUT.TXT".
void countBlanks(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "File could not be opened." << endl;
        return;
    }
    char ch;
    int count = 0;
    while (inFile.get(ch)) {
        if (isspace(ch) && ch == ' ') {
            count++;
        }
    }

    inFile.close();
    cout << "Question 4: The number of blank spaces in " << filename << " is: " << count << endl;
}

//5. Write a function to count the number of words in a text file named "OUT.TXT".
void countWords(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "File could not be opened." << endl;
        return;
    }
    string word;
    int count = 0;
    while (inFile >> word) {
        count++;
    }

    inFile.close();
    cout << "Question 5: The number of words in " << filename << " is: " << count << endl;
}

//6. Write a function in C++ to print the count of word "the" as an independent word in a text file named "STORY.TXT".
void countTheWord(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "File could not be opened." << endl;
        return;
    }
    string word;
    int count = 0;
    while (inFile >> word) {
        // Convert word to lowercase for case-insensitive comparison
        for (char& c : word) {
            c = tolower(c);
        }
        if (word == "the") {
            count++;
        }
    }

    inFile.close();
    cout << "Question 6: The number of occurrences of the word 'the' in " << filename << " is: " << count << endl;
}

//7. Write a function in C++ to count and display the number of lines not starting with alphabet 'A' present in a text file "STORY.TXT".
void countLinesNotStartingWithA(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "File could not be opened." << endl;
        return;
    }
    string line;
    int count = 0;
    while (getline(inFile, line)) {
        if (!line.empty() && tolower(line[0]) != 'a') {
            count++;
        }
    }

    inFile.close();
    cout << "Question 7: The number of lines not starting with 'A' in " << filename << " is: " << count << endl;
}

//8. Write a function named copyupper() to read the file FIRST.TXT and create a new file named SECOND.TXT containing all words from FIRST.TXT in uppercase.
void copyupper(const string& sourceFile, const string& destFile) {
    ifstream inFile(sourceFile);
    if (!inFile) {
        cerr << "Source file could not be opened." << endl;
        return;
    }

    ofstream outFile(destFile);
    if (!outFile) {
        cerr << "Destination file could not be opened." << endl;
        return;
    }

    string word;
    while (inFile >> word) {
        for (char& c : word) {
            c = toupper(c);
        }
        outFile << word << " ";
    }

    inFile.close();
    outFile.close();
    cout << "Question 8: Content has been copied to " << destFile << " in uppercase." << endl;
}

//9. Write a function named vowelwords() to read the file FIRST.TXT and create a new file named SECOND.TXT containing only those words from FIRST.TXT which start with a lowercase vowel.
void vowelwords(const string& sourceFile, const string& destFile) {
    ifstream inFile(sourceFile);
    if (!inFile) {
        cerr << "Source file could not be opened." << endl;
        return;
    }

    ofstream outFile(destFile);
    if (!outFile) {
        cerr << "Destination file could not be opened." << endl;
        return;
    }

    string word;
    while (inFile >> word) {
        if (word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u') {
            outFile << word << " ";
        }
    }

    inFile.close();
    outFile.close();
    cout << "Question 9: Words starting with a lowercase vowel have been copied to " << destFile << "." << endl;
}

int main() {
    //1. Write a C++ program to write numbers from 1 to 100 to a text file NOTES.TXT.
    ofstream outFile("NOTES.TXT");

    if (!outFile) {
        cerr << "File could not be opened." << endl;
        return 1;
    }

    for (int i = 1; i <= 100; ++i) {
        outFile << i << endl;
    }

    outFile.close();
    cout << "Question 1: Numbers 1 to 100 have been written to NOTES.TXT" << endl;

    //2. Write a C++ program, which initializes a string variable to the content "Time is a great teacher but unfortunately it kills all its pupils. Berlioz" and outputs the string to the disk file OUT.TXT. you have to include all the header files if required.
    string content = "Time is a great teacher but unfortunately it kills all its pupils. Berlioz";
    ofstream outFile2("OUT.TXT");

    if (!outFile2) {
        cerr << "File could not be opened." << endl;
        return 1;
    }

    outFile2 << content << endl;

    outFile2.close();
    cout << "Question 2: The string has been written to OUT.TXT" << endl;

   //3. Write a user-defined function in C++ to read the content from a text file OUT.TXT, count and display the number of alphabets present in it. 
   countAlphabets("OUT.TXT");

   //4. Write a function to count the number of blank present in a text file named "OUT.TXT".
   countBlanks("OUT.TXT");

    //5. Write a function to count the number of words in a text file named "OUT.TXT".
    countWords("OUT.TXT");

    //6. Write a function in C++ to print the count of word "the" as an independent word in a text file named "STORY.TXT".
    countTheWord("STORY.TXT");

    //7. Write a function in C++ to count and display the number of lines not starting with alphabet 'A' present in a text file "STORY.TXT".
    countLinesNotStartingWithA("STORY.TXT");

    //8. Write a function named copyupper() to read the file FIRST.TXT and create a new file named SECOND.TXT containing all words from FIRST.TXT in uppercase.
    copyupper("FIRST.TXT", "SECOND.TXT");

    //9. Write a function named vowelwords() to read the file FIRST.TXT and create a new file named SECOND.TXT containing only those words from FIRST.TXT which start with a lowercase vowel.
    vowelwords("FIRST.TXT", "SECOND.TXT");

    //10. Write the objects of EMPLOYEE to a binary file and read the objects of EMPLOYEE from binary file and display them on screen.
    //Set to 1 employee for testing

    /*EMPLOYEE employees[1];
    for (int i = 0; i < 1; ++i) {
        employees[i].GETIT();
    }

    writeEmployeesToFile("EMPLOYEE.DAT", employees, 1); 
    readEmployeesFromFile("EMPLOYEE.DAT");*/

    //12. Write a function readfile() to read all the records present in an already existing binary file SHIP.DAT and display them on the screen, also count the number of records present in the file.
   // readfile("SHIP.DAT");

    //13. Write a function to read contents of file STUDENT.DAT and display the details of those Students whose Percentage is above 75.
   // displayHighPercentageStudents("STUDENT.DAT");

    //15. Add new students to the file STUDENT.DAT
    //set to 1 student for testing

    /*STUD newStudents[1];
    for (int i = 0; i < 1; ++i) {
        newStudents[i].Enter();
    }
    addNewStudentsToFile("STUDENT.DAT", newStudents, 1);*/

    return 0;
}