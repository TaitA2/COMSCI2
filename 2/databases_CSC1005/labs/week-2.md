# SQL Query results

## Section 1 - Sakila
1. SELECT * FROM film WHERE title LIKE "%games%";
  * GAMES BOWFINGER
  * HOLIDAY GAMES
  * RAGE GAMES
2. SELECT * FROM film WHERE length > 120; 
  * African egg, agent truman, alamo videotape...
3. select * from actor where last_name like "%queen%";
  * Julia McQueen
  * Cate McQueen

## Section 2 - World
4. select * from city where population > 1000000 order by name;
5. select * from country where name != LocalName;

## Section 3 - Basketball
6. select playerID from awards_players where year = 1989 group by playerID; 
7. SELECT * FROM player_allstar where season_id = 1998 and points > 400 and minutes < 900;
  * NO SEASON 1998 EXISTS
8. select name, homeWon from teams where year = 1994 and name like "%Chicago%" ;
9. select name from teams where year = 1994 and name like "%C%" and homeWon > awayWon ;
  * Boston Celtics, Charlotte Hornets, Chicago Bulls, Cleveland Cavaliers, Dallas Mavericks, Houston Rockets, Indiana Pacers, Los Angeles Clippers, Milwaukee Bucks, New York Knicks, Orlando Magic, Sacramento Kings, Seattle Supersonics
