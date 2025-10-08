1. Acomputer system uses 5 character passwords. Each is a letter or integer. First character is a letter.
* a) total number of passwords:
  * 26 * 36 * 36 * 36 * 36 
  * 43670016 total passwords
* b) proportion of passwords beginning with a consonant
  * total starting with consonant / total
  * 21 * 36 * 36 * 36 * 36 = 35271936
  * 35271936 / 43670016 
  * 0.8 
* c) proportion of passwords ending with even number
  * total ending in even / total
  * even endings = 26 * 36 * 36 * 36 * 5 = 6065280
  * 6065280 / 43670016 
  * 0.138
* d) proportion of possible passwords beginning with a consonant OR end with an even.
  * addition law of probability:
    * P(A U B) = P(A) + P(B) - P(A n B)
    * P(A) = 0.8
    * P(B) = 0.138
    * P(A n B) = P(A) * P(B)
      * P(A n B) = 21 * 36  * 36  * 36  * 36  * 5 
      * P(A n B) = 4898880 / 43670016 
    * P(A n B) = 0.112
    * P(A U B) = 0.8 + 0.138 - 0.112
    * P(A U B) = 0.8344017
* e) probability a random password would be a palindrome
  * total palindromes / total passwords
  * total palindromes = 26 * 36 * 36
  * total palindromes = 33696
  * palindromes / total = 33696 / 43670016
  * 0.0007716049
* f) solve e using a simulation in R
  * count = 0
  * iterations = 100000
  * letters_and_numbers = c(letters, 0:9)
  * for (i in 1:iterations) {
    * part1 = sample(c(letters), 1, replace=T)
    * part2 = sample(c(letters_and_numbers), 4, replace=T)
    * password = c(part1, part2)
    * if(identical(password, rev(password))){
      * count = count + 1 
    * }
  * }
  * sprintf("%.20f", count / iterations)
  * 0.00075
