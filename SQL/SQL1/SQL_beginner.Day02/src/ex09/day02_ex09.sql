SELECT person.name 
FROM person 
	INNER JOIN person_order AS po ON po.person_id = person.id
	INNER JOIN menu ON menu.id = po.menu_id
WHERE gender = 'female' AND pizza_name = 'pepperoni pizza'
INTERSECT 
SELECT person.name 
FROM person 
	INNER JOIN person_order AS po ON po.person_id = person.id
	INNER JOIN menu ON menu.id = po.menu_id
WHERE gender = 'female' AND pizza_name = 'cheese pizza'
ORDER BY 1