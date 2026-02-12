# SQL Query Results

## Section 1
1. select distinct playerID from awards_players where year = 1989;
2. select playerID from players_teams where year = 1998 and points > 400 and minutes < 900;
  * curryde01
  * wallajo01
3. select name, homeWon from teams where year = 1994 and name like "%Chicago%";
  * Chicago Bulls
33. select name from teams where year = 1994 and name like "%C%" and homeWon > awayWon;

## Section 2
4. select title from film where rating = "PG" or rating = "PG-13" order by length, title;
5. select distinct rating from film order by rating;
  * G
  * PG
  * PG-13
  * R
  * NC-17
6. select title from film where title like "THE%" order by title;
  * THEORY MERMAID

## Section 3
7. select name, CountryCode from city where CountryCode = "USA" and name like "%New%" order by name;
  * New Bedford
  * New Haven
  * New Orleans
  * New York
  * Newark
  * Newport News
8. select name, population from city where name like "%burg" order by population desc;
9. select distinct language, Percentage from countrylanguage where Percentage >= 50 order by Percentage desc;
