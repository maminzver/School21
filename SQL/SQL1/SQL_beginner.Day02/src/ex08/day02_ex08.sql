SELECT person.name
FROM person
	INNER JOIN person_order AS po ON person.id = po.person_id
	INNER JOIN menu ON po.menu_id = menu.id
WHERE gender = 'male' AND address IN ('Moscow', 'Samara') AND pizza_name IN ('pepperoni pizza', 'mushroom pizza')
ORDER BY 1 DESC