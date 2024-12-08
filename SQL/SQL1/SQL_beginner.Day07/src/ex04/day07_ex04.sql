SELECT person.name, COUNT(*) AS count_of_visits
FROM person
	INNER JOIN person_visits AS pv ON person.id = pv.person_id
GROUP BY person.name
HAVING COUNT(*) > 3