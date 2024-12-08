select a.action_date, name as person_name
	from person
join (SELECT order_date as action_date,
 person_id FROM person_order
INTERSECT
SELECT visit_date as action_date,
 person_id FROM person_visits) as a
on a.person_id = person.id

ORDER BY action_date ASC, name DESC