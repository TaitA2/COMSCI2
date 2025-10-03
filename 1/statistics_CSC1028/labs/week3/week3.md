1. 5 character passwords. first character is letter, others are letters or integer.

* a) total possible passwords
  * 26 * 36 * 36 * 36 * 36  = 43670016

* b) proportion of passwords that begin with a consonant
  * 21 * 36 * 36 * 36 * 36  = 35271936
  * 35271936 / 43670016 = 0.8076923076923077

* c) proportion of passwords that end with an even number
  * 26 * 36 * 36 * 36 * 5  = 
  * 6065280 / 43670016 = 0.1388888888888889

* d) proportion of passwords that start with a consonant and or end with an even number
  * P(A U B) = P(A) + P(B) - P(A n B)
    * P(A n B) = (21 * 36 * 36 * 36 * 5) / 43670016 = 4898880/43670016 = 0.112179
  * P(A U B) = 0.8 + 0.138 - 0.112179 = 0.8525821
  * 85%

* e) if a password is selected at random, what is the probability it would be a palindrome?
  * total possible 3 digit passwords == total possible palindromes
  * 26 * 36 * 36 = 33696
  * 33696 / 43670016  = 0.0007716049382716049
  * ~0.077%

* f) simulate e) in R
  * results = logical(100000)
  * alnum = c(letters,0:9)
  * for (i in 1:100000){
    * start = sample(letters,1,replace=T)
    * end = sample(alnum,4,replace=T)
    * password = c(start,end)
    * results[i] = identical(password, rev(password))}
  * sprintf("%.20f\n", length(results[results==TRUE])/100000)
  * 0.00075
  * ~0.075%
