SELECT pz.name
FROM person
	INNER JOIN person_visits AS pv ON person.id = pv.person_id
	INNER JOIN pizzeria AS pz ON pz.id = pv.pizzeria_id
	INNER JOIN menu ON menu.pizzeria_id = pz.id
WHERE price < 800 AND person.name = 'Dmitriy' AND pv.visit_date = '2022-01-08'