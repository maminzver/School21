COMMENT ON TABLE person_discounts IS 'This table of discounts for persons';
COMMENT ON COLUMN person_discounts.id IS 'Primary key';
COMMENT ON COLUMN person_discounts.person_id IS 'foreign key, person identifier';
COMMENT ON COLUMN person_discounts.pizzeria_id IS 'Foreign key, pizzeria identifier';
COMMENT ON COLUMN person_discounts.discount IS 'Discount for each person in each pizzeria';
