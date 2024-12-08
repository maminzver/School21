SELECT pizza_name, pz.name AS pizzeria_name
FROM person_order AS po
	INNER JOIN person ON person.id = po.person_id
	INNER JOIN menu ON menu.id = po.menu_id
	INNER JOIN pizzeria AS pz ON menu.pizzeria_id = pz.id
WHERE person.name IN ('Denis', 'Anna')
ORDER BY 1, 2