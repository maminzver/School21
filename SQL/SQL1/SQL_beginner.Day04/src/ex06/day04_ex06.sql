CREATE MATERIALIZED VIEW mv_dmitriy_visits_and_eats AS 
SELECT pz.name
FROM pizzeria AS pz
	INNER JOIN menu ON menu.pizzeria_id = pz.id
	INNER JOIN person_visits AS pv ON pv.pizzeria_id = pz.id
	INNER JOIN person ON pv.person_id = person.id
WHERE menu.price < 800 AND pv.visit_date = '2022-01-08' AND person.name = 'Dmitriy'