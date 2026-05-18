//Ryan Ramdihal COP 4020 Spring 2025 with Professor Leinecker
//Javascript 1 Assignment


//Problem 14
let longestCollatzSequence = (limit) => { // upper bound of the starting value

  // Initialize the longest sequence and the starting value of the longest sequence
  let longestSequence = 1; // 1 is the length of the sequence for 1
  let longestValue = 1; // 1 is the starting value for the sequence of 1

  // Loop through all starting values from 2 to the limit
  for(let startValue = 2; startValue < limit; startValue ++){ 
      
      // Initialize the number of terms and the current term
      let numTerms = 1; 
      let currentTerm = startValue; 

      // While we haven't reached 1
      while(currentTerm != 1){ 
          if(currentTerm % 2 === 0){ // If current term is even
              currentTerm = currentTerm / 2; // Divide by 2
          }else{ // If current term is odd
              currentTerm = ((3 * currentTerm) + 1); // Multiply by 3 and add 1
          }
          numTerms++; // Increment the number of terms
      }

      if(numTerms > longestSequence){ // If the number of terms is greater than the longest sequence
          //console.log('Number of terms for ' + startValue + ' is ' + numTerms)
          longestSequence = numTerms; // Update the longest sequence
          longestValue = startValue ;// Update the starting value of the longest sequence
      }

  }
  /* Return the starting value of the longest chain */
  return longestValue;

}
console.log('The solution for problem 14 is ' + longestCollatzSequence(1000000)); // 837799

//Problem 20
function factorial(n) { // 100! = 100 * 99 * 98 * ... * 1
    if (n === 0) { // 0! = 1
      return BigInt(1); // BigInt is used for larger numbers, 21! largest for int
    } else {
      return BigInt(n) * factorial(n - 1); // n! = n * (n - 1)!
    }
  }
  
  function sumDigits(n) {
        const str = n.toString(); // Convert number to a string
        let sum = 0; // Initialize the sum

        for (let i = 0; i < str.length; i++) { // Go through each digit in factorial number
         sum += parseInt(str[i]); // Add the digit to the sum after converting it back to a number from a string 
        }
    return sum; 
  }
  
  const result = sumDigits(factorial(100));//  call function to get the value of the sum of the digits of 100!
  console.log("The solution for problem 20 is " + result); // 648