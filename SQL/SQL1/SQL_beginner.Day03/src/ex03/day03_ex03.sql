(SELECT pz.name AS pizzeria_name
FROM person 
	INNER JOIN person_visits AS pv ON person.id = pv.person_id
	INNER JOIN pizzeria AS pz ON pz.id = pv.pizzeria_id
WHERE person.gender = 'female'
EXCEPT ALL
SELECT pz.name
FROM person 
	INNER JOIN person_visits AS pv ON person.id = pv.person_id
	INNER JOIN pizzeria AS pz ON pz.id = pv.pizzeria_id
WHERE person.gender = 'male')
UNION
(SELECT pz.name
FROM person 
	INNER JOIN person_visits AS pv ON person.id = pv.person_id
	INNER JOIN pizzeria AS pz ON pz.id = pv.pizzeria_id
WHERE person.gender = 'male'
EXCEPT ALL
SELECT pz.name
FROM person 
	INNER JOIN person_visits AS pv ON person.id = pv.person_id
	INNER JOIN pizzeria AS pz ON pz.id = pv.pizzeria_id
WHERE person.gender = 'female')
ORDER BY 1