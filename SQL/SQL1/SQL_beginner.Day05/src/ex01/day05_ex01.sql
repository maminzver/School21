SET enable_seqscan = OFF;
EXPLAIN ANALYSE
SELECT menu.pizza_name AS pizza_name, pz.name AS pizzeria_name
FROM menu 
	INNER JOIN pizzeria AS pz ON menu.pizzeria_id = pz.id