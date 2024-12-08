INSERT INTO person_order(id, person_id, menu_id, order_date)
SELECT 
	g+(SELECT MAX(id) FROM person_order) AS id,
	id AS person_id, 
	(SELECT id from menu WHERE pizza_name = 'greek pizza') AS menu_id,
	'2022-02-25' AS order_date
FROM person INNER JOIN 
generate_series(1, (SELECT COUNT(*) FROM person)) AS g on g = person.id