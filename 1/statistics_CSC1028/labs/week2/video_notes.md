# Exercises in R notes


1. If passwords can consist of six letters, find the probability that a randomly chosen password will not have any repeated letters.
  * 2 things to find:
    * number of passwords that do not have any repeated letters
      * 26P6
    * total number of 6 letter passwords (Sample)
      * 26 * 26 * 26 * 26 * 26 * 26
      * 26 ^ 6
  * P(E) = 26P6 / 26^6
  * R
    * prod(26:21) / (26^6)
    * 0.5366045
    * ~53%

2. A sample of size 10 is chosen at random from a class of 100 consisting of 60 females and 40 males. Find the probability of getting 10 females.
  * 2 things to find
    * number of possible groups of 10 females
      * 60 C 10
    * total number of possible samples of 10 (Sample)
      * 100C10
  * P(E) = 60C10 / 100C10
  * R
    * choose(60,10) / choose(100,10)
    * 0.004355441
    * ~0.43%

3. A box with 15 IC chips contains 5 defective chips. If a sample of three chips is drawn at random without replacement, what is the probability that all three are defective?
  * 2 things to find
    * number of possible samples of 3 defective chips
      * 5P3
    * total number of possible samples of 3 chips (Sample)
      * 15P3
  * 5P3 / 15P3
  * R
    * prod(5:3) / prod(15:13)
    * OR
    * choose(5,3) / choose(15,3)
    * 0.02197802
    * ~2.19%

4. A batch of 50 semiconductors contains 10 that are defective. Two are selected at random without replacement.
* a) What is the probability that the first one selected is defective?
  * 10 / 50
  * 0.2
  * 20%
* b) What is the probability that the second one selected is defective?
  * 2 posssiblities:
    * Good then Bad
      * (40 / 50) * (10 / 49)
    * Bad then Bad
      * (10 / 50) * (9 / 49)
  * (40 / 50) * (10 / 49) + (10 / 50) * (9 / 49)
  * 0.2
  * 20%
* c) What is the probability that both are defective?
  * (10 / 50) * (9 / 49)
  * 0.03673469
  * ~3.67%
* d) How would the probability change in (b) if the chips selected were replaced before the next selection?
  * 2 posssiblities:
    * Good then Bad
      * (40 / 50) * (10 / 50)
    * Bad then Bad
      * (10 / 50) * (10 / 50)
  * ((40 / 50) * (10 / 50)) + ((10 / 50) * (10 / 50))
  * 0.2
  * 20%
  * stays the same

5. In a party of 5 students, find the probability that at least 2 have the same birthday (month/day), assuming a 365 day year.
  * First, find the probability that all birthdays are different
    * 2 things to find
      * number of possible 5 birthdays
        * 365P5 
      * total possible birthdays (Sample)
        * 365 ^ 5
    * 365P5 / (365^5)
    * 0.9728644
    * ~97%
  * Now find inverse
    * 1 - 0.9728644
    * 0.0271356
    * ~2.7%

6. The probability that two students in a class have the same birthday is at least 75%. What is the minimum size of the class?
  * k = class size
  * 1 - (365Pk / (365^k)) = 0.75
  * brute force in R
  * k = 32

7. Use R to simulate that the probability of getting a head is .5 if a fair coin is tossed 1000 times
  * x = sample(c('H','T'),1000,replace=T)
    * creates an array of 1000 elements, each either 'H' or 'T'
  * table(x)/1000
  * H 0.525 
  * T 0.475 

8. Use R to simulate that the probability of getting an even number if a fair die is rolled 600 times
  * sample(c(1,2,3,4,5,6),600, replace=T)
    * 1 0.1633333
    * 2 0.1650000
    * 3 0.1733333
    * 4 0.1566667
    * 5 0.1600000
    * 6 0.1816667
  * store the probabilities
    * ps = table(x) / 600
  * add up probabilities of even numbers
    * ps[2] + ps[4]+ps[6]
    * 0.5

9. Use R to simulate the probability of each outcome if 2 fair coins are tossed 100 times
  * x = sample(c('HH', 'HT', 'TT', 'TH'),100, replace=T)
  * table(x) / 4
    * HH 7.25
    * HT 6.50
    * TH 6.50
    * TT 4.75

10. Amy and Jane are gambling against eachother. A fair coin is tossed repeatedly. Each time a head comes up, Amy wins two euro from Jane, and each time a tails comes up, AMy loses 2 euro to Jane. Use R to simulate this game 100 times.
* a) Estimate the number of times that Amy is ahead in these 100 tosses
* b) Estimate how much Amy won or lost
  * get the sample space
    * 2 possibilites
      * win 2
      * lose 2
    * x = sample(c(2,-2),100,replace=T)
  * start total count at 0
    * total = 0
  * set first value of total to first value of x
    * total[1] = x[1]
  * use a for loop to set each element of total to the new score by adding the ith value of x to the previous value in total
    * for (i in 2:100) total[i] = total[i-1]+x[i]
  * view it as a plot
    * plot(total)
  * view indexes of elements where the score was positive
    * total[total > 0]
  * get the number of times the total was positive
    * length(total[total > 0])
  * get the finishing winnings or losings
    * total[100]
    * OR
    * sum(x)

11. A series of 20 jobs arrive at a computing center with 50 processors. Assume that each of the jobs is equally likely to go through any one of the processors. Find the probability that a processor is used at least twice.
  * 2 solutions
    * Permutations formula
      * start with compliment
      * 2 things to find
        * number of ways 50 processors could be allocated to 20 jobs without repeats
          * 50P20
        * sample space
          * 50^20
      * P(É) = 50P20 / 50^20
        * 0.01202305
      * P(E) = 1 - (50P20 / 50^20)
        * 0.9870769
      * ~98%
    * Simulation
      * num_ps = 0
      * for (i in 1:1000) num_ps[i] = length(unique(sample(1:50,20,replace=T)))
      * P(É) = length(num_ps[num_ps==20])*100
      * P(E) = 1 - length(num_ps[num_ps==20])*100
