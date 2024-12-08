SELECT person.name AS name, menu.pizza_name AS pizza_name, price, (price - (price / 100 * discount)) AS discount_price, pz.name AS pizzeria_name
FROM person
	INNER JOIN person_order AS po ON person.id = po.person_id
	INNER JOIN menu ON po.menu_id = menu.id
	INNER JOIN pizzeria AS pz ON pz.id = menu.pizzeria_id
	INNER JOIN person_discounts AS pd ON pd.person_id = person.id AND pd.pizzeria_id = pz.id
ORDER BY 1, 2