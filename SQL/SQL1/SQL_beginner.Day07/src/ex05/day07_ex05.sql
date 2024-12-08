SELECT DISTINCT person.name
FROM person
	INNER JOIN person_order AS po ON person.id = po.person_id
ORDER BY 1