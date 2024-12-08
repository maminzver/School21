SELECT visits.name AS name, COALESCE(visits.cnt, 0) + COALESCE(orders.cnt, 0) AS total_count
FROM
(SELECT pz.name AS name, COUNT(*) AS cnt
FROM person_visits AS pv
	INNER JOIN pizzeria AS pz ON pz.id = pv.pizzeria_id
GROUP BY pz.name) AS visits
FULL JOIN 
(SELECT pz.name AS name, COUNT(*) AS cnt
FROM person_order AS po
	INNER JOIN menu ON menu.id = po.menu_id
	INNER JOIN pizzeria AS pz ON pz.id = menu.pizzeria_id
GROUP BY pz.name) AS orders ON visits.name = orders.name
ORDER BY 2 DESC, 1