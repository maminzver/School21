(SELECT pz.name, COUNT(*), 'visit' AS action_type
FROM person_visits AS pv
	INNER JOIN pizzeria AS pz ON pz.id = pv.pizzeria_id
GROUP BY pz.name
ORDER BY 2 DESC
LIMIT 3)
UNION 
(SELECT pz.name, COUNT(*), 'order' AS action_type
FROM person_order AS po
	INNER JOIN menu ON menu.id = po.menu_id
	INNER JOIN pizzeria AS pz ON pz.id = menu.pizzeria_id
GROUP BY pz.name
ORDER BY 2 DESC
LIMIT 3)
ORDER BY 3, 2 DESC