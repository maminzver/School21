SELECT pz.name AS name, COUNT(*) AS count_of_orders, ROUND(AVG(price), 2) AS average_price, MAX(price) AS max_price, MIN(price) AS min_price
FROM pizzeria AS pz 
	INNER JOIN menu ON menu.pizzeria_id = pz.id
	INNER JOIN person_order AS po ON po.menu_id = menu.id
GROUP BY pz.name
ORDER BY 1