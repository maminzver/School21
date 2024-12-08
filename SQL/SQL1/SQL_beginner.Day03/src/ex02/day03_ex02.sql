SELECT pizza_name, price, pz.name
FROM (
SELECT menu.id AS menu_id
FROM menu 
	EXCEPT
SELECT menu_id
FROM person_order
ORDER BY 1) AS fm
	INNER JOIN menu ON fm.menu_id = menu.id
	INNER JOIN pizzeria AS pz ON menu.pizzeria_id = pz.id
ORDER BY 1, 2