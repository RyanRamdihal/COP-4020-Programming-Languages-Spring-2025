// COP 4020, Spring 2025, Ryan Ramdihal
// C# Object Oriented and LINQ Programming Assignment
using System;
using System.Collections.Generic;
using System.Linq;

class Animal
{
    public void move()
    {
        Console.WriteLine("The animal moves.");
    }

    public void sleep()
    {
        Console.WriteLine("The animal sleeps.");
    }

    public void eat()
    {
        Console.WriteLine("The animal eats.");
    }
}

class Dog : Animal
{
    public void sing()
    {
        Console.WriteLine("The dog barks.");
    }

    public void wash()
    {
        Console.WriteLine("The dog is being washed.");
    }

    public void turnAround()
    {
        Console.WriteLine("The dog turns around.");
    }
}

class Cat : Animal
{
    public void sing()
    {
        Console.WriteLine("The cat meows.");
    }

    public void wash()
    {
        Console.WriteLine("The cat is cleans itself.");
    }

    public void turnAround()
    {
        Console.WriteLine("The cat turns around.");
    }
}

class Bird : Animal
{
    public void sing()
    {
        Console.WriteLine("The bird chirps.");
    }

    public void wash()
    {
        Console.WriteLine("The bird is bathing in water.");
    }

    public void turnAround()
    {
        Console.WriteLine("The bird turns around.");
    }
}

interface IUFO
{
    void fly();
    void goToHyperspace();
    void land();
}

class SmallCraft : IUFO
{
    public void fly()
    {
        Console.WriteLine("The small craft is flying.");
    }

    public void goToHyperspace()
    {
        Console.WriteLine("The small craft is entering hyperspace.");
    }

    public void land()
    {
        Console.WriteLine("The small craft is landing.");
    }
}

class LargeCraft : IUFO
{
    public void fly()
    {
        Console.WriteLine("The large craft is flying.");
    }

    public void goToHyperspace()
    {
        Console.WriteLine("The large craft is entering hyperspace.");
    }

    public void land()
    {
        Console.WriteLine("The large craft is landing.");
    }
}

class BossCraft : IUFO
{
    public void fly()
    {
        Console.WriteLine("The boss craft is flying.");
    }

    public void goToHyperspace()
    {
        Console.WriteLine("The boss craft is entering hyperspace.");
    }

    public void land()
    {
        Console.WriteLine("The boss craft is landing.");
    }
}

public class Problem1
{
    public static IEnumerable<int> myFilter(IEnumerable<int> input)
    {
        //Remove all multiples of 5 greater than 50
        var filtered = input.Where(x => !(x > 50 && x % 5 == 0));

        //Cube each number
        var cubed = filtered.Select(x => x * x * x);

        //Remove any resulting integer that is even
        var result = cubed.Where(x => x % 2 != 0);

        return result;
    }
}

public class Problem2
{
    public static IEnumerable<int> myFilter(IEnumerable<int> input)
    {
        //Remove all multiples of 6 less than 42
        var filtered = input.Where(x => !(x < 42 && x % 6 == 0));

        //Square each number
        var squared = filtered.Select(x => x * x);

        //Remove any resulting integer that is odd
        var result = squared.Where(x => x % 2 == 0);

        return result;
    }
}

public class TestProblem2
{
    public static IEnumerable<int> merge(IEnumerable<int> input1, IEnumerable<int> input2, IEnumerable<int> input3, IEnumerable<int> input4)
    {
        // Find the intersection of all four lists
        var intersection = input1.Intersect(input2).Intersect(input3).Intersect(input4);

        // Filter the intersection to include only multiples of 10
        var result = intersection.Where(x => x % 10 == 0);

        return result;
    }
}

class Program
{
    static void Main(string[] args)
    {
        Dog dog = new Dog();
        Cat cat = new Cat();
        Bird bird = new Bird();

        // Call methods for Dog
        Console.WriteLine("Dog:");
        dog.move();
        dog.sleep();
        dog.eat();
        dog.sing();
        dog.wash();
        dog.turnAround();

        // Call methods for Cat
        Console.WriteLine("\nCat:");
        cat.move();
        cat.sleep();
        cat.eat();
        cat.sing();
        cat.wash();
        cat.turnAround();

        // Call methods for Bird
        Console.WriteLine("\nBird:");
        bird.move();
        bird.sleep();
        bird.eat();
        bird.sing();
        bird.wash();
        bird.turnAround();

        SmallCraft smallCraft = new SmallCraft();
        LargeCraft largeCraft = new LargeCraft();
        BossCraft bossCraft = new BossCraft();

        // Call methods for SmallCraft
        Console.WriteLine("\nSmallCraft:");
        smallCraft.fly();
        smallCraft.goToHyperspace();
        smallCraft.land();

        // Call methods for LargeCraft
        Console.WriteLine("\nLargeCraft:");
        largeCraft.fly();
        largeCraft.goToHyperspace();
        largeCraft.land();

        // Call methods for BossCraft
        Console.WriteLine("\nBossCraft:");
        bossCraft.fly();
        bossCraft.goToHyperspace();
        bossCraft.land();

        Random rnd = new Random(5); // Random number generator
        var listForProblem = Enumerable.Range(1, 100).Select(i => rnd.Next() % 101);
        var answer = Problem1.myFilter(listForProblem);

        foreach (int i in answer)
        {
            Console.WriteLine(i);
        }

        Console.WriteLine("\nProblem2:");
        Random rnd2 = new Random(); // Random number generator
        var listForProblem2 = Enumerable.Range(1, 100).Select(i => rnd2.Next() % 101);
        var answer2 = Problem2.myFilter(listForProblem2);

        foreach (int i in answer2)
        {
            Console.WriteLine(i);
        }




        // Generate the four lists
       // Sequence from 1 to 15
        var list1 = Enumerable.Range(1, 15);

        // Even numbers from 2 to 42
        var list2 = Enumerable.Range(1, 21).Select(x => x * 2);

        // Odd numbers from 3 to 21
        var list3 = Enumerable.Range(0, 10).Select(x => 3 + x * 2);

        // Multiples of 5 from 5 to 105
        var list4 = Enumerable.Range(1, 21).Select(x => x * 5);

        // Call the merge function
        var mergedAnswer = TestProblem2.merge(list1, list2, list3, list4);

        // Print the result
        Console.WriteLine("\nMerged List:");
        foreach (int i in mergedAnswer)
        {
            Console.WriteLine(i);
        }
    }
}