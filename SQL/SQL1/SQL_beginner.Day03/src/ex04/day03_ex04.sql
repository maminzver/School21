(SELECT pz.name AS pizzeria_name
FROM person 
	INNER JOIN person_order AS po ON person.id = po.person_id
	INNER JOIN menu ON menu.id = po.menu_id
	INNER JOIN pizzeria AS pz ON pz.id = menu.pizzeria_id
WHERE person.gender = 'female'
EXCEPT
SELECT pz.name
FROM person 
	INNER JOIN person_order AS po ON person.id = po.person_id
	INNER JOIN menu ON menu.id = po.menu_id
	INNER JOIN pizzeria AS pz ON pz.id = menu.pizzeria_id
WHERE person.gender = 'male')
UNION
(SELECT pz.name
FROM person 
	INNER JOIN person_order AS po ON person.id = po.person_id
	INNER JOIN menu ON menu.id = po.menu_id
	INNER JOIN pizzeria AS pz ON pz.id = menu.pizzeria_id
WHERE person.gender = 'male'
EXCEPT ALL
SELECT pz.name
FROM person 
	INNER JOIN person_order AS po ON person.id = po.person_id
	INNER JOIN menu ON menu.id = po.menu_id
	INNER JOIN pizzeria AS pz ON pz.id = menu.pizzeria_id
WHERE person.gender = 'female')
ORDER BY 1