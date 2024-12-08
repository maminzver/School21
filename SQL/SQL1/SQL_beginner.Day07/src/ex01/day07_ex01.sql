SELECT person.name, COUNT(*) AS count_of_visits
FROM person_visits AS pv
	INNER JOIN person ON pv.person_id = person.id
GROUP BY person.name
ORDER BY 2 desc, 1
LIMIT 4
