SELECT p1.name AS person_name1, p2.name AS person_name2, p1.address AS common_address 
FROM person AS p1
	INNER JOIN person AS p2 on p1.id > p2.id AND p1.address = p2.address
