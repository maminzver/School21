INSERT INTO person_order(id, person_id, menu_id, order_date) VALUES
((SELECT MAX(id) + 1 FROM person_order), (SELECT id FROM person WHERE name = 'Denis'), (select id FROM menu WHERE pizza_name = 'sicilian pizza'), '2022-02-24');

INSERT INTO person_order(id, person_id, menu_id, order_date) VALUES
((SELECT MAX(id) + 1 FROM person_order), (SELECT id FROM person WHERE name = 'Irina'), (select id FROM menu WHERE pizza_name = 'sicilian pizza'), '2022-02-24')
