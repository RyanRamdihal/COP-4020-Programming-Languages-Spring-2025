--Ryan Ramdihal COP 4020 Spring 2025 with Professor Leinecker

-- 1. Create a function named problem1. Use a list comprehension for the main function. 
-- This function will take a single integer parameter. 
-- It indicates the number of primes that will be the final list. 
-- The final solution will output a list of every other prime.
isPrime n = ip n [2..(isqrt (n))]  
-- 'ip' is a helper function that checks divisibility of 'n' with the numbers in the list [2..(isqrt n)].
-- The list '[2..(isqrt n)]' includes all potential divisors from 2 to the integer square root of 'n'.

 where
 ip _ [] = True
 ip n (x:xs)
 -- Define the 'ip' function with two parameters: 'n' (the number to check) and the list of divisors (x:xs).
 -- The function will recursively check if 'n' is divisible by any element in the list (x).

  | n `mod` x == 0 = False
-- If 'n' is divisible by 'x', return False because 'n' is not prime.

  | otherwise = ip n xs
-- If 'n' is not divisible by 'x', recursively call 'ip' with the remaining list of divisors (xs).

-- calculates the integer square root of a number 'i'.
isqrt = floor . sqrt . fromIntegral
-- 'fromIntegral' converts the input 'i' to a floating-point number (for sqrt).
-- 'sqrt' computes the square root of the number.
-- 'floor' rounds the result down to the nearest integer, producing the integer square root of 'i'.

-- Helper function to list every prime number
primeList n = take (2*n) [x | x <- [1..], isPrime x]
-- `primeList` generates a list of the first `2 * n` prime numbers.
-- It does this by taking the first `2 * n` elements from an infinite list of numbers `[1..]`, 
-- filtering those that are prime using the `isPrime` function, and returning the resulting list.

problem1 n = skipEvenPrimes (primeList n)
 where 
 skipEvenPrimes xs = [y | (i, y) <- zip [2..] xs, odd i] 
 -- zip [1..] xs: creates a list of pairs where each element of `xs` is paired with an array index.
 -- Filter with odd i: Includes only the elements where the index i is odd.

-- 2. Create a function named problem2. Use recursion to solve this problem. 
--This function will take a single integer parameter.
--It indicates the maximum value of Fibonacci numbers that will be in the list.
--The final solution will be a list of Fibonacci numbers that have a three as their right-most digit and are less than or equal to n.
-- (For this problem, Fibonacci starts 1,1,2,…)
problem2 n = go n 1 1 
-- n is max value, 1 is first number in sequence (f), 1 is second number in sequence (s)
    where 
    go n f s 
    -- n is max value, f is first number in sequence, s is second number in sequence
        | (f+s) > n = [] 
        --if the sum of the two numbers is greater than n, return an empty list
        | (f+s) `mod` 10 == 3 = (f+s) : go n s (f+s)
        -- If the next Fibonacci number (f + s) has a rightmost digit of 3 (checked using (f + s) mod 10 == 3), include it in the resulting list.
        | otherwise = go n s (f+s) 
        --If the next Fibonacci number does not have a rightmost digit of 3, skip it.


--3. Create a function named problem3. For this problem, you can solve it any way you’d like. 
--You may (and should) use helper functions. Create a list from numbers from 1 to n. 
--The numbers must be either a multiple of five or have exactly three factors.

-- Calculates the number of divisors of a number `n`
threeFactors n = 
  -- Create a list of 1s for every `x` in the range [1..n]
  -- where `x` is a divisor of `n` (`n mod x == 0`) add 1 to every factor of `n`
  sum([ 1 | x <- [1..n], n `mod` x == 0]) 

-- Generates a list of numbers from 1 to `n` that satisfy the following conditions:
--   - The number is divisible by 5 (`x mod 5 == 0`), OR
--   - The number has exactly 3 factors (as determined by `factorsP x`)
problem3 n = 
  [x | x <- [1..n],  
    -- Create a list of all `x` in the range [1..n]
    (x `mod` 5 == 0 || threeFactors x == 3)]
    -- Include `x` if it satisfies either of the conditions

