--Ryan Ramdihal COP 4020 Spring 2025 with Professor Leinecker
--Higher Order Functions Assignment

--1. Using map, double the numbers in this list: [1,5,-18,99]
doubleList xs = map (*2) xs
-- xs is a list of elements
-- map takes two arguments: a function and a list
-- The function here is '(*2)', which doubles its input
-- 'map (*2) xs' applies the function to each element of the list 'xs'

--2. Using filter extract all the even numbers in this list: [1..100]
evenList xs = filter even xs
-- 'filter' takes two arguments: a predicate/boolean function and a list
-- The function here is 'even', which checks if a number is even
-- 'filter even xs' applies the predicate to each element of the list 'xs'
-- and returns a new list containing only the elements that satisfy the predicate: true

--3. Using map multiply all numbers in this list: [1,3..77] by 3.
multiplyBy3List xs = map (*3) xs
-- 'map' takes two arguments: a function and a list
-- The function here is '(*3)', which multiplies its input by 3
-- 'map (*3) xs' applies the function to each element of the list 'xs'

--4. Using any functions you choose 
--(but map and filter might be good choices) 
--calculate the sum of the squares of all odd numbers in this list: [1,2,3,4,5,7,8,1,43,25,65,22]
sumSquaresOfOdd xs = sum squaredOddNumbers
  where
    oddNumbers = filter odd xs
    -- 'filter' takes two arguments: a predicate function and a list
    -- The predicate function here is 'odd', which checks if a number is odd
    -- 'filter odd xs' returns a new list containing only the odd elements of 'xs'
    squaredOddNumbers = map (^2) oddNumbers
    -- apply the 'map' function to the list of odd numbers, 'map' takes two arguments: a function and a list
    -- The function here is '(^2)', which squares its input
    -- 'map (^2) oddNumbers' applies the squaring function to each element of the oddNumbers list

-- apply the 'sum' function to the list of squared odd numbers
-- 'sum' takes a list of numbers and returns their sum
-- 'sum squaredOddNumbers' returns the sum of the squared odd numbers