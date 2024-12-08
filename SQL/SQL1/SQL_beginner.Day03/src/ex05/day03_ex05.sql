SELECT pz.name
FROM person_visits AS pv
	INNER JOIN person ON person.id = pV.person_id
	INNER JOIN pizzeria AS pz ON pz.id = pv.pizzeria_id
WHERE person.name = 'Andrey'
EXCEPT
SELECT pz.name
FROM person_order AS pv
	INNER JOIN person ON person.id = pv.person_id
	INNER JOIN pizzeria AS pz ON pz.id = pv.person_id
WHERE person.name = 'Andrey'
ORDER BY 1
