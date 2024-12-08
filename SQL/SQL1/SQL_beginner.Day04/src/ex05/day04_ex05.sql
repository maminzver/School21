CREATE VIEW v_price_with_discount AS 
SELECT person.name AS name, menu.pizza_name AS pizza_name, menu.price AS price,
	ROUND(menu.price - menu.price * 0.1) AS discount_price
FROM person
	INNER JOIN person_order AS po ON person.id = po.person_id
	INNER JOIN menu ON menu.id = po.menu_id
ORDER BY person.name, menu.pizza_name