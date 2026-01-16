# SQL Query results
## Q1
* SELECT * FROM sakila.actor where first_name = "michael";
  * ID    f-name    l-name  last_update
  * 74 	  MICHAEL 	BENING 	2006-02-15 04:34:33
  *	185 	MICHAEL 	BOLGER 	2006-02-15 04:34:33
## Q2
* SELECT * FROM City where ID = 15;
  * ID  Name      Code  District    Population
  * 15 	Enschede 	NLD 	Overijssel 	149544
 
## Q3
* SELECT Name, ID FROM City where ID = 15;
  * Name     ID
  * Enschede 15
