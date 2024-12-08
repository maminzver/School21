SELECT address, pz.name AS name, COUNT(*) AS count_of_orders
FROM person_order AS po
	INNER JOIN person ON po.person_id = person.id
	INNER JOIN menu ON menu.id = po.menu_id
	INNER JOIN pizzeria AS pz ON pz.id = menu.pizzeria_id
GROUP BY address, pz.name
ORDER BY 1, 2