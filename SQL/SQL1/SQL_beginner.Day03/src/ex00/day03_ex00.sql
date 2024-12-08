SELECT pizza_name, price, pz.name, pv.visit_date
FROM menu 
	INNER JOIN pizzeria AS pz ON pz.id = menu.pizzeria_id
	INNER JOIN person_visits AS pv ON pz.id = pv.pizzeria_id
	INNER JOIN person ON person.id = pv.person_id
WHERE price BETWEEN 800 AND 1000 AND person.name = 'Kate'
ORDER BY 1,2, 3