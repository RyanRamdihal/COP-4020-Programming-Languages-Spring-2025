// C# Intro, Ryan Ramdihal, Spring 2025

class USFStudent
{
    public void SayIt()
    {
        Console.WriteLine("Go Bulls");
    }
    public void Intro()
    {
        Console.WriteLine("I am a student at the University of South Florida.");
    }
}

class UCFStudent
{
    public void SayIt()
    {
        Console.WriteLine("Go Knights");
    }
    public void Intro()
    {
        Console.WriteLine("I am a student at the University of Central Florida.");
    }
}

class UFStudent
{
    public void SayIt()
    {
        Console.WriteLine("Go Gators");
    }
    public void Intro()
    {
        Console.WriteLine("I am a student at the University of Florida.");
    }
}

class Program
{
    static void Main(string[] args)
    {
        // Create an instance of type of student
        USFStudent usfStudent = new USFStudent();
        UCFStudent ucfStudent = new UCFStudent();
        UFStudent ufStudent = new UFStudent();

        // USF student info
        Console.WriteLine("USF Student:");
        usfStudent.SayIt(); 
        usfStudent.Intro(); 

        //  UCF student info
        Console.WriteLine("\nUCF Student:");
        ucfStudent.SayIt(); 
        ucfStudent.Intro(); 

        // UF student info
        Console.WriteLine("\nUF Student:");
        ufStudent.SayIt(); 
        ufStudent.Intro(); 
    }
}